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
    pinMode (CS_PIN, OUTPUT);
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
  digitalWrite(CS_PIN, LOW);
  digitalWrite(spiCSPin, HIGH);
  float celsius = tcouple.readTempC();
  Serial.print("T in C = ");
  celsius = celsius*100;
  cel[0] = celsius/100;
  cel[1] = (int)celsius%100;
  Serial.println(celsius);
  
  Serial.println("tempe is ");

  
  digitalWrite(CS_PIN, HIGH);
  digitalWrite(spiCSPin, LOW);
  //Serial.println("Data sent !!!");
  CAN.sendMsgBuf(0x5EC, 0, 2, cel);
  delay(1000);
}
