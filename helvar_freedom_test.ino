//
//    FILE: CRC8_test.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//    DATE: 2021-01-20
//    (c) : MIT


#include "CRC8.h"
#include "CRC.h"



//byte tt[4];
CRC8 crc;




void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600);
  Serial.println(__FILE__);

query_light_level();
query_fade_time();
query_physical_minimum_level();
query_protocol_version();
query_status();



set_light_level(0x90);
set_fade_time(0b00000000);
  
}

byte light = 254;
void loop()
{
  set_light_level_fast(0x90);
  set_light_level_fast(0x00);
  set_light_level_fast(0x90);
  delay(1000);
  //set_light_level(0x00);
  //set_light_level(0xF0);
  //delay(500);
  //light-=50;
  //if (light < 50) light = 254;
  //query_status();
//delay(200);
}


// -- END OF FILE --
