#include <Servo.h>  // add servo library

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
Servo myservo2;  // create servo object to control a servo

int potpin2 = 1;  // analog pin used to connect the potentiometer
int val2;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1025, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo2.write(val2);
  delay(15);                           // waits for the servo to get there
}
