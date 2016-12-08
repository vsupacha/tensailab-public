# import the necessary packages
import time
import cv2
import numpy as np

class Capture():
    def __init__(self):
        self.cap = cv2.VideoCapture(0)
        xmlpath = '/usr/share/opencv/haarcascades/'
        classifier = 'haarcascade_frontalface_default.xml'
        self.detector = cv2.CascadeClassifier(classifier)

    def __del__(self):
        self.cap.release()
        
    def get_frame(self):
        success, img = self.cap.read()
        gray_img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
        faces = self.detector.detectMultiScale(gray_img, 1.1, 5)
        for (x,y,w,h) in faces:
            cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,0),2)
        ret, jpeg = cv2.imencode('.jpg', img)
        return jpeg.tostring()
