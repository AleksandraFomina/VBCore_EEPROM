
#ifndef VB_EEPROM_H
#define VB_EEPROM_H
#include "Arduino.h"
#include <Wire.h>  // Подключаем здесь, чтобы компилятор знал про Wire


extern const int PAGE_SIZE;
extern const int EEPROM_SIZE;
extern const int EEPROM_I2C_ADDR;


void initEEPROM();     // Объявление
void clearEEPROM(byte fill = 0xFF);
bool isDataInEEPROM(uint16_t addr);
void writeFloatToEEPROM(uint16_t addr, float value);
float readFloatFromEEPROM(uint16_t addr);

#endif