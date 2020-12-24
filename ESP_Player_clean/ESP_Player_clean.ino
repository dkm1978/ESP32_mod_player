
#include "hxcmod.h"
#include "enigma.h"
//#include "atari.h"




#define DAC1 25
#define DAC2 26

volatile  uint16_t buff[2] ;




modcontext mcontext;
void* tune=(void*) &big;
hw_timer_t * timer = NULL;


void IRAM_ATTR onTimer() {
  
      hxcmod_fillbuffer(&mcontext,(msample*) &buff,1,0 );
      dacWrite(DAC1,buff[0]);
    
}


void setup() {
  
  
  hxcmod_init( &mcontext );
  hxcmod_setcfg( &mcontext, 44100, 1, 0);
  hxcmod_load( &mcontext,tune, sizeof(big) );
  timer = timerBegin(0, 5, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 363, true);
  timerAlarmEnable(timer);
  
 
  
}


void loop() {
      
  
                    
}
