import RPi.GPIO as GPIO                    
from time import sleep
import serial
import sys, termios, tty, os, time
import numpy as np
import time
ser = serial.Serial(
  port='/dev/ttyAMA0',
  baudrate = 9600,
  parity=serial.PARITY_NONE,
  stopbits=serial.STOPBITS_ONE,
  bytesize=serial.EIGHTBITS,
  timeout=1
)
import RPi.GPIO as GPIO                    




GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)                     

TRIG1 = 23                               
ECHO1 = 24    
TRIG2 = 27                           
ECHO2 = 22

#print "Distance measurement in progress"

GPIO.setup(TRIG1,GPIO.OUT)                  
GPIO.setup(ECHO1,GPIO.IN)    
GPIO.setup(TRIG2,GPIO.OUT)                  
GPIO.setup(ECHO2,GPIO.IN)               


while True :
  res = '0'
  GPIO.output(TRIG1, False)                
  #print "Waitng For Sensor To Settle"
  sleep(0.01)                            

  GPIO.output(TRIG1, True)                  
  sleep(0.00001)                      
  GPIO.output(TRIG1, False)                 

  while GPIO.input(ECHO1)==0:               
    pulse_start = time.time()              

  while GPIO.input(ECHO1)==1:               
    pulse_end = time.time()                 

  pulse_duration1 = pulse_end - pulse_start
  print "duration"
  
  GPIO.output(TRIG2, False)                
  #print "Waitng For Sensor To Settle"
  time.sleep(0.01)                            

  GPIO.output(TRIG2, True)                  
  time.sleep(0.00001)                      
  GPIO.output(TRIG2, False)                 

  while GPIO.input(ECHO2)==0:               
    pulse_start1 = time.time()              

  while GPIO.input(ECHO2)==1:               
    pulse_end1 = time.time()                 

  pulse_duration2 = pulse_end1 - pulse_start1

  distance1 = pulse_duration1 * 17150        
  distance1 = round(distance1, 2)
  distance2 = pulse_duration2 * 17150        
  distance2 = round(distance2, 2)   

       
  #print "Distance 1 :",distance1 - 0.5,"cm"  
  #print "Distance 2 :",distance2 - 0.5,"cm"
  sleep(1)
  	
  ser.isOpen()
  if (distance1 < 15 ) or (distance2 < 15 )  :
      res = '1'
  
  ser.write(str(res))
  