String buildNo = "1.0.4";

// Code starts here
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up a constant for the tilt switch pin
const int switchPin = 6;
const int tempPin = A0;
const int refPin = A1;

// variable to hold the value of the switch pin
int switchState = 0;

// variable to hold previous value of the switch pin
int prevSwitchState = 0;

// a variable to choose which reply from the crystal ball
int reply;

void setup() {
  Serial.begin(9600);
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);

  // set up the switch pin as an input
  pinMode(switchPin, INPUT);

  // Print a message to the LCD.
  lcd.print("Temperature:--.-");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("Build No:");
  lcd.setCursor(10, 1);
  lcd.print(buildNo);
}

int i = 0;
float sumtemp = 0.0;
int sleeptime = 10; //ms 
float j = 1000.0 / sleeptime;
float temp = 0.00;

void loop() {
  i++;
  delay(sleeptime);
  float tempSensorValue = analogRead(tempPin);
  float refSensorValue = analogRead(refPin);
  sumtemp = sumtemp + tempSensorValue;
  
  if(i >= j) {
    float voltage = sumtemp/j/1024.0 * 5.0;
    temp = ( voltage - 0.5) * 100 + 0.80;
  
    Serial.print(" Temp Sensor volts: ");
    Serial.print(voltage,4);
    Serial.print(" Temp Sensor value: ");
    Serial.print(tempSensorValue,4);
    Serial.print(" Temperature: ");
    Serial.print(temp,2);
    Serial.print(" Ref: ");
    Serial.println(refSensorValue);
    i = 0;
    sumtemp = 0.0;
    lcd.setCursor(12, 0);
    lcd.print(temp,1);
  }
}
