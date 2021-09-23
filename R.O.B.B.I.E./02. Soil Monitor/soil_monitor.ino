#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1015 ads_0;  // I2C ADDR pin GND
Adafruit_ADS1015 ads_1;  // I2C ADDR pin VDD
Adafruit_ADS1015 ads_2;  // I2C ADDR pin SDA
Adafruit_ADS1015 ads_3;  // I2C ADDR pin SCL

void setup(void)
{
  Serial.begin(9600);

  Serial.println(ads_0.begin(0x48) ? "Node 1 connected" : "Node 1 failed to initialize");  // I2C ADDR pin GND
  ads_0.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  ads_0.setDataRate(0);  // 128 samples per second

  Serial.println(ads_1.begin(0x49) ? "Node 2 connected" : "Node 2 failed to initialize");  // I2C ADDR pin VDD
  ads_1.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  ads_1.setDataRate(0);  // 128 samples per second

  Serial.println(ads_2.begin(0x4A) ? "Node 3 connected" : "Node 3 failed to initialize");  // I2C ADDR pin SDA
  ads_2.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  ads_2.setDataRate(0);  // 128 samples per second

  Serial.println(ads_3.begin(0x4B) ? "Node 4 connected" : "Node 4 failed to initialize");  // I2C ADDR pin SCL
  ads_3.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  ads_3.setDataRate(0);  // 128 samples per second
}

void loop(void)
{
  int16_t adc048, adc148, adc248, adc348, adc049, adc149, adc249, adc349, adc04A, adc14A, adc24A, adc34A, adc04B, adc14B, adc24B, adc34B;
  float volts048, volts148, volts248, volts348, volts049, volts149, volts249, volts349, volts04A, volts14A, volts24A, volts34A, volts04B, volts14B, volts24B, volts34B;

  adc048 = ads_0.readADC_SingleEnded(0);
  adc148 = ads_0.readADC_SingleEnded(1);
  adc248 = ads_0.readADC_SingleEnded(2);
  adc348 = ads_0.readADC_SingleEnded(3);
  adc049 = ads_1.readADC_SingleEnded(0);
  adc149 = ads_1.readADC_SingleEnded(1);
  adc249 = ads_1.readADC_SingleEnded(2);
  adc349 = ads_1.readADC_SingleEnded(3);
  adc04A = ads_2.readADC_SingleEnded(0);
  adc14A = ads_2.readADC_SingleEnded(1);
  adc24A = ads_2.readADC_SingleEnded(2);
  adc34A = ads_2.readADC_SingleEnded(3);
  adc04B = ads_3.readADC_SingleEnded(0);
  adc14B = ads_3.readADC_SingleEnded(1);
  adc24B = ads_3.readADC_SingleEnded(2);
  adc34B = ads_3.readADC_SingleEnded(3);
  
  volts048 = ads_0.computeVolts(adc048);
  volts148 = ads_0.computeVolts(adc148);
  volts248 = ads_0.computeVolts(adc248);
  volts348 = ads_0.computeVolts(adc348);
  volts049 = ads_1.computeVolts(adc049);
  volts149 = ads_1.computeVolts(adc149);
  volts249 = ads_1.computeVolts(adc249);
  volts349 = ads_1.computeVolts(adc349);
  volts04A = ads_2.computeVolts(adc04A);
  volts14A = ads_2.computeVolts(adc14A);
  volts24A = ads_2.computeVolts(adc24A);
  volts34A = ads_2.computeVolts(adc34A);
  volts04B = ads_3.computeVolts(adc04B);
  volts14B = ads_3.computeVolts(adc14B);
  volts24B = ads_3.computeVolts(adc24B);
  volts34B = ads_3.computeVolts(adc34B);
 
  Serial.println("-----------------------------------------------------------");
  Serial.print("AIN0: "); Serial.print(adc048); Serial.print("  "); Serial.print(volts048); Serial.println("V");
  Serial.print("AIN1: "); Serial.print(adc148); Serial.print("  "); Serial.print(volts148); Serial.println("V");
  Serial.print("AIN2: "); Serial.print(adc248); Serial.print("  "); Serial.print(volts248); Serial.println("V");
  Serial.print("AIN3: "); Serial.print(adc348); Serial.print("  "); Serial.print(volts348); Serial.println("V");
  Serial.print("AIN0: "); Serial.print(adc049); Serial.print("  "); Serial.print(volts049); Serial.println("V");
  Serial.print("AIN1: "); Serial.print(adc149); Serial.print("  "); Serial.print(volts149); Serial.println("V");
  Serial.print("AIN2: "); Serial.print(adc249); Serial.print("  "); Serial.print(volts249); Serial.println("V");
  Serial.print("AIN3: "); Serial.print(adc349); Serial.print("  "); Serial.print(volts349); Serial.println("V");
  Serial.print("AIN0: "); Serial.print(adc04A); Serial.print("  "); Serial.print(volts04A); Serial.println("V");
  Serial.print("AIN1: "); Serial.print(adc14A); Serial.print("  "); Serial.print(volts14A); Serial.println("V");
  Serial.print("AIN2: "); Serial.print(adc24A); Serial.print("  "); Serial.print(volts24A); Serial.println("V");
  Serial.print("AIN3: "); Serial.print(adc34A); Serial.print("  "); Serial.print(volts34A); Serial.println("V");
  Serial.print("AIN0: "); Serial.print(adc04B); Serial.print("  "); Serial.print(volts04B); Serial.println("V");
  Serial.print("AIN1: "); Serial.print(adc14B); Serial.print("  "); Serial.print(volts14B); Serial.println("V");
  Serial.print("AIN2: "); Serial.print(adc24B); Serial.print("  "); Serial.print(volts24B); Serial.println("V");
  Serial.print("AIN3: "); Serial.print(adc34B); Serial.print("  "); Serial.print(volts34B); Serial.println("V");
  
  delay(30000);
}