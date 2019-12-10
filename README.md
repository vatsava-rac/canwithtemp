# canwithtemp
this is used for transmitting temperature over CAN bus
cansend is cod to send the temperature sensor data. 
we use Arduino nano in the transmitter side and Arduino Mega i the receiver side. 

The temperature sensor used is MAX6675. CAN to SPI module is MCP6515
pin connections to nano are:

    NANO  ------>  CAN             
    10    ------>  CS                
    11    ------>  SI                 
    12    ------>  SO                
    13    ------>  SCK
    
    NANO  ----->  SENSOR
      9   ----->   CS  
     12   ----->   SD
     13  ------>   SCK
The second CAN module is connected to Mega:

      MEGA  ----->  CAN
      10    ----->  CS
      50    ----->  SO
      51    ----->  SI
      52    ----->  SCK


Libraries for the code can be found using the link
https://github.com/Seeed-Studio/CAN_BUS_Shield

In the code the transmission rate of CAN bus is written as 1000Kbps. But the transmission happens at only 500Kbps which is the desired speed.

![alt tag](https://drive.google.com/open?id=1uWspD_54pqEGKcUtw9hxNyizi-0vJney/pathtoimg.png "screenshot of the logic analyzer")
