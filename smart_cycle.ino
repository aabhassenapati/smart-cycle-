//this is code written by Aaabhas Senapati along with Adityaraj Mohta for making the project smart cycle


const int trigPin = 9;
const int echoPin = 10;
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;   
long duration;
int distance2;

//obstacle and buzzer and horn based on speed
#include <Wire.h> //Include Wire library
#include <LiquidCrystal_I2C.h>//Include the previous downloaded
//LiquidCrystal_I2C library
LiquidCrystal_I2C lcd(0x27, 16, 2); //Here we are going to define what kind of
//display we are using. In this case it is one with 16 signs and 2 rows.
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//#include <LiquidCrystal.h>
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  lcd.begin();
  pinMode(53, INPUT);
  pinMode(15, OUTPUT);
  pinMode(16, INPUT);
  //pinMode(12, INPUT);
  pinMode(17, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);

  pinMode(51, OUTPUT);

  pinMode(13, OUTPUT);
  pinMode(49, OUTPUT);
  digitalWrite(49, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(51, LOW);
  digitalWrite(15, LOW);
  // Provide ground and power by using the analog inputs as normal digital pins.
  // This makes it possible to directly connect the breakout board to the
  // Arduino. If you use the normal 5V and GND pins on the Arduino,
  // you can remove these lines.


}
int c=0;
int b = 0;
int count = 0;
int count3 = 0 ;
int num = 0;
int d=0;
int e = 0;
double timer = 0;
double circumference = 2.2;
double speed_cycle;
void loop() {
  // print the sensor values:
  // Serial.print(analogRead(xpin));
  // print a tab between values:
  //Serial.print("\t");
  //Serial.print(analogRead(ypin));
  // print a tab between values:
  //  Serial.print("\t");
  //Serial.print(analogRead(zpin));
  //Serial.println();*/
  // delay before next reading:
  //delay(2000);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance2= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance2);
int aabhas = digitalRead(53);
  Serial.println(aabhas);
  if (aabhas == 1)
  { //count2++;
    num = count3;
  }

  if (digitalRead(12) == HIGH)
  { Serial.println("lock open");

  }

  if (digitalRead(12) == LOW)
  {
    Serial.println("lock close");
  }
  if (digitalRead(16) == HIGH)
  {
    digitalWrite(13, HIGH);
  }
  if (digitalRead(16) == LOW)
  {
    digitalWrite(13, LOW);
  }
  if ((aabhas == 0) && (count3 == num + 1)  )
  {
   // timer = millis()/1000 - b;
 c=millis();
timer = c-b;
    b=c;
    count++;

    //count2 = 0;
  }
  int distance = (circumference) * count;
 
     
  if(count/2==0) {
     
    d = millis();
    }
   if((count/2) ==1)
    {
      e=millis();
      }
 
  Serial.println(speed_cycle);
  Serial.println(millis() / 1000);
 
  
  
  Serial.println(distance);
  Serial.println(analogRead(xpin));
Serial.println(analogRead(ypin));
Serial.println(analogRead(zpin));

  lcd.setCursor(0, 0); //At the loop part the I²C LCD is programed just like the

lcd.print("speed:");
lcd.print(1000*3.6*(circumference/timer));


  //lcd.print("x=");
  //lcd.print(analogRead(xpin));
 // lcd.print(" y=");
  //lcd.print(analogRead(ypin));

  lcd.setCursor(0, 1); // lcd.setCursor to define sign and row where the text
 lcd.print("distance:");
lcd.print(distance);
  //should start
  //lcd.print("z=");
 // lcd.print(analogRead(zpin));
//  lcd.print(" Gyroscope");

  count3++;
}
