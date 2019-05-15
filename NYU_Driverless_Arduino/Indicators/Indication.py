import time
import sys
import termios
import keyboard
import serial
import struct
import numpy as np
from xbee import XBee



def flush_input():
	import sys, termios
	termios.tcflush(sys.stdin, termios.TCIOFLUSH)

data=0

def toggle(string s){
    if s == "Right_Indicator"
        data = (data ^ 0x01)
    elif s == "Left_Indicator":
        data = (data ^ 0x02)
    elif s == "Brake_Light"
        data = (data ^ 0x04)
    elif s == "Head_Light":
        data = (data ^ 0x08)
    elif s == "Autonomous_Mode"
        data = (data ^ 0x10)
    elif s == "Circuit_Breaker":
        data = (data ^ 0x20)
}
	
def open_serialComm(port):
    # Enable USB communication
    serial_port = serial.Serial(port,9600)
    #xbee = XBee(serial_port)

    # Refresh the port to be used
    serial_port.close()
    serial_port.open()

    print('Serial communication established !!')
    return serial_port

bool change = false
bool push = false
print('\nEstablishing communication with Analyzer Bot....')
serial_port = open_serialComm('/dev/ttyUSB2')
while True:#making a loop
	#used try so that if user pressed other than the given key error will not be shown
 
	if keyboard.is_pressed('q') and not change:	#if key 'a' is pressed
		toggle("Right_Indicator")
        change = true
        push = true
	else:
		change = false
	if keyboard.is_pressed('w') and not change:
		toggle("Left_Indicator")
        change = true
        push = true
	else:
		change = false
	if keyboard.is_pressed('e') and not change:	#if key 'a' is pressed
		toggle("Brake_Light")
        change = true
        push = true
	else:
		change = false
	if keyboard.is_pressed('r') and not change:
		toggle("Head_Light")
        change = true
        push = true
	else:
		change = false
	if keyboard.is_pressed('t') and not change:	#if key 'a' is pressed
		toggle("Autonomous_Mode")
        change = true
        push = true
	else:
		change = false
	if keyboard.is_pressed('y') and not change:
		toggle("Circuit_Breaker")
        change = true
        push = true
	else:
		change = false
	
	time.sleep(0.05)
	
    if push:
        print(bin(data))
        serial_port.write(struct.pack('>B', data))
        push = false
flush_input()

