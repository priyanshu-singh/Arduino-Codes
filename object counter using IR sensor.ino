int pirpin=2;
int counter=0;
int hitObject=false;
//int laststate=HIGH;
void setup(){
  Serial.begin(9600);
  pinMode(pirpin,INPUT);
}
void loop(){
  int val=digitalRead(pirpin);
  if((val==0)&&(hitObject==false)){
    counter++;
    hitObject=true;
    Serial.print("Counter= ");
    Serial.println(counter);
  }
  else if((val==1)&&(hitObject==true)){
    hitObject=false;
  }
}
