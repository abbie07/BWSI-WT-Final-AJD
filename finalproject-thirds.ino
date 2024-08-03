int fetPin = A1; // mosfet pin to control heater
int led = 13;
const int SOFT_POT_PIN = A0;
int potVal = 0; // Variable to store the input from the potentiometer
int potPin = A0; // Potentiometer output connected to analog 0

void setup() 
{
  Serial.begin(9600);
  pinMode(fetPin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(SOFT_POT_PIN, INPUT);
}

void loop() {
  potVal = analogRead(potPin);   // read the potentiometer value at the input pin
    analogWrite(fetPin, 0); // duty cycle out of 255
    
    if (potVal < 341)  // Lowest third of the potentiometer's range (0-340)
    {
    potVal = (potVal * 3) / 4; // Normalize to 0-255
    analogWrite(fetPin, 0);
    }

    else if (potVal < 682) // Middle third of potentiometer's range (341-681)
    {
    potVal = ( (potVal-341) * 3) / 4; // Normalize to 0-255
    analogWrite(fetPin, 170);
    }
  
    else  // Upper third of potentiometer's range (682-1023)
    {
    potVal = ( (potVal-341) * 3) / 4; // Normalize to 0-255
    analogWrite(fetPin, 230);
    }
}
