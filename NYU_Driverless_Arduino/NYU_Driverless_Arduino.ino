#include <SoftwareSerial.h>
#include <Sabertooth.h>

#define P_Const 4
#define LeftLimit 439
#define RightLimit 642


int STR_angle = 30;
int STR_Speed = 0;
int data=0;
bool error=false;

SoftwareSerial SWSerial(11, 10); // RX on no pin (unused), TX on pin 11 (to S1).
Sabertooth ST(128, SWSerial); // Address 128, and use SWSerial as the serial port.

int potentiometer;
int destination;
int rotatespeed;


void setup()
{
  // put your setup code here, to run once:
  SWSerial.begin(9600);
  ST.autobaud();
  pinMode(7, OUTPUT);
  digitalWrite(7,LOW);
  Serial.begin(9600);
  Serial.println("Test");
}

int getAngleSpeed(int s) {
  int angle = s;
  int data = analogRead(A0);
//  if(data<RightLimit || data>LeftLimit){
//    error=true;
//    return 0;
//  }
  potentiometer = map(data, LeftLimit, RightLimit, 60, 0);
  rotatespeed = constrain(P_Const * map(potentiometer - angle,-30,30, 127, -127), -127, 127);
  Serial.print(data);
  Serial.print(" ");
  Serial.print(potentiometer);
  Serial.print(" ");
  Serial.println(rotatespeed);
  return rotatespeed;

}

long timer;
int getLinearSpeed(int s) {
  int L_speed = s;
  if (L_speed < 0)
    return 50;
  return map(L_speed, 0, 4, 0, -127);
}

boolean flag = 0;

void loop()
{
  if (Serial.available() > 0) {
    flag=0;
    data = Serial.read();
    if(data>127)
      STR_angle=data-128;
    else
      STR_Speed=data-1;
    //ST.motor(1,127);
    
    ST.motor(2, getAngleSpeed(STR_angle));
    ST.motor(1, getLinearSpeed(STR_Speed));
  }
  else if (flag != 1) {
    flag = 1;
    timer = millis();
  }
  else if (millis() - timer >= 500) {
    STR_Speed = 0;
    STR_angle = 30;
    //ST.motor(1,0);
    ST.motor(2, getAngleSpeed(STR_angle));
    ST.motor(1, getLinearSpeed(STR_Speed));
  }

  if(error){
    digitalWrite(7,HIGH);
  }
  //Serial.print(data);
  //Serial.print(" ");
  //Serial.print(STR_angle);
  //Serial.print(" ");
  //Serial.println(STR_Speed);
  delay(10);
}
