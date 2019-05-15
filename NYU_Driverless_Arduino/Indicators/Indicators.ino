#include "Indicators.h"

#define Right_Indicator_Pin (0)
#define Left_Indicator_Pin  (1)
#define Brake_Light_Pin     (2)
#define Head_Light_Pin      (3)
#define Front_Light_Pin     (4)
#define Autonomous_Mode_Pin (5)
#define Circuit_Breaker_Pin (6)

Indicator_Status stat;
bool blink_state = false;
long previous_time=-500;

void setup(){
  Serial.begin(9600);
  pinMode(Right_Indicator_Pin,OUTPUT);
  pinMode(Left_Indicator_Pin,OUTPUT);
  pinMode(Brake_Light_Pin,OUTPUT);
  pinMode(Head_Light_Pin,OUTPUT);
  pinMode(Front_Light_Pin,OUTPUT);
  pinMode(Autonomous_Mode_Pin,OUTPUT);
  pinMode(Circuit_Breaker_Pin,OUTPUT);
}
uint8_t data;

void loop(){
  if(Serial.available());
    data = Serial.read();
  update_status(data,&stat);
  if(!(stat.Right_Indicator || stat.Right_Indicator))
      blink_state=false;
  else if(stat.Right_Indicator){
      if(millis() - previous_time >= 500){
          if(blink_state)
            digitalWrite(Right_Indicator_Pin,LOW);
          else 
            digitalWrite(Right_Indicator_Pin,HIGH);

          previous_time = millis();
      }
  }
  else if(stat.Left_Indicator){
      if(millis() - previous_time >= 500){
          if(blink_state)
            digitalWrite(Left_Indicator_Pin,LOW);
          else 
            digitalWrite(Left_Indicator_Pin,HIGH);

          previous_time = millis();
      }
  }

  if(stat.Brake_Light){
      digitalWrite(Brake_Light_Pin,HIGH);
  }
  else 
      digitalWrite(Brake_Light_Pin,LOW);

  
  if(stat.Head_Light){
      digitalWrite(Head_Light_Pin,HIGH);
  }
  else 
      digitalWrite(Head_Light_Pin,LOW);

  
  if(stat.Front_Light){
      digitalWrite(Front_Light_Pin,HIGH);
  }
  else 
      digitalWrite(Front_Light_Pin,LOW);
      
  if(stat.Autonomous_Mode){
      digitalWrite(Autonomous_Mode_Pin,HIGH);
  }
  else 
      digitalWrite(Autonomous_Mode_Pin,LOW);

  
  if(stat.Circuit_Breaker){
      digitalWrite(Circuit_Breaker_Pin,HIGH);
  }
  else 
      digitalWrite(Circuit_Breaker_Pin,LOW);


  delay(10);
}
