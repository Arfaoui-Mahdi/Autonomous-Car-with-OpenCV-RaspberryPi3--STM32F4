import picamera
import io
import cv2
import time
import math
import serial
from time import sleep
import numpy
ser = serial.Serial(
  port='/dev/ttyAMA0',
  baudrate = 9600,
  parity=serial.PARITY_NONE,
  stopbits=serial.STOPBITS_ONE,
  bytesize=serial.EIGHTBITS,
  timeout=1
)

global buff





def det(gray,image) :
 
    
 def rect(ps,image):
    dist = 50 
    for (x,y,w,h) in ps:
        dist = (2*3.14*180)/(w+h*360)*1000+3
    return(dist) ;
   
 def rectf(ps,image):
    dist = 50 
    for (x,y,w,h) in ps:
        dist = (2*3.14*180)/(w+h*360)*1000+3
    return(dist,x,y,w,h) ;

 def extract(img,x,y,w,h) :
     p = img[y:y+h,x:x+w]
     return (p) ;

 def traffic(img) :
     b,g,r = cv2.split(img)
     if (g.sum > r.sum) :
         r = "green"
     else :
         r = "red"
     return (r) ;



    


#Load a cascade file for detecting yield
 roundabout_cascade = cv2.CascadeClassifier('roundabout.xml')
 stop_cascade = cv2.CascadeClassifier('stop_sign.xml')
 speed1_cascade = cv2.CascadeClassifier('speedl.xml')
 roundabout_cascade = cv2.CascadeClassifier('roundabout.xml')
 yieled_cascade = cv2.CascadeClassifier('yield.xml')
 traffic_cascade  = cv2.CascadeClassifier('traf1.xml')
 
 

 
#Convert to grayscale
 

#Look for pannels in the image using the loaded cascade file
 roundabouts = 0
 ds = 5000
 df = 5000
 dp = 5000
 dy = 5000
 v = 'green'
 res = '0'
 roundabouts = roundabout_cascade.detectMultiScale(gray, 1.1, 5)
 if str(len(roundabouts)) != '0' :
  speeds= speed1_cascade.detectMultiScale(gray, 1.1, 5)
  stops= stop_cascade.detectMultiScale(gray, 1.1, 5)
  if  str(len(stops)) != '0' :
      ds = rect(stops,image)
      #print ds
  
  if str(len(speeds)) != '0' :
      dp = rect(speeds,image)
      #print dp
      
   
 yieleds= yieled_cascade.detectMultiScale(gray, 1.1, 5) 
 
 if str(len(yieleds)) != '0' :
      dy = rect(yieleds,image)
      
      
 traffics= traffic_cascade.detectMultiScale(gray, 1.1, 5)
 
 if str(len(traffics)) != '0' :
     df,x,y,w,h = rectf(traffics,image)
     im = extract(image,x,y,w,h)
     v = traffic(im)
     
 mi = min(ds,dp,dy,df)
 #print mi
 
 if (mi == ds ) and (ds <= 50) and (ds != 0) :
     res = '2'
 elif (mi == dp) and (dp <= 50) and ( dp != 0) :
     res = '5' 
 elif (mi == df) and (v == "red") and (df <= 50) and ( df != 0) :
     res = '4'
 elif (mi == dy) and (dy <= 30) and ( dy != 50) :
     res = '3'
 #else :
    # print "no" 
     
     
     
 return(res)




while (True) :
    
    stream = io.BytesIO()   
    with picamera.PiCamera() as camera:
      camera.resolution = (640, 480)
      camera.capture(stream, format='jpeg') #!!!!!
    
    buff= numpy.fromstring(stream.getvalue(), dtype=numpy.uint8)
    #Now creates an OpenCV image
    image = cv2.imdecode(buff, 1) 
    
    gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
    res = det(gray,image)
    ser.isOpen()
    ser.write(str(res))
    
    

    
     
       
    


    
     
