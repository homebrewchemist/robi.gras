#include "Arduino.h" // Used for arduino board
#include "Wire.h"  // Used for I2C
#include "Adafruit_SHT31.h" // Used for SHT-30-D

//Adafruit_SHT31 env_0  // I2C ADDR 0x44
//Adafruit_SHT31 env_1  // I2C ADDR 0x45 connect ADR to VIN

bool enableHeater = false;
uint8_t loopCnt = 0;

Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup(void)  // Setup code, runs once
{
  Serial.begin(9600);  // Serial speed 9600 baud

  Serial.println("SHT31 test");
  if (! sht31.begin(0x44)) {   // Set to 0x45 for alt i2c addr
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }

  Serial.print("Heater Enabled State: ");
  if (sht31.isHeaterEnabled())
    Serial.println("ENABLED");
  else
    Serial.println("DISABLED");  
}

void loop(void)  // Loop code, runs on repeat
{
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();

  if (! isnan(t)) {  // check if 'is not a number'
    Serial.print("Temp *C = "); Serial.print(t); Serial.print("\t\t");
  } else { 
    Serial.println("Failed to read temperature");
  }
  
  if (! isnan(h)) {  // check if 'is not a number'
    Serial.print("Hum. % = "); Serial.println(h);
  } else { 
    Serial.println("Failed to read humidity");
  }

  delay(1000);

  // Toggle heater enabled state every 30 seconds
  // An ~3.0 degC temperature increase can be noted when heater is enabled
  if (loopCnt >= 30)
  {
    enableHeater = !enableHeater;
    sht31.heater(enableHeater);
    Serial.print("Heater Enabled State: ");
    if (sht31.isHeaterEnabled())
      Serial.println("ENABLED");
    else
      Serial.println("DISABLED");

    loopCnt = 0;
  }
  loopCnt++;
}
/*
  temp0 = env_0.readTemperature();
  humid0 = env_0.readHumidity();

  Serial.println("-----------------------------------------------------------");
  Serial.print("Temp *C = "); Serial.print(temp0); Serial.print("\t\t");
  Serial.print("Hum. % = "); Serial.println(humid0);

  delay(30000);