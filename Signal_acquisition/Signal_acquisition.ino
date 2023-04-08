int sensorPin = A1;  // select the input pin for the potentiometer
float sensorValue = 0; // variable to store the value coming from the sensor

// void setup()
// {
//     Serial.begin(9600);
//     analogReadResolution(12);
// }

// void loop()
// {
//     // read the value from the sensor:
//     sensorValue = analogRead(sensorPin);
//     Serial.println(sensorValue);
//     delay(10);
// }

#define DAC_PIN A0 // Make code a bit more legible

float x = 0;            // Value to take the sin of
float increment = 0.02; // Value to increment x by each time
int frequency = 440;    // Frequency of sine wave
float incomingByte = 0;
int dacVoltage = 0;
void setup()
{
    SerialUSB.begin(9600);
    analogReadResolution(12);
}

void loop()
{
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    SerialUSB.println(sensorValue);
    delay(10);
}