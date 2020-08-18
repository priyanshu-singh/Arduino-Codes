#include <Wire.h>
#include "Adafruit_MPR121.h"
#include <LiquidCrystal.h>

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif
unsigned long prevmillis2; // To store time
unsigned long duration2; // To store time difference
unsigned long lcdrefresh2; // To store time for lcd to refresh

char ch;
int Contrast=130;
int backLight = 9;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd2(28, 29, 30, 31, 32, 33);

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {
  Serial.begin(9600);

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
  
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");

  
  pinMode(13,OUTPUT);
  analogWrite(3,Contrast);
  // set up the LCD's number of columns and rows: 
  lcd2.begin(16, 2);
  // Print a message to the LCD.
  Serial.print("fuel level:");
   pinMode(backLight, HIGH);
digitalWrite(backLight, HIGH);
 
}

void loop() {
  // Get the currently touched pads
  digitalWrite(13,LOW);
   delay(1000);
   digitalWrite(13,HIGH);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd2.setCursor(0, 1);
  currtouched = cap.touched();
  
 

  // reset our state
  lasttouched = currtouched;

  // comment out this line for detailed data from the sensor!
  
  
  // debugging info, what
  Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
  Serial.print("Filt: ");
  for (uint8_t i=0; i<2; i++) {
    Serial.print(cap.filteredData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("Base: ");
  for (uint8_t i=0; i<2; i++) {
  Serial.print(cap.baselineData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
   if( ( millis()-lcdrefresh2 ) >= 100 )
    {
  lcd2.print("\t");
 if(cap.baselineData(2)<180) {
   lcd2.print("100% water"); Serial.print("\t");
  
 }
   if(cap.baselineData(0)<183) {
    lcd2.print("50% water"); Serial.print("\t");
  }

   else if(cap.baselineData(1)<183) {
    lcd2.print("almost empty"); Serial.print("\t");
  }}
 
  Serial.println();
  
  // put a delay so it isn't overwhelming
 
}
