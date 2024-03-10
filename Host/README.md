# Computer controll

I am using an Orange Pi One, with an Armbian OS installed, to controll the relay.
I enabled UART3 using the armbian-config utility, so now it is accessible as /dev/ttyS3 
on pins PA13 (TXD) and PA14 (RXD) of the 40 pin GPIO header.

To send data I am developing a python script, based on Fastapi framework. It is a web server to enable web access, with a webcam video feed. The video feed is enabled on port 8013 using ustreamer. The "./Host/web_server/tools/ustreamer.sh" script is to start/stop the video feed. 