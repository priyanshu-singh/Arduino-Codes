
#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define TRIGGER_PIN2 8
#define ECHO_PIN2 9
#define USONIC_DIV 58.0
#define MEASURE_SAMPLE_DELAY 5
#define MEASURE_SAMPLES 25
#define MEASURE_DELAY 250
void setup()
{
   // Serial monitoring
   Serial.begin(9600);

   // Initializing Trigger Output and Echo Input
   pinMode(TRIGGER_PIN, OUTPUT);
   pinMode(ECHO_PIN, INPUT);

   pinMode(TRIGGER_PIN2, OUTPUT);
   pinMode(ECHO_PIN2, INPUT);
   

   // Reset the trigger pin and wait a half a second
   digitalWrite(TRIGGER_PIN, LOW);
   digitalWrite(TRIGGER_PIN2, LOW);
   delayMicroseconds(1000);
}void loop()
{
  delay(MEASURE_DELAY);
  long distance = measure();
  Serial.print("Distance: \t");
  Serial.print(distance-331);
  Serial.print(" mm ");
  long distance2 = measure2();
  Serial.print("lower: \t");
  Serial.print(distance2-139);
  Serial.println(" mm");
}
long measure()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += singleMeasurement();
  }
  return measureSum / MEASURE_SAMPLES;
}
long singleMeasurement()
{
  long duration = 0;
  // Measure: Put up Trigger...
  digitalWrite(TRIGGER_PIN, HIGH);
  // ... wait for 11 µs ...
  delayMicroseconds(11);
  // ... put the trigger down ...
  digitalWrite(TRIGGER_PIN, LOW);
  // ... and wait for the echo ...
  duration = pulseIn(ECHO_PIN, HIGH);
  return (long) (((float) duration / USONIC_DIV) * 10.0);
} 
long measure2()
{
  long measureSum2 = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum2 += singleMeasurement2();
  }
  return measureSum2 / MEASURE_SAMPLES;
}
long singleMeasurement2()
{
  long duration2 = 0;
  // Measure: Put up Trigger...
  digitalWrite(TRIGGER_PIN2, HIGH);
  // ... wait for 11 µs ...
  delayMicroseconds(11);
  // ... put the trigger down ...
  digitalWrite(TRIGGER_PIN2, LOW);
  // ... and wait for the echo ...
  duration2 = pulseIn(ECHO_PIN2, HIGH);
  return (long) (((float) duration2 / USONIC_DIV) * 10.0);
} 
