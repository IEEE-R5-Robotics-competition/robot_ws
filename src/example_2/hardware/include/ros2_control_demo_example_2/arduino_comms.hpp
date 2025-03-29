#ifndef DIFFDRIVE_ARDUINO_ARDUINO_COMMS_HPP
#define DIFFDRIVE_ARDUINO_ARDUINO_COMMS_HPP

#include <sstream>
#include <libserial/SerialPort.h>
#include <iostream>

LibSerial::BaudRate convert_baud_rate(int baud_rate)
{
    switch (baud_rate)
    {
        case 1200:  return LibSerial::BaudRate::BAUD_1200;
        case 1800:  return LibSerial::BaudRate::BAUD_1800;
        case 2400:  return LibSerial::BaudRate::BAUD_2400;
        case 4800:  return LibSerial::BaudRate::BAUD_4800;
        case 9600:  return LibSerial::BaudRate::BAUD_9600;
        case 19200: return LibSerial::BaudRate::BAUD_19200;
        case 38400: return LibSerial::BaudRate::BAUD_38400;
        case 57600: return LibSerial::BaudRate::BAUD_57600;
        case 115200:return LibSerial::BaudRate::BAUD_115200;
        case 230400:return LibSerial::BaudRate::BAUD_230400;
        case 460800:return LibSerial::BaudRate::BAUD_460800;
        default:
            std::cout << "Error! Baud Rate " << baud_rate << " not supported! Default to 57600" << std::endl;}
            return LibSerial::BaudRate::BAUD_57600;
}

class ArduinoComms
{


public:

  ArduinoComms() = default;

  void connect(const std::string &serial_device, int32_t baud_rate, int32_t timeout_ms)
  {
    timeout_ms_ = timeout_ms;
    serial_conn_.Open(serial_device);
    serial_conn_.SetBaudRate(convert_baud_rate(baud_rate));
	
  }

  void disconnect()
  {
    serial_conn_.Close();
  }

  bool connected() const { return serial_conn_.IsOpen(); }
  
  std::string sendMsg(const std::string &msg_to_send, bool print_output = false)
	{
	if (!connected())
	{
		std::cerr << "Error: Serial port not connected!" << std::endl;
		return "";
	}
	
	serial_conn_.FlushIOBuffers();
	serial_conn_.Write(msg_to_send);
	
	std::string response = "";
	
	// Skip response wait for motor commands which don't reply
	if (!(msg_to_send.length() >= 2 && msg_to_send.substr(0, 2) == "m ")) {
		try
		{
		// Read until newline, but also handle the carriage return
		serial_conn_.ReadLine(response, '\n', timeout_ms_);
		// Strip the carriage return if present
		if (!response.empty() && response.back() == '\r') {
			response.pop_back();
		}
		}
		catch(LibSerial::ReadTimeout&)
		{
		std::cerr << "The ReadByte() call has timed out." << '\n' << std::endl;
		}
	}
	
	if(print_output)
	{
		std::cout << "Sent: " << msg_to_send << std::endl;
		std::cout << "Received: " << response << std::endl;
	}
	
	return response;
	}

  void send_empty_msg()
  {
    std::string response = sendMsg("\r");
  }

  void read_encoder_values(int &val_1, int &val_2)
  {
    std::string response = sendMsg("e\r");

    if(response.empty())
    {
      	std::cerr << "encoder values are empty" << '\n' << std::endl;
        return;
    }

    std::string delimeter = " ";
    size_t del_pos = response.find(delimeter);

    if(del_pos == std::string::npos)
    {
        std::cerr << "wrong encoder parameters recieved" << '\n' << std::endl;
		// Optionally return a safe default or skip this read cycle.
        return;
    }

    // std::string token_1 = response.substr(0, del_pos);
    std::string token_1 = response.substr(del_pos + 1, response.length() - del_pos);
    std::string token_2 = response.substr(del_pos + 1, response.length() - del_pos);
    
    if (token_1.empty() || token_2.empty()) {
        std::cerr << "encoder tokens are empty" << token_1.c_str() << "\n" << token_2.c_str() << std::endl;
        // Optionally return a safe default or skip this read cycle.
        return;
      }
      
    try {
        val_1 = std::stoi(token_1);
        val_2 = std::stoi(token_2);
    } 
    catch (const std::invalid_argument&) {
      	// Handle invalid argument error
      	std::cerr << "Received invalid encoder data: " << token_1.c_str() << "  " << token_2.c_str() << "\n" << std::endl;
    } 
    catch (const std::out_of_range&) {
      	// Handle out of range error
      	std::cerr << "Received out of range encoder data: " << token_1.c_str() << "  " << token_2.c_str() << "\n" << std::endl;
    }
  }

  void set_motor_values(int val_1, int val_2)
  {
    std::stringstream ss;
    ss << "m " << val_1 << " " << val_2 << "\r";
    sendMsg(ss.str());
  }

  void set_pid_values(float k_p, float k_d, float k_i, float k_o)
  {
    std::stringstream ss;
    ss << "u " << k_p << ":" << k_d << ":" << k_i << ":" << k_o << "\r";
    sendMsg(ss.str());
  }

private:
  LibSerial::SerialPort serial_conn_;
  int32_t timeout_ms_;
};

#endif // DIFFDRIVE_ARDUINO_ARDUINO_COMMS_CPP