#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);   //defining lcd pins

const int dataIN = 2; //IR sensor INPUT


unsigned long lcdrefresh; // To store time for lcd to refresh

int counter=0;
int hitObject=false;




void setup()
{
  Serial.begin(9600);
  pinMode(dataIN,INPUT);
  lcd.begin(16,2);     
   
}

void loop()
{
  int val=digitalRead(dataIN);
  if((val==0)&&(hitObject==false)){
    counter++;
    hitObject=true;
    Serial.print("Counter= ");
    Serial.println(counter);
  }
  else if((val==1)&&(hitObject==true)){
    hitObject=false;
  }
 
  
  // LCD Display
  if( ( millis()-lcdrefresh ) >= 100 )
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Distance Travelled");
      lcd.setCursor(0,1);
      lcd.print("Distance = ");
      lcd.print(counter*1.754);         
      lcdrefresh = millis();   
    }

}
