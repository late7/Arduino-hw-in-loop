void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
  //  delay(50);
  // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
    Serial.print("Voltage: ");
    Serial.println(voltage);
    delay(1000);
}
