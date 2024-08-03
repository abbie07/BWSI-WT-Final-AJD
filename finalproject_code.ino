const int potPin = A0; // Pin connected to the potentiometer
const int heaterPin = A1; // Pin connected to the MOSFET gate (PWM pin)
int potValue = 0; // Variable to store the potentiometer value
int pwmValue = 0; // Variable to store the PWM value

void setup() {
  pinMode(heaterPin, OUTPUT);
  Serial.begin(9600); // Start the Serial communication for debugging
}

void loop() {
  // Read the potentiometer value
  potValue = analogRead(potPin);
  
  // Map the potentiometer value to a PWM range (0-255)
  pwmValue = map(potValue, 0, 1023, 0, 255);
  
  // Set the PWM value to control the heater
  analogWrite(heaterPin, pwmValue);
  
  // Print the values for debugging
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" -> PWM Value: ");
  Serial.println(pwmValue);
  
  delay(100);
}