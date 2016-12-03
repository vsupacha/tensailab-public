# import the necessary packages
import time
import cv2
import numpy as np
 
# initialize the camera and grab a reference to the raw camera capture
cap = cv2.VideoCapture(0)
#kernel = np.ones((5,5),np.uint8)

# grab an image from the camera
while True:
    # read image
    success,img = cap.read()
    
    # try some OpenCV features
    #gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    #edges_img = cv2.Canny(img,100,200)
    #blur_img = cv2.blur(img,(5,5))    
    #opening_img = cv2.morphologyEx(img, cv2.MORPH_OPEN, kernel)
    
    # display the image on screen 
    cv2.imshow("Image", img)
    key = cv2.waitKey(1) & 0xFF
    
    # check for 'q' to quit
    if key == ord('q'):
        break
cv2.destroyAllWindows()