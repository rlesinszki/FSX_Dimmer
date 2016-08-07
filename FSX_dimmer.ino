/* FSX_Dimmer
 *  1. FS reads dimmer pot over RS485
 *  2. FS commands LED dimming setting
 *  NOTE: FS also sends dimming commands to Clock (non-current controled
 *  devices
*/

#define LED_drive 11
#define brightnessControl A6
#define version 1.0

byte brightness = 50;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(LED_drive, OUTPUT);
  pinMode(brightnessControl, INPUT);
  HelloWorld();
}

// the loop function runs over and over again forever
void loop() {
  brightness = analogRead(brightnessControl) / 4;
  analogWrite(LED_drive, brightness);
  delay(100);              // wait for a second
  analogWrite(LED_drive, 0);
  delay(100);              // wait for a second
  Serial.println(brightness);
}


int HelloWorld() {
  Serial.print("Version: ");
  Serial.println(version);
  return(10);
}
