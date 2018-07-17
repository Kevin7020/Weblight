#ifndef LED_H
#define LED_H
#define PWM_LED 5
/*
void Led_fade( void ) {
  int brightness = 0;    // how bright the LED is
  int fadeAmount = 5;    // how many points to fade the LED by

  for (int i = 0; i <= 3; i++) { // the loop routine
    // set the brightness of pin PWM_LED:
    analogWrite(PWM_LED, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    delay(30); // wait for 30 milliseconds to see the dimming effect
  }
}
*/
void send_led_values_html() { // get the value of request argument "state" and convert it to an int
  int state = server.arg("state").toInt();
  
  analogWrite(PWM_LED, state);
  server.send(200, "text/plain", String("LED is now ") + ((state)?"on":"off"));
}

/*
 * 
void send_led_values_html (){
  Led_fade();
  server.send ( 200, "text/plain", "OK");
  Serial.println(__FUNCTION__); 

}

 */
#endif
