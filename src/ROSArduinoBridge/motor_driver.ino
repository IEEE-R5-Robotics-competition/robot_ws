#define USE_BASE
#define LEFT 0 
#define RIGHT 1

// Include the Adafruit Motor Shield V2 library
#include <Adafruit_MotorShield.h>

// Create the motor shield object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Create motor objects for left and right motors
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);  // M1 on the shield
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4); // M2 on the shield

// Initialize the motor controller
void initMotorController() {
  AFMS.begin();  // Initialize the motor shield
}

// Set speed for an individual motor
void setMotorSpeed(int i, int spd) {
  // Serial.print("Setting motor ");
  // Serial.print(i == LEFT ? "LEFT" : "RIGHT");
  // Serial.print(" speed to ");
  // Serial.println(spd);

  if (spd > 255) spd = 255;
  if (spd < -255) spd = -255;

  if (i == LEFT) {
    if (spd > 0) {
      leftMotor->run(FORWARD);
      leftMotor->setSpeed(spd);
    } else if (spd < 0) {
      leftMotor->run(BACKWARD);
      leftMotor->setSpeed(-spd);
    } else {
      leftMotor->run(RELEASE);
    }
  } else if (i == RIGHT) {
    if (spd > 0) {
      rightMotor->run(FORWARD);
      rightMotor->setSpeed(spd);
    } else if (spd < 0) {
      rightMotor->run(BACKWARD);
      rightMotor->setSpeed(-spd);
    } else {
      rightMotor->run(RELEASE);
    }
  }
}

// Set speed for both motors
void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  // Serial.print("Setting motors: LEFT=");
  // Serial.print(leftSpeed);
  // Serial.print(", RIGHT=");
  // Serial.println(rightSpeed);

  setMotorSpeed(LEFT, leftSpeed);
  setMotorSpeed(RIGHT, rightSpeed);
}