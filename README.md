# canwithtemp
this is used for transmitting temperature over CAN bus
cansend is cod to send the temperature sensor data. 
we use Arduino nano in the transmitter side and Arduino Mega i the receiver side. 

The temperature sensor used is MAX6675. CAN to SPI module is MCP6515
pin connections to nano are:
    NANO  ------>  CAN              NANO  ----->  SENSOR
    10    ------>  CS                12   ----->   SD
    11    ------>  SI                 9  ------>   CS
    12    ------>  SO                13  ------>   SCK
    13    ------>  SCK
    
The second CAN module is connected to Mega. 
