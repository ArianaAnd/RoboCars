#include <NewPing.h>
#include <SoftwareSerial.h> 
#include <Servo.h>
#include <LiquidCrystal.h>

#define int1 5
#define int2 4
#define int3 3
#define int4 2
const int trigPin = 9;
const int echoPin = 10;



#define SPEED 255 //160-255

SoftwareSerial sonar_serial(6,7); //RX, TX


#define TRIGGER_PIN 8
#define ECHO_PIN 7
#define MAX_DISTANCE 200//MMaximum distanta masurata
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


Servo servo;

void setup() {
  pinMode(int1, OUTPUT);
  pinMode(int2, OUTPUT);
  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);
  sonar_serial.begin(9600);
  servo.attach(11);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
/*  unsigned int uS = sonar.ping();
  int val = uS / US_ROUNDTRIP_CM; //Convertor distanta in cm
  if((val > 1) && (val<20)){
    delay(100);
    recover();
  }
  else{
    int command = sonar_serial.read();
    if(command != -1){
      switch (command){
        case 'F':forward(); break;
        case 'B':back(); break;
        case 'L':left(); break;
        case 'R':right(); break;
        case 'K':stop(); break;
        
      }
      delay(10);
    }
  }*/
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 

 


  servo.write(45);
  delay(1000);
  servo.write(90);
  delay(1000);
    servo.write(180);
  delay(1000);
    servo.write(60);
  delay(1000);
    servo.write(90);
  delay(1000);
    servo.write(45);
  delay(1000);

  
  forward();
  delay(5000);


  forward();
  delay(5000);
  stop();
  delay(5000);

  back();
  delay(1000);
  stop();
  delay(2000);
   left();
  delay(100);
  stop();
  delay(200);


  right();
  delay(100);
  stop();
  delay(500);

  
left();
delay(5000);
stop();







  
}




 
  


void recover(){
  back();
  delay(800);
  left();
  delay(500);
  forward();
}

void forward(){
  stop();
  analogWrite(int1, SPEED);
  analogWrite(int3, SPEED);
}

void back(){
  stop();
  analogWrite(int2, SPEED);
  analogWrite(int4, SPEED);
}

void left(){
  stop();
  analogWrite(int3, SPEED);
  analogWrite(int2, SPEED);
  
  }
  void right(){
    
    analogWrite(int4, SPEED);
    analogWrite(int1, SPEED);
}


void stop()
{
  analogWrite(int1, 0);
  analogWrite(int2, 0);
  analogWrite(int3, 0);
  analogWrite(int4, 0);
}
