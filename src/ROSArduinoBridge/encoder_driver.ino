/* *************************************************************
   Encoder definitions
   ************************************************************ */
   
#ifdef USE_BASE  // REMOVED THE COMMENT HERE

#ifdef ROBOGAIA
  /* The Robogaia Mega Encoder shield */
  #include "MegaEncoderCounter.h"

  /* Create the encoder shield object */
  MegaEncoderCounter encoders = MegaEncoderCounter(4); // Initializes the Mega Encoder Counter in the 4X Count mode
  
  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return encoders.YAxisGetCount();
    else return encoders.XAxisGetCount();
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT) return encoders.YAxisReset();
    else return encoders.XAxisReset();
  }
#elif defined(ARDUINO_ENC_COUNTER)
  volatile long left_enc_pos = 0L;
  volatile long right_enc_pos = 0L;
  static const int8_t ENC_STATES [] = {0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0};  //encoder lookup table
    
  /* Interrupt routine for LEFT encoder */
  ISR (PCINT2_vect){
    static uint8_t enc_last=0;
    enc_last <<=2; 
    enc_last |= (PIND & (3 << 2)) >> 2; 
    left_enc_pos += ENC_STATES[(enc_last & 0x0f)];
  }
  
  /* Interrupt routine for RIGHT encoder */
  ISR (PCINT1_vect){
    static uint8_t enc_last=0;
    enc_last <<=2; 
    enc_last |= (PINC & (3 << 4)) >> 4; 
    right_enc_pos += ENC_STATES[(enc_last & 0x0f)];
  }
  
  long readEncoder(int i) {
    if (i == LEFT) return left_enc_pos;
    else return right_enc_pos;
  }

  void resetEncoder(int i) {
    if (i == LEFT) left_enc_pos = 0L;
    else right_enc_pos = 0L;
  }
#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif  // REMOVED THE COMMENT HERE