# Arduino-PWM-Video-Switcher
This code let's you take an arduino and a relay and use it as a video source switcher for FPV applications

I use this as a video tx input switcher, to switch between my board cam and gopro feed for FPV. It works as follows:
A temporary high signal on the pwm channel (over 1700us) will toggle between input 0 and 1. It defaults to input 0 on power loss, so wire your board cam to input 0.

I use it on a 8th channel mapped to my trainer switch. pressing the switch toggles the video.

WIRING:

PWM Cable:  

             Red to +5v of arduino.
             
             White to Digital I/O pin 3 of Arduino
             
             Black to ground of arduino
             
Relay:       

             Coil pin 1 to Digital I/O pin 2 of Arduino
             
             Coil pin 2 to ground of arduino
             
             Common (C) pin to Video Tx Video in
             
             NC pin to primary camera video line
             
             NO pin to second camera video line
             
I used a Pro Mini Clone and a micro 1A relay and was able to put heat shrink around the entire unit, making it small and portable.
