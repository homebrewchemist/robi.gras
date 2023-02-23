### Hardware list

1. 12v PSU
2. 5v Step Down
3. Raspberry Pi 4
4. 6Ch Relay
5. 2Ch Relay
6. Thermocouple
7. Outlets
8. Peristaltic Pumps
9. NPK Sensor
10. pH Probe
11. EC Probe
12. DO Probe
13. RTD Thermocouple
14. Switches
15. Displays

### Chip list

1. ATMega928
2. ATTiny84
3. ATTiny85
4. SHT-31 (Temp/Humid)
5. SDP-810 (Pressure)
6. ADS1015 (ADC)
7. 555 Timers (Low Voltage)
8. TB-6612 (Mot Control)
9. DS-3502 (Rheostat)
10. 555 Timer (High Voltage)
11. DS3231 (RTC)
12. AT24C32 (EEPROM)
13. RS-485 (UART)
14. pH-OEM (pH)
15. EC-OEM (EC)
16. DO-OEM (DO)
17. RTD-2-OEM (RTD)

### Modules in process

- [ ] Envro Manager (SHT-31)
- [ ] Envro Manager (SDP-810)
- [ ] Soil Monitor (555 Cap)
- [ ] Soil Sensor Calibration (Soft)
- [ ] Soil Monitor (2w Therm)
- [ ] Soil Monitor (ADS1015)
tbd


- [ ] Real Time Clock (RTC)
- [ ] Irrigation Control (Mot)
- [ ] Enviro Control (Relay)

- [ ] Internal Monitoring Temp/Power

###### i2c Address list

0x25 (Diff Pressure SDP-810)

0x28 (Irrigation POT DS3502)
0x29 (pH Loop POT DS3502)

0x40 (Temp/Rh Sensor HDC1080)

0x44 (Inside SHT-31)
0x45 (Outside SHT-31)

0x48 (Soil ADS1015 1)
0x49 (Soil ADS1015 2)
0x4A (Soil ADS1015 3)
0x4B (Soil ADS1015 4)

0x57 (EEPROM AT24C32)

0x61 (DO-OEM)
0x63 (pH-OEM)
0x64 (EC-OEM)
0x66 (RTD-2-OEM)

0x68 (RTC DS3231)

### Process Flow

#### envro.manager
if Ti > T
Turn on Heater
if Ti < T
Turn on A/C

if Hi < H
Turn on Humidifer
if Hi > H
Turn on Dehumidifer

if Pdiff < 0
Turn on Vent

#### envro.sensor
Read SHT-31a, Inside Temp = Ti
Read SHT-31b, Outside Temp = To

Read SHT-31a, Inside Humid = Hi
Read SHT-31b, Outside Humid = Ho

Read SPD-810, Differential Pressure = Pdiff

#### enviro.switch
Heater
A/C
Canopy Fan
Floor Fan
Humidifer
Dehumidifier
Vent


#### irrigation.manager


#### soil.sensor

Read SoilCap



Read ADS1015, SoilCap = C
if soil.Tc < C
Turn on irg.w

Read ADS1015, SoilTemp = S
if SoilTemp < S
Turn on TankHeat

#### Water
#### pH
Read pH sensor, pH = P
if pH != P
Adjust pH, pH Protocol

#### Nutrient
Read RS-485
UNKNOWN PROCESS

#### Subsystems

Initialize I2C
Read RTC
EEprom