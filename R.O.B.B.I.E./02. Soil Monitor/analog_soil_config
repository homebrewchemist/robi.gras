const int dry0 = 595; // value for dry sensor
const int wet0 = 409; // value for wet sensor
const int dry1 = 595; // value for dry sensor
const int wet1 = 409; // value for wet sensor
const int dry2 = 595; // value for dry sensor
const int wet2 = 409; // value for wet sensor
const int dry3 = 595; // value for dry sensor
const int wet3 = 409; // value for wet sensor
const int dry4 = 595; // value for dry sensor
const int wet4 = 409; // value for wet sensor

void setup()
{
  Serial.begin(9600); //open serial port, set baud rate to 9600 bps
}

void loop()
{
  int soilSensor0 = analogRead(A0); //soilSensor analog pin
  int soilSensor1 = analogRead(A1);
  int soilSensor2 = analogRead(A2);
  int soilSensor3 = analogRead(A3);
  int soilSensor4 = analogRead(A4);
 
  // soil sensor range 400 to 590
  // map can translate this to a scale or 0% to 100%
  
  int soilMoist0 = map(soilSensor0, wet0, dry0, 100, 0);
  int soilMoist1 = map(soilSensor1, wet1, dry1, 100, 0);
  int soilMoist2 = map(soilSensor2, wet2, dry2, 100, 0);
  int soilMoist3 = map(soilSensor3, wet3, dry3, 100, 0);
  int soilMoist4 = map(soilSensor4, wet4, dry4, 100, 0);
  
  Serial.println("Sensor 1");
  Serial.print(soilMoist0);
  Serial.println("Sensor 2");
  Serial.print(soilMoist1);
  Serial.println("Sensor 3");
  Serial.print(soilMoist2);
  Serial.println("Sensor 4");
  Serial.print(soilMoist3);
  Serial.println("Sensor 5");
  Serial.print(soilMoist4);
  
  delay(500);
}