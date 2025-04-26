/* PWM Motor Control Sketch */

#define PWM_PIN 3
#define DIAL_CTL_PIN A0
#define UPDATE_PERIOD_MS 1000  // Update once per second

#define DEBUG_SERIAL

void setup()
{
  #ifdef DEBUG_SERIAL
  Serial.begin(9600);
  #endif

  pinMode(PWM_PIN, OUTPUT);

}


void loop()
{
  int dial_ctl_val;

  dial_ctl_val = analogRead(DIAL_CTL_PIN);
  
  /* the analog read gives 0-1023.  
   *  We want 0-255, so shift by 2.
   */
  dial_ctl_val = dial_ctl_val >> 2;

  #ifdef DEBUG_SERIAL
  Serial.println(dial_ctl_val);
  #endif

  analogWrite(PWM_PIN, dial_ctl_val);

  delay(UPDATE_PERIOD_MS);
}
