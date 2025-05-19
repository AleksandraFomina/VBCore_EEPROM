
#ifndef VB_EEPROM_H
#define VB_EEPROM_H
#include "Arduino.h"
#include <Wire.h>  // Подключаем здесь, чтобы компилятор знал про Wire


extern const int PAGE_SIZE;
extern const int EEPROM_SIZE;




void initEEPROM();     // Объявление
void clearEEPROM(byte fill = 0xFF, byte eeprom_i2c_addr = 0x50);
bool isDataInEEPROM(uint16_t addr, byte eeprom_i2c_addr = 0x50);
void writeFloatToEEPROM(uint16_t addr, float value, byte eeprom_i2c_addr = 0x50);
float readFloatFromEEPROM(uint16_t addr, byte eeprom_i2c_addr = 0x50);

#endif