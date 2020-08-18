int hallsensor = 2;                // Hall sensor at pin 2

volatile byte counter;

unsigned int rpm2;

unsigned long passedtime;

const int dataIN = 3; //IR sensor INPUT

unsigned long prevmillis; // To store time
unsigned long duration; // To store time difference
unsigned long timeold;
unsigned long refresh;

int rpm;// RPM value
int v;
boolean currentstate; // Current state of IR input scan
boolean prevstate; 

void isr()

 {

   //Each rotation, this interrupt function is run twice, so take that into consideration for

   //calculating RPM

   //Update count

      counter++;

 }
void setup()

 {Serial.begin(9600);

   //Intiates Serial communications
   pinMode(dataIN,INPUT);    
  prevmillis = 0;
  prevstate = LOW;
  timeold = 0;

   attachInterrupt(0, isr, RISING); //Interrupts are called on Rise of Input

   pinMode(hallsensor, INPUT); //Sets hallsensor as input

   counter = 0;

   rpm = 0;

   passedtime = 0; //Initialise the values

 }
 void loop()
 {
   delay(500);//Update RPM every second

   detachInterrupt(0); //Interrupts are disabled

   rpm2 = 60*100/(millis() - passedtime)*counter;

   passedtime = millis();

   counter = 0;

   Serial.print("RPM=");

   Serial.println(rpm2); //Print out result to monitor

   attachInterrupt(0, isr, RISING);   //Restart the interrupt processing
   

  }
