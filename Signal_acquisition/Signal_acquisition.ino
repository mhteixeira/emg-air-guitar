int sensorPin = A1;  // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor

void setup()
{
    Serial.begin(9600);
    analogReadResolution(12);
}

void loop()
{
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    delay(10);
}