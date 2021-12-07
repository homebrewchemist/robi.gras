/*
*/

//Packages
#include <Wire.h>  // Used for I2C
#include <Adafruit_ADS1X15.h> // Used for ADS1015

//Objects
Adafruit_ADS1015 ads_0;  // I2C ADDR 0x48 pin GND
//Adafruit_ADS1015 ads_1;  // I2C ADDR 0x49 pin VDD
//Adafruit_ADS1015 ads_2;  // I2C ADDR 0x4A pin SDA
//Adafruit_ADS1015 ads_3;  // I2C ADDR 0x4B pin SCL

//Setup Code
void setup(void)  // Setup code, runs once
{
  Serial.begin(9600);  // Serial speed 9600 baud

  Serial.println(ads_0.begin(0x48) ? "Soil Node A: connected" : "Soil Node A: failed to initialize");  // I2C ADDR pin GND
  ads_0.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  ads_0.setDataRate(0);  // 128 samples per second
/*
  Serial.println(ads_1.begin(0x49) ? "Soil Node B: connected" : "Soil Node B: failed to initialize");  // I2C ADDR pin VDD
  ads_1.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  ads_1.setDataRate(0);  // 128 samples per second

  Serial.println(ads_2.begin(0x4A) ? "Therm Node A: connected" : "Therm Node A: failed to initialize");  // I2C ADDR pin SDA
  ads_2.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  ads_2.setDataRate(0);  // 128 samples per second

  Serial.println(ads_3.begin(0x4B) ? "Therm Node B: connected" : "Therm Node B: failed to initialize");  // I2C ADDR pin SCL
  ads_3.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  ads_3.setDataRate(0);  // 128 samples per second*/
}

//Loop Code
void loop(void)  // Loop code, runs on repeat
{
  int16_t cap0, cap1, cap2, cap3;  // cap0-7 Capacitive Soil Moisture Sensor 2.0   thm0-7 K Thermocouple
  float volts0, volts1, volts2, volts3;  // volts0-15 for voltage from sensor readings

  cap0 = ads_0.readADC_SingleEnded(0);
  cap1 = ads_0.readADC_SingleEnded(1);
  cap2 = ads_0.readADC_SingleEnded(2);
  cap3 = ads_0.readADC_SingleEnded(3);
  /*cap4 = ads_1.readADC_SingleEnded(0);
  cap5 = ads_1.readADC_SingleEnded(1);
  cap6 = ads_1.readADC_SingleEnded(2);
  cap7 = ads_1.readADC_SingleEnded(3);
  thm0 = ads_2.readADC_SingleEnded(0);
  thm1 = ads_2.readADC_SingleEnded(1);
  thm2 = ads_2.readADC_SingleEnded(2);
  thm3 = ads_2.readADC_SingleEnded(3);
  thm4 = ads_3.readADC_SingleEnded(0);
  thm5 = ads_3.readADC_SingleEnded(1);
  thm6 = ads_3.readADC_SingleEnded(2);
  thm7 = ads_3.readADC_SingleEnded(3);*/
  
  volts0 = ads_0.computeVolts(cap0);
  volts1 = ads_0.computeVolts(cap1);
  volts2 = ads_0.computeVolts(cap2);
  volts3 = ads_0.computeVolts(cap3);
  /*volts4 = ads_1.computeVolts(cap4);
  volts5 = ads_1.computeVolts(cap5);
  volts6 = ads_1.computeVolts(cap6);
  volts7 = ads_1.computeVolts(cap7);
  volts8 = ads_2.computeVolts(thm0);
  volts9 = ads_2.computeVolts(thm1);
  volts10 = ads_2.computeVolts(thm2);
  volts11 = ads_2.computeVolts(thm3);
  volts12 = ads_3.computeVolts(thm4);
  volts13 = ads_3.computeVolts(thm5);
  volts14 = ads_3.computeVolts(thm6);
  volts15 = ads_3.computeVolts(thm7);*/
 
  Serial.println("-----------------------------------------------------------");
  Serial.print("Ch 1: "); Serial.print(cap0); Serial.print("  "); Serial.print(volts0); Serial.println("V");
  Serial.print("Ch 2: "); Serial.print(cap1); Serial.print("  "); Serial.print(volts1); Serial.println("V");
  Serial.print("Ch 3: "); Serial.print(cap2); Serial.print("  "); Serial.print(volts2); Serial.println("V");
  Serial.print("Ch 4: "); Serial.print(cap3); Serial.print("  "); Serial.print(volts3); Serial.println("V");
  /*Serial.print("Ch 5: "); Serial.print(cap4); Serial.print("  "); Serial.print(volts4); Serial.println("V");
  Serial.print("Ch 6: "); Serial.print(cap5); Serial.print("  "); Serial.print(volts5); Serial.println("V");
  Serial.print("Ch 7: "); Serial.print(cap6); Serial.print("  "); Serial.print(volts6); Serial.println("V");
  Serial.print("Ch 8: "); Serial.print(cap7); Serial.print("  "); Serial.print(volts7); Serial.println("V");
  Serial.print("Ch 9: "); Serial.print(thm0); Serial.print("  "); Serial.print(volts04A); Serial.println("V");
  Serial.print("Ch 10: "); Serial.print(thm1); Serial.print("  "); Serial.print(volts14A); Serial.println("V");
  Serial.print("Ch 11: "); Serial.print(thm2); Serial.print("  "); Serial.print(volts24A); Serial.println("V");
  Serial.print("Ch 12: "); Serial.print(thm3); Serial.print("  "); Serial.print(volts34A); Serial.println("V");
  Serial.print("Ch 13: "); Serial.print(thm4); Serial.print("  "); Serial.print(volts04B); Serial.println("V");
  Serial.print("Ch 14: "); Serial.print(thm5); Serial.print("  "); Serial.print(volts14B); Serial.println("V");
  Serial.print("Ch 15: "); Serial.print(thm6); Serial.print("  "); Serial.print(volts24B); Serial.println("V");
  Serial.print("Ch 16: "); Serial.print(thm7); Serial.print("  "); Serial.print(volts34B); Serial.println("V");*/
  
  delay(30000);
}
