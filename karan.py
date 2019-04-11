import time
import sys
import termios
import keyboard

#define karan


def flush_input():
	import sys, termios
	termios.tcflush(sys.stdin, termios.TCIOFLUSH)

speed =0
angle =30

def speed_up():
	global speed
	speed+=0.5
	if speed > 4:
		speed=4
def speed_down():
	global speed
	speed-=0.5
	if speed<0:
		speed=0
def turn_left():
	global angle
	angle+=1
	if angle>60:
		angle =60
def turn_right():
	global angle
	angle-=1
	if angle<0:
		angle =0

def straighten():
	global angle
	angle=30


def brake_and_reverse():
	global speed
	if speed>0:
		speed=0
	else:
		speed=-1
	


while True:#making a loop
	 #used try so that if user pressed other than the given key error will not be shown
	if keyboard.is_pressed('w'):	#if key 'a' is pressed
		speed_up()
	else:
		speed_down()
	if keyboard.is_pressed('a') and not(keyboard.is_pressed('d')):
		turn_left()
	elif keyboard.is_pressed('d') and not(keyboard.is_pressed('a')):
		turn_right()
	else:
		straighten()
	if(keyboard.is_pressed('s')):
		brake_and_reverse()
	time.sleep(0.05)
	print('Speed= '+str(speed)+' Angle = '+str(angle))
	




flush_input()

