
#include <SPI.h>
#include <mcp_can.h>

const int SPI_CS_PIN = 10;
MCP_CAN CAN(SPI_CS_PIN);  

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

    while (CAN_OK != CAN.begin(CAN_1000KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
}
uint8_t buf[2] ;
unsigned char len = 0;

void loop() {
  // put your main code here, to run repeatedly:

  if(CAN_MSGAVAIL == CAN.checkReceive())
  {
  
  uint32_t canId = CAN.getCanId();
  
  CAN.readMsgBuf(&len, buf);// reading data from CAN.
  Serial.print("Get data from ID: ");
  Serial.println(canId, HEX);
  Serial.print("len is =");
  Serial.println(len);

   for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i]);
            Serial.print("\t");
        }
        Serial.println();
  
  float a = buf[0]*100;
  float b = a + buf[1];
  float c = (b/100) ;
  Serial.print("temp is = ");
  Serial.println(c);
      
  delay(1000);

}}
