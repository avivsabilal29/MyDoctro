
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>


#define HARDWARE_TYPE MD_MAX72XX::FC16_HW


#define PAUSE_TIME    1000
#define SCROLL_SPEED  50
#define MAX_DEVICES 4
#define CS_PIN 10

//#define CLK_PIN   13
//#define DATA_PIN  11

MD_Parola led = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
const char *pesan[] =
            {
              "Info",
              "Tenik",
              "Subscribe",
              
            };

void setup() {
 
  led.begin();

 
  led.setIntensity(1);


  led.displayClear();

  
}

void loop() {
   static uint8_t info = 0;
  int ran = random(4);
  if (led.displayAnimate()) {
    
    switch(ran){
        case 1:
        led.displayText(pesan[0], PA_CENTER, SCROLL_SPEED, PAUSE_TIME, PA_PRINT, PA_NO_EFFECT);    
          
      //  info = (info + 1) % ARRAY_SIZE(pesan);
         //delay(1000);
        break;
        case 2:      
       led.displayText(pesan[1], PA_CENTER, SCROLL_SPEED, PAUSE_TIME, PA_PRINT, PA_NO_EFFECT); 
            //led.displayScroll("Subscribe", PA_CENTER, PA_SCROLL_LEFT, 100);  
            delay(1000);
        break;
        case 3:
        // led.displayText(pesan[2], PA_CENTER, SCROLL_SPEED, PAUSE_TIME, PA_PRINT, PA_NO_EFFECT); 
            led.displayScroll("Subscribe", PA_CENTER, PA_SCROLL_LEFT, 100);
            //led.displayText('20:15:00', PA_CENTER, 0, 0, PA_PRINT,PA_NO_EFFECT);
           // delay(1000);
        break;    
      
        
    }  
    led.displayReset(); 
  }
}
