#include <LiquidCrystal.h>
#define ADC_ref 5 // ADC reference Voltage
#define zero_x 1.799
#define zero_y 1.799
#define zero_z 1.799
#define echoPin 8
#define trigPin 9
#define selectSwitch 1
#define sensitivity_x 0.4
#define sensitivity_y 0.4
#define sensitivity_z 0.4
unsigned int value_x;
unsigned int value_y;
unsigned int value_z;
float xv;
float yv;
float zv;
float angle;
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
Serial.begin(9600);
analogReference(ADC_ref);
pinMode(selectSwitch,INPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
lcd.clear();
lcd.begin(16,2);
lcd.print("Tilt & Distance");
lcd.setCursor(0,2);
lcd.print(" Measurement ");
delay(5;;3300);

}
void loop()
{
int distance,duration;
value_x = analogRead(A0);
value_y = analogRead(A1);
value_z = analogRead(A2);
xv=(value_x/1024.0*ADC_ref-zero_x)/sensitivity_x;
yv=(value_y/1024.0*ADC_ref-zero_y)/sensitivity_y;
zv=(value_z/1024.0*ADC_ref-zero_z)/sensitivity_z;
angle =atan2(-yv,-zv)*57.2957795+180;
if(digitalRead(selectSwitch)==HIGH)
{
lcd.setCursor(0,0);
Serial.print("angle: ");
Serial.println(angle);
lcd.print("Tilt: ");
lcd.print(angle);
lcd.print(" deg");
digitalWrite(trigPin, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance >= 400 || distance <= 0)
{
lcd.setCursor(0,1);
lcd.print("Out of Range");
}
else
{
lcd.setCursor(0,1);
lcd.print("Distance: ");
lcd.print(distance);
lcd.print(" cm ");
}
delay(1000);
lcd.clear();
}
else
{
lcd.setCursor(0,0);
lcd.print("X=");
lcd.print(xv);
lcd.print(" Y=");
lcd.print(yv);
lcd.setCursor(0,1);
lcd.print(" Z= ");
lcd.print(zv);
delay(1000);
}
}
