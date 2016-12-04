# import the necessary packages
import time
import cv2
import numpy as np

class Capture():
    def __init__(self):
        self.cap = cv2.VideoCapture(0)

    def __del__(self):
        self.cap.release()
        
    def get_frame(self):
        success, img = self.cap.read()
        ret, jpeg = cv2.imencode('.jpg', img)
        return jpeg.tostring()