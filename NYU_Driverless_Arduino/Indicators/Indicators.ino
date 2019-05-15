#include "Indicators.h"

#define Right_Indicator_Pin (4)
#define Left_Indicator_Pin  (3)
#define Brake_Light_Pin     (5)
#define Head_Light_Pin      (2)
#define Front_Light_Pin     (6)
#define Autonomous_Mode_Pin (8)
#define Circuit_Breaker_Pin (7)

Indicator_Status stat;
bool left_blink_state = false;
bool right_blink_state = false;
long left_previous_time=-500;
long right_previous_time=-500;

void setup(){
  Serial.begin(9600);
  pinMode(Right_Indicator_Pin,OUTPUT);
  pinMode(Left_Indicator_Pin,OUTPUT);
  pinMode(Brake_Light_Pin,OUTPUT);
  pinMode(Head_Light_Pin,OUTPUT);
  pinMode(Front_Light_Pin,OUTPUT);
  pinMode(Autonomous_Mode_Pin,OUTPUT);
  pinMode(Circuit_Breaker_Pin,OUTPUT);
  Serial.println("Initialization complete...");
}
uint8_t data;

void loop(){
  if(Serial.available()){
    data = Serial.read();
    update_status(data,&stat);
  }
  if(stat.Right_Indicator){
      if(millis() - right_previous_time >= 500){
          if(right_blink_state){
            digitalWrite(Right_Indicator_Pin,HIGH);
            right_blink_state=false;
          }
          else{
            digitalWrite(Right_Indicator_Pin,LOW);
            right_blink_state=true;
          }
          right_previous_time = millis();
      }
  }
  else{
      digitalWrite(Right_Indicator_Pin,HIGH);
      right_blink_state=false;
  }
  if(stat.Left_Indicator){
      if(millis() - left_previous_time >= 500){
          if(left_blink_state){
            digitalWrite(Left_Indicator_Pin,HIGH);
            left_blink_state=false;
          }
          else{
            digitalWrite(Left_Indicator_Pin,LOW);
            left_blink_state=true;
          }

          left_previous_time = millis();
      }
  }
  else{
      digitalWrite(Left_Indicator_Pin,HIGH);
      left_blink_state=false;
  }

  if(stat.Brake_Light){
      digitalWrite(Brake_Light_Pin,LOW);
  }
  else 
      digitalWrite(Brake_Light_Pin,HIGH);

  
  if(stat.Head_Light){
      digitalWrite(Head_Light_Pin,LOW);
  }
  else 
      digitalWrite(Head_Light_Pin,HIGH);

  
  if(stat.Front_Light){
      digitalWrite(Front_Light_Pin,LOW);
  }
  else 
      digitalWrite(Front_Light_Pin,HIGH);
      
  if(stat.Autonomous_Mode){
      digitalWrite(Autonomous_Mode_Pin,LOW);
  }
  else 
      digitalWrite(Autonomous_Mode_Pin,HIGH);

  
  if(stat.Circuit_Breaker){
      digitalWrite(Circuit_Breaker_Pin,LOW);
  }
  else 
      digitalWrite(Circuit_Breaker_Pin,HIGH);


  delay(10);
}
