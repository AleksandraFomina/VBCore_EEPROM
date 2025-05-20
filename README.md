Собраны функции для работы с EEPROM на драйверах моторов VBCore. Стоит учитывать, что функции писались для работы с данными типа float (занимают 4 байта). Функции для работы с другими типами будут реализованы позже. Базовый адрес устройства на шине 0x50 (A0-A2 - GND) и менять его нельзя! Реализованы следующие функции:

initEEPROM(uint32_t pin_SDA, uint32_t pin_SCL) - установка пинов SDA и SCL и инициализация Wire

clearEEPROM(byte fill) - очистка EEPROM, аргумент fill необязательный - по умолчанию в EEPROM записывается 0xFF

bool isDataInEEPROM(uint16_t addr) - функция вернет true, если по адресу addr записаны какие-то данные

writeFloatToEEPROM(uint16_t addr, float value) - функция запишет число value по указанному адресу addr

float readFloatFromEEPROM(uint16_t addr) - функция вернет значение, записанное по адресу addr  
