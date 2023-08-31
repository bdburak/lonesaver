
// Write string from eeprom. Address-1 is the length
void writeStringArrayToEEPROM(String message, int address){
  int lenght = message.length();
  for (int i = 0; i < lenght; i++) {
    EEPROM.write(address + i, byte(message[i]));
  }
  // Serial.println();
  EEPROM.write(address-1, byte(lenght));
  EEPROM.commit();
}
// Read string from eeprom. Address-1 is the length
String readStringFromEEPROM(int address){
  String temp;
  for (int i = 0; i < int(EEPROM.read(address-1)); i++) {
    // Serial.println(EEPROM.read(address + i));
    temp += char(EEPROM.read(address + i));
  }
  return temp;
}

// Update SSID data on eeprom
void updateSSIDEEPROM(String data){
  writeStringArrayToEEPROM(data, 1);
}
// Update wifi password data on eeprom
void updatePasswordEEPROM(String data){
  writeStringArrayToEEPROM(data, 52);
}
// Update message data on eeprom
void updateMessageEPROM(String data){
  writeStringArrayToEEPROM(data, 104);
}
// Update message interval data on eeprom
void updateIntervalEPROM(byte data){
  EEPROM.write(155, data);
}

// Retrieve SSID data from eeprom
String retrieveSSID(){
  // ssid info starts from address 1
  return readStringFromEEPROM(1);
}
// Retrieve wifi password data from eeprom
String retrievePassword(){
  // password info starts from address 52
  return readStringFromEEPROM(52);
}
// Retrieve message data from eeprom
String retrieveMessage(){
  // message info starts from address 104
  return readStringFromEEPROM(104);
}
// Retrieve message interval data from eeprom
byte retrieveInterval(){
  // interval info starts from address 155
  return EEPROM.read(155);
}