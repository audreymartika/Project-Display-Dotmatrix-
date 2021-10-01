/*
  Scrolling alphabet demo, displays characters one at a time into a scrolling box.
*/

#include <SPI.h>
#include <DMD2.h>
#include <TimerOne.h>
#include <fonts/SystemFont5x7.h>
#include <fonts/Arial14.h>
#include <fonts/Droid_Sans_12.h>

int a;
char data;
// Set Width to the number of displays wide you have
//const int WIDTH = 1;

// You can change to a smaller font (two lines) by commenting this line,
// and uncommenting the line after it:
//const uint8_t *FONT = Arial14;
//const uint8_t *FONT = SystemFont5x7;
const uint8_t *FONT = Droid_Sans_12;

SoftDMD dmd(3, 2, 49, 46, 47, 48, 51, 52);

void Interrupt()
{
  dmd.scanDisplay();
}
  // "box" provides a text box to automatically write to/scroll the display
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  data = Serial.read();
  dmd.setBrightness(255);
  dmd.selectFont(FONT);
  dmd.begin();
  Timer1.initialize(10000);
  Timer1.attachInterrupt(Interrupt);
   
  // Set a single LED on or off
  //void setPixel(unsigned int x, unsigned int y, DMDGraphicsMode mode=GRAPHICS_ON);

  // Get status of a single LED
  // bool getPixel(unsigned int x, unsigned int y);

}
void count() {
  if (a == 5) {
    DMD_TextBox box(dmd,32,20);
    box.print("WAIT!");
 //   delay(100000);
    box.clear();
  }
  else {
    DMD_TextBox box(dmd,15,20);
    box.print("WELCOME");
 //   delay(100000);
    box.clear();
  }
}

// the loop routine runs over and over again forever:
void loop() {
 dmd.drawString(2, 4, "RUANG KAPRODI");
 // delay(100000);
  while(Serial.available()){
  if(data = 'b'){
    for(a=0;a<=5;a++){
      count();
      Serial.print(a);
 //     delay(100000);
    }
  }
  }
 
}
