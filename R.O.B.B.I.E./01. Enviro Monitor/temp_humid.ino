#include <Wire.h>  // Used for I2C
#include <Adafruit_SHT31.h> // Used for SHT-30-D

Adafruit_SHT31 env_0;  // I2C ADDR 0x44
//Adafruit_SHT31 env_1;  // I2C ADDR 0x45

bool enableHeater = false;

void setup(void)  // Setup code, runs once
{
  Serial.begin(9600);  // Serial speed 9600 baud

  Serial.println(env_0.begin(0x44) ? "Env Node A: connected" : "Env Node A: failed to initialize");
  Serial.print("Heater State: ");
  if (env_0.isHeaterEnabled())  // If heater is on print ENABLED
    Serial.println("ENABLED");
  else
    Serial.println("DISABLED");
/*  
  Serial.println(env_1.begin(0x45) ? "Env Node B: connected" : "Env Node B: failed to initialize");
  Serial.print("Heater State: ");
  if (env_1.isHeaterEnabled())  // If heater is on print ENABLED
    Serial.println("ENABLED");
  else
    Serial.println("DISABLED");*/
  }

void loop(void)  // Loop code, runs on repeat
{
  float temp0, temp1, humid0, humid1;

  temp0 = env_0.readTemperature();
  //temp1 = env_1.readTemperature();

  humid0 = env_0.readHumidity();
  //humid1 = env_1.readHumidity();

  Serial.println("-----------------------------------------------------------");
  Serial.print("Temp *C = "); Serial.print(temp0); Serial.print("\t\t");
  Serial.print("Hum. % = "); Serial.println(humid0);
  Serial.print("Temp *C = "); Serial.print(temp1); Serial.print("\t\t");
  Serial.print("Hum. % = "); Serial.println(humid1);

  delay(30000);
}