#include <Wire.h>  

void setup() {

  Wire.begin();
  SetupRelays();

}

void loop() {

  byte  relaydata; 

  relaydata = 0x01;

  for (byte i = 0; i < 7; i = i + 1) {

    WriteRelays(7,relaydata);   
    delay(100);  
    relaydata = relaydata << 1;
  }

  for (byte i = 7; i > 0; i = i - 1) {

    WriteRelays(7,relaydata);    
    delay(100);  
    relaydata = relaydata >> 1;
  }

}


void SetupRelays() {

  for (byte i = 0; i <= 7; i = i + 1) {
    MCP_Write(i, 0x00, 0b00000000);      
    MCP_Write(i, 0x12, 0b00000000);
    MCP_Write(i, 0x01, 0b00000000);     
    MCP_Write(i, 0x13, 0b00000000);     
  }
}

void WriteRelays(byte address, byte data) {

  MCP_Write(address, 0x12, data);
  MCP_Write(address, 0x13, data);

}

void MCP_Write(byte MCPaddress, byte MCPregister, byte MCPdata) {

  MCPaddress = MCPaddress + 0x20;    
  Wire.beginTransmission(MCPaddress);
  Wire.write(MCPregister);
  Wire.write(MCPdata);
  Wire.endTransmission();

}

