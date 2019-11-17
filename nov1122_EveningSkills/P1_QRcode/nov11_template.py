# prepare OpenCV, pyzbar, datetime, csv and winsound libraries
import cv2
from pyzbar.pyzbar import decode
from datetime import datetime
import csv
import winsound

# source preparation: image file, video file, camera
cap = cv2.VideoCapture(0)
while True:
    # read image
    ret,img = cap.read()
    # pre-process image
    img = cv2.flip(img, flipCode=1)
    # extract QR code from image

    # preview image and update GUI
    cv2.imshow('Preview', img)
    if cv2.waitKey(10) == ord('q'):
        break
cap.release()