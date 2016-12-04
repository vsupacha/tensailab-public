# Streaming Video with Raspberry Pi and OpenCV
A short talk about streaming video using Raspberry Pi and OpenCV at the MLH Local Hack Bangkok. The event was hosted by [Enterprise Lab](http://www.enterpriselab.co/) on December 3rd, 2016 at PlayLab. 

The presentation material can be accessed onine by [this Prezi link](https://prezi.com/jptp8aabpo4q/rasberry-pi-with-camera/). 

## Requirements
* Raspberry Pi 3 + micro SD card (>= 8GB) + LAN cable + USB cable for power
* Raspberry Pi camera module or webcam
* [Raspbian Image](https://www.raspberrypi.org/downloads/)
* [PuTTY](http://www.putty.org/)
* [RealVNC Viewer](https://www.realvnc.com/download/viewer/)

## Examples
1. **capture.py** continuous capture and preview until press 'q'. 
2. **main.py** main program using Flask to provide video feed.
3. **capture_base.py** class to capture, encode as JPEG, and convert to string.
4. **capture_face.py** class to capture, do face detection, encode as JPEG, and convert to string.

## References
* [Accessing the Raspberry Pi Camera with OpenCV and Python](http://www.pyimagesearch.com/2015/03/30/accessing-the-raspberry-pi-camera-with-opencv-and-python/)
* [Detecting cats in images with OpenCV](http://www.pyimagesearch.com/2016/06/20/detecting-cats-in-images-with-opencv/)
* [Python Live Video Streaming Example](http://www.chioka.in/python-live-video-streaming-example/)
 