#include <EEPROM.h>

// set the epprom addresses for the settings that we are keeping
#define E_INIT         1023
// the setting array size must match the settings number
uint8_t settings[5];
// settings addresses
#define SETTING_1   0
#define SETTING_2   1
#define SETTING_3   2
#define SETTING_4   3
#define SETTING_5   4

void setup()
{
  loadSettings();
}

void loop()
{
  //your program code and logic
}

void loadSettings() {
  if (EEPROM.read(E_INIT) == 'T') {
    //settings have been initialized, read them
    settings[SETTING_1] = EEPROM.read(SETTING_1);
    settings[SETTING_2] = EEPROM.read(SETTING_2);
    settings[SETTING_3] = EEPROM.read(SETTING_3);
    settings[SETTING_4] = EEPROM.read(SETTING_4);
    settings[SETTING_5] = EEPROM.read(SETTING_5);
  } else {
    //first time run, settings were never set
    EEPROM.write(SETTING_1, 4);
    settings[SETTING_1] = 4;
    EEPROM.write(SETTING_2, 4);
    settings[SETTING_2] = 4;
    EEPROM.write(SETTING_3, 90);
    settings[SETTING_3] = 90;
    EEPROM.write(SETTING_4, 4);
    settings[SETTING_4] = 4;
    EEPROM.write(SETTING_5, 8);
    settings[SETTING_5] = 8;
    EEPROM.write(E_INIT, 'T');    
  }
}

void updateSetting(int address, byte value) {
  EEPROM.update(address, value);
}
