// int sensorPin = A1;  // select the input pin for the potentiometer
// int sensorValue = 0; // variable to store the value coming from the sensor

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
    analogWriteResolution(10); // Set analog out resolution to max, 10-bits
    analogReadResolution(12);  // Set analog input resolution to max, 12-bits

    SerialUSB.begin(9600);
}

void loop()
{
    // Generate a voltage value between 0 and 1023.
    // Let's scale a sin wave between those values:
    // Offset by 511.5, then multiply sin by 511.5.

    if (SerialUSB.available() > 0)
    {
        incomingByte = Serial.parseFloat(SKIP_ALL, '\n');
        dacVoltage = 512 + (int)(incomingByte * 1024 / 3.3);
    }

    // Generate a voltage between 0 and 3.3V.
    // 0= 0V, 1023=3.3V, 512=1.65V, etc.
    analogWrite(DAC_PIN, dacVoltage);

    // Now read A1 (connected to A0), and convert that
    // 12-bit ADC value to a voltage between 0 and 3.3.
    // float voltage = analogRead(A1) * 3.3 / 4096.0 - 1.65;
    float voltage = analogRead(A1);
    SerialUSB.println(voltage); // Print the voltage.
    delay(1);                   // Delay 1ms
}