/* Written by Michael Dornisch
https://github.com/eovnu87435ds

PWM Relay for Arduino

I use this as a video tx input switcher, to switch between my board cam
and gopro feed for FPV. It works as follows:
A temporary high signal on the pwm channel (over 1700us) will toggle 
between input 0 and 1. It defaults to input 0 on power loss, so wire
your board cam to input 0.

I use it on a 8th channel mapped to my trainer switch. pressing the switch
toggles the video.

WIRING:

PWM Cable:   Red to +5v of arduino.
             White to Digital I/O pin 3 of Arduino
             Black to ground of arduino
             
Relay:       Coil pin 1 to Digital I/O pin 2 of Arduino
             Coil pin 2 to ground of arduino
             Common (C) pin to Video Tx Video in
             NC pin to primary camera video line
             NO pin to second camera video line
             
I used a Pro Mini Clone and a micro 1A relay and was able to put heat shrink around the entire unit, making it small and portable.

*/
             

byte PWM_PIN = 3;
int pwm_val;
boolean pwmactivate = false;
boolean relayval = false;
byte relay = 2;


void setup() {
  pinMode(PWM_PIN, INPUT);
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);

}

void loop() {
  pwm_val = pulseIn(PWM_PIN, HIGH);
  Serial.println(pwm_val);
  if (pwm_val >= 1700) {
 toggle();
  }


}

void toggle(){
  relayval = !relayval;
  if(relayval){
 digitalWrite(relay,HIGH);
}
if(!relayval){
  digitalWrite(relay,LOW);
}
delay(1000);
}
