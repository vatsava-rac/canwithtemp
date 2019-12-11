#include <SPI.h>
#include <mcp_can.h>
#include <MAX6675.h>

#define CS_PIN 9          //pin for temp sensor
MAX6675 tcouple(CS_PIN);
const int spiCSPin = 10;   //pi for CAN module


MCP_CAN CAN(spiCSPin);

void setup()
{
    Serial.begin(9600);
    pinMode (CS_PIN, OUTPUT);  // making both the CS pins as output pins
    pinMode (spiCSPin, OUTPUT);
    
    Serial.println("Temp sensor");
    
    while (CAN_OK != CAN.begin(CAN_1000KBPS))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    Serial.println("CAN BUS Shield Init OK!");
}

uint8_t cel[2] = { 0, 0};
    
void loop()
{
  // SPI transmission happens only when the CS pin is low.
  // So, for reading temperature 
  digitalWrite(CS_PIN, LOW); // making CS pin of sensor low 
  digitalWrite(spiCSPin, HIGH); // making CS pin of CAN module high
  float celsius = tcouple.readTempC();
  Serial.print("T in C = ");
  Serial.println(celsius); // printing the temprature
    
  /* sending the temperature values as an array of size 2.
  First we multiply the temperature to hundred and to convert it froom floating point number to decimak number
  Then we divide with hundred to get first two digits. The remainder is found using % operator.
  The two elements are tramsmitted as an array */
  celsius = celsius*100;
  cel[0] = celsius/100;
  cel[1] = (int)celsius%100;
 
  // blocking the temperature sensor and using the CAN module for transmission
  digitalWrite(CS_PIN, HIGH);
  digitalWrite(spiCSPin, LOW);
  //Serial.println("Data sent !!!");
  CAN.sendMsgBuf(0x5DC, 1, 2, cel);
  delay(1000);
}
