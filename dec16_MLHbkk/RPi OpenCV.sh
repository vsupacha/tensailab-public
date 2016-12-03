# from 2016-11-25, need to create empty 'ssh' in boot partition

# expand filesystems, enable camera and VNC
sudo raspi-config

# upgrade programs
sudo apt-get update
sudo apt-get upgrade

# run VNC for remote desktop
vncserver -geometry 1024x768

# install & configure motion (height width framerate stream_localhost)
sudo apt-get install motion
sudo nano /etc/motion/motion.conf

# add camera driver
sudo modprobe bcm2835-v4l2
ls /dev/video0

# run motion
sudo motion -n

# install python libraries
sudo apt-get install python-opencv opencv-data 

