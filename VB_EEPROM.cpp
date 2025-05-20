#include "VB_EEPROM.h"


const int PAGE_SIZE = 64; // for AT24C256C
const int EEPROM_SIZE = 32768; // for AT24C256C  32,768 words of 8 bits each
const int EEPROM_I2C_ADDR = 0x50;

void initEEPROM(uint32_t pin_SDA, uint32_t pin_SCL){
  Wire.setSDA(pin_SDA); //pinSDA PB_7_ALT1
  Wire.setSCL(pin_SCL); //pinSCL PC6
  Wire.begin();
}

void clearEEPROM(byte fill) {
  byte buffer[PAGE_SIZE];
  for (int i = 0; i < PAGE_SIZE; i++) buffer[i] = fill;

  for (uint16_t addr = 0; addr < EEPROM_SIZE; addr += PAGE_SIZE) {
    Wire.beginTransmission(EEPROM_I2C_ADDR);
    Wire.write((addr >> 8) & 0xFF);  // Older address byte
    Wire.write(addr & 0xFF);         // Less address byte

    for (int i = 0; i < PAGE_SIZE; i++) {
      Wire.write(buffer[i]);
    }

    Wire.endTransmission();
    delay(5);  
  }
}

bool isDataInEEPROM(uint16_t addr ) { // func for 4-byte size data
  // If all 4 bytes are equal 0xFF — empty
  Wire.beginTransmission(EEPROM_I2C_ADDR);
  Wire.write((addr >> 8) & 0xFF);
  Wire.write(addr & 0xFF);
  Wire.endTransmission();

  Wire.requestFrom(EEPROM_I2C_ADDR, 4);
  for (int i = 0; i < 4; i++) {
    while (!Wire.available());
    if (Wire.read() != 0xFF) return true;  
  }
  return false;  
}

void writeFloatToEEPROM(uint16_t addr, float value) {
  byte* p = (byte*) &value;  

  Wire.beginTransmission(EEPROM_I2C_ADDR);
  Wire.write((addr >> 8) & 0xFF);  // Старший байт адреса
  Wire.write(addr & 0xFF);         // Младший байт адреса

  for (int i = 0; i < 4; i++) {
    Wire.write(p[i]);  
  }

  Wire.endTransmission();
  delay(5);
}

float readFloatFromEEPROM(uint16_t addr) {
  byte buffer[4];

  Wire.beginTransmission(EEPROM_I2C_ADDR);
  Wire.write((addr >> 8) & 0xFF);
  Wire.write(addr & 0xFF);
  Wire.endTransmission();

  Wire.requestFrom(EEPROM_I2C_ADDR, 4);
  for (int i = 0; i < 4; i++) {
    while (!Wire.available());
    buffer[i] = Wire.read();
  }

  float value;
  memcpy(&value, buffer, 4);
  return value;
}