//1st-pin 7 &8
int trigPin1=13; //Sensor Trip pin connected to Arduino pin 13
int echoPin1=11;  //Sensor Echo pin connected to Arduino pin 11
int myCounter1=0;  //declare your variable myCounter and set to 0
float pingTime1;  //time for ping to travel from sensor to target and return
float targetDistance1; //Distance to Target in inches
float speedOfSound=776.5; //Speed of sound in miles per hour when temp is 77 degrees.
float tm1;

int trigPin2=7; //Sensor Trip pin connected to Arduino pin 13
int echoPin2=6;  //Sensor Echo pin connected to Arduino pin 11  //declare your variable myCounter and set to 0
float pingTime2;  //time for ping to travel from sensor to target and return
float targetDistance2; //Distance to Target in inches
float tm2;
void setup() {
  
Serial.begin(9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
 
}
 
void loop() {
  
  digitalWrite(trigPin1, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin1, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin1, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in high state
  
  pingTime1 = pulseIn(echoPin1, HIGH);  //pingTime is presented in microceconds
  pingTime1=pingTime1/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime1=pingTime1/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  targetDistance1= speedOfSound * pingTime1;  //This will be in miles, since speed of sound was miles per hour
  targetDistance1=targetDistance1/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  targetDistance1= targetDistance1*63360;    //Convert miles to inches by multipling by 63360 (inches per mile)
  if(targetDistance1<200)
  {
   tm1= millis();
   //Serial.print("  ");
  //Serial.print(tm1);
  }
  digitalWrite(trigPin2, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin2, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin2, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in high state
  
  pingTime2 = pulseIn(echoPin2, HIGH);  //pingTime is presented in microceconds
  pingTime2=pingTime2/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime2=pingTime2/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  targetDistance2= speedOfSound * pingTime2;  //This will be in miles, since speed of sound was miles per hour
  targetDistance2=targetDistance2/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  targetDistance2= targetDistance2*63360;    //Convert miles to inches by multipling by 63360 (inches per mile)

  
  if(targetDistance2<200){
   tm2= millis();
   //Serial.print("  ");
  //Serial.print(tm2);
  }
  float tm3=tm1-tm2+0.16;
  float aacn=30/(sqrt(tm3))
  Serial.println(tm3/1000);
  delay(00);
}  
