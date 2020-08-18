
int Xread;
int Xrest;

int Yread;
int Yrest;

int Zread;
int Zrest;

double Gx;
double Gy;
double Gz;

int xpin = 0;
int ypin = 1;
int zpin = 2;

int t1;

int Xread2;
int Xrest2;

int Yread2;
int Yrest2;

int Zread2;
int Zrest2;

double Gx2;
double Gy2;
double Gz2;

int xpin2 = 3;
int ypin2 = 4;
int zpin2 = 5;

int t2;
void setup()
{
Serial.begin(9600);

digitalWrite(13,HIGH);

Xrest=analogRead(xpin);
Serial.print(Xrest);
Yrest=analogRead(ypin);
Serial.print(Yrest);
Zrest=analogRead(zpin);
Serial.print(Zrest);

Xrest2=analogRead(xpin2);
Serial.print(Xrest2);
Yrest2=analogRead(ypin2);
Serial.print(Yrest2);
Zrest2=analogRead(zpin2);
Serial.print(Zrest2);
digitalWrite(13,LOW);
}
void loop()
{
Serial.print("Time ");
t1=millis();
Serial.print(t1*0.001);

Xread = analogRead(xpin)-Xrest;
Yread=analogRead(ypin)-Yrest;
Zread=analogRead(zpin)-Zrest;

Xread2 = analogRead(xpin2)-Xrest2;
Yread2=analogRead(ypin2)-Yrest2;
Zread2=analogRead(zpin2)-Zrest2;

Gx=Xread/67.584;
Gy=Yread/67.584;
Gz=Zread/67.584;

Gx2=Xread2/67.584;
Gy2=Yread2/67.584;
Gz2=Zread2/67.584;
Serial.print("  \t");
Serial.print(Gx);
Serial.print("  \t");
Serial.print(Gy);
Serial.print("  \t");
Serial.print(Gz);
Serial.println("  \t");

Serial.print("  \t");
Serial.print(Gx2);
Serial.print("  \t");
Serial.print(Gy2);
Serial.print("  \t");
Serial.print(Gz2);
Serial.println("\n");
delay(500);

}
