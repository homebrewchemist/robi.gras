## Equipment list

1. Raspberry Pi 4
2. ATMega and ATTiny assorted
3. DS3231 RTC/AT24C32 EEPROM
4. SHT30-D x2 Sensor
5. ADS1015 x4 ADC
6. AT24C32
7. 4ch Relay
8. outlets x2

## Modules in process

- [ ] Envro Monitor (SHT-30)
- [ ] Soil Monitor (Cap)
- [ ] Soil Monitor (Therm)
- [ ] Real Time Clock (RTC)
- [ ] Irrigation Control (Mot)
- [ ] Enviro Control (Relay)
- [ ] Soil Sensor Calibration (Soft)
- [ ] Internal Monitoring Temp/Power

## Process Flow

# Enviro
Read SHT-30, Temp = T
if Temp > T
Turn on HeatBulb

Read SPD-810, Press = P
if Pressure < P
Add Air Pressure UNKNOWN PROCESS

Read SHT-30, Humid = H
if Humid < H
Turn on Fog
if Humid > H
Turn on Fan

# Soil
Read ADS1015, SoilCap = C
if SoilCap < C
Turn on IrgPump

Read ADS1015, SoilTemp = S
if SoilTemp < S
Turn on TankHeat

# Water
# pH
Read pH sensor, pH = P
if pH != P
Adjust pH, pH Protocol

# Nutrient
Read RS-485
UNKNOWN PROCESS

# Subsystems

Initialize I2C
Read RTC
EEprom

