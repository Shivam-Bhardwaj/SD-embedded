#define LEFT
//#define RIGHT
#ifdef LEFT
#define angle -127
#endif
#ifdef RIGHT
#define angle 127
#endif

#include <SoftwareSerial.h>
#include <Sabertooth.h>


SoftwareSerial SWSerial(NOT_A_PIN, 10); // RX on no pin (unused), TX on pin 11 (to S1).
Sabertooth ST(128, SWSerial); // Address 128, and use SWSerial as the serial port.

void setup()
{
  // put your setup code here, to run once:
  SWSerial.begin(9600);
  ST.autobaud();
  Serial.begin(9600);
  Serial.println("Test");
}


void loop()
{
    ST.motor(1, angle);
    while(1);
}
