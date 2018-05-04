# relay-board
Arduino example code for 16 channels i2c relay board.

The code is for relay board testing purpose. 

Attention should be paid to:

MCP_Write(i, 0x00, 0b00000000);
0x00 is I/O DIRECTION REGISTER for MCP port A - When a bit is set, the corresponding pin becomes an input. When a bit is clear, the corresponding pin becomes an output.

MCP_Write(i, 0x12, 0b00000000);
Set all pins of PORTA to OFF.

MCP_Write(i, 0x01, 0b00000000)
0x01 is I/O DIRECTION REGISTER for MCP port B - When a bit is set, the corresponding pin becomes an input. When a bit is clear, the corresponding pin becomes an output.

MCP_Write(i, 0x13, 0b00000000);
Set all pins of PORTB to OFF.

WriteRelays(7,relaydata);
7 is i2c board address  - depends on how dip switch is set.
