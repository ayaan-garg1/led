// LED Brightness Control Using a Potentiometer
// Potentiometer wiper -> A0, LED (via 220 ohm) -> pin 9 (PWM)

const int potPin = A0;   // analog input from potentiometer
const int ledPin = 9;    // PWM-capable output pin

int potValue = 0;        // raw reading, 0-1023
int brightness = 0;      // PWM value, 0-255

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);    // to view values in Serial Monitor
}

void loop() {
  potValue = analogRead(potPin);                   // read knob position
  brightness = map(potValue, 0, 1023, 0, 255);     // scale to PWM range
  analogWrite(ledPin, brightness);                 // set LED brightness

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("  Brightness: ");
  Serial.print(brightness);
  Serial.print("  (");
  Serial.print(brightness * 100 / 255);
  Serial.println("%)");

  delay(50);                                       // small pause for stable output
}
