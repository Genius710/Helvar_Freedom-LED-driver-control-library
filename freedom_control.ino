byte helvar_crc(byte mess[], int len)
{
  crc.reset();
  crc.setStartXOR(0xFF);
  crc.setPolynome(0x07);
  crc.add(mess, 2);
  //Serial.println(crc.getCRC(), HEX);
  return crc.getCRC();
  
}


void alive(byte payload)
{
  Serial.println("alive:");
  byte command = 0x01;
  
  Serial2.write(command);
  Serial2.write(payload);
  byte mess[3];
  mess[0] = command;
  mess[1] = payload;
  Serial2.write(helvar_crc(mess,2));
}

void query_protocol_version()
{
  Serial.println("query protocol version:");
  //byte command = 0x01;
  
  Serial2.write(0x02);
  Serial2.write(0x00);
  Serial2.write(0xFD);

    delay(55);
  while (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
  while (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.println(Serial2.read(),HEX);   // read it and send it out Serial (USB)
  }
}

void query_physical_minimum_level()
{
  Serial.println("query physical minimum level:");
  Serial2.write(0x03);
  Serial2.write(0x00);
  Serial2.write(0xE8);

    delay(55);
  while (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
  while (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.println(Serial2.read(),HEX);   // read it and send it out Serial (USB)
  }
}


void set_light_level(byte payload)
{
  Serial.print("set light level  ");
  Serial.print((int) payload);
  Serial.println("  :");
  byte command = 0x04;
  byte mess[3];
  mess[0] = command;
  mess[1] = payload;
  /*
  Serial2.write(command);
  Serial2.write(payload);
  Serial2.write(helvar_crc(mess,2));
  */

  byte tosend[4] ={command,payload,helvar_crc(mess,2)};
Serial2.write(tosend,3);

  delay(200);
  while (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
  while (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.print(Serial2.read(),HEX);   // read it and send it out Serial (USB)
  }
  Serial.println();
  Serial.println("set light level finished");
}



void set_light_level_fast(byte payload)
{
  //Serial.print("set light level  ");
  //Serial.print((int) payload);
  //Serial.println("  :");
  byte command = 0x04;
  byte mess[3];
  mess[0] = command;
  mess[1] = payload;
  /*
  Serial2.write(command);
  Serial2.write(payload);
  Serial2.write(helvar_crc(mess,2));
  */

  byte tosend[4] ={command,payload,helvar_crc(mess,2)};
Serial2.write(tosend,3);

/*  delay(200);
  while (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
  while (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.print(Serial2.read(),HEX);   // read it and send it out Serial (USB)
  }
  Serial.println();
  Serial.println("set light level finished");*/
}





void set_fade_time(byte payload)
{
  Serial.println("set fade time :");
  byte command = 0x05;
  byte mess[3];
  mess[0] = command;
  mess[1] = payload;
  Serial2.write(command);
  Serial2.write(payload);
  Serial2.write(helvar_crc(mess,2));


  delay(55);
  while (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
  while (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.println(Serial2.read(),HEX);   // read it and send it out Serial (USB)
  }
}


void query_light_level()
{
  Serial.println("query light level:");
  /*byte command = 0x04;
  byte mess[3];
  mess[0] = command;
  mess[1] = payload;*/
  Serial2.write(0x06);
  Serial2.write(0x00);
  Serial2.write(0xA9);


  delay(55);
  while (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
  while (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.println(Serial2.read(),BIN);   // read it and send it out Serial (USB)
  }
}


void query_fade_time()
{
  Serial.println("query fade time :");
  /*byte command = 0x04;
  byte mess[3];
  mess[0] = command;
  mess[1] = payload;*/
  byte command = 0x07;
  byte payload = 0x00;
  byte mess[3];
  mess[0] = command;
  mess[1] = payload;
  Serial2.write(command);
  Serial2.write(payload);
  Serial2.write(helvar_crc(mess,2));


  delay(55);
  while (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
  while (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.println(Serial2.read(),HEX);   // read it and send it out Serial (USB)
  }
}


void query_status()
{
  Serial.println("query status:");
  /*byte command = 0x04;
  byte mess[3];
  mess[0] = command;
  mess[1] = payload;*/
  byte command = 0x0A;
  byte payload = 0x00;
//  byte mess[3];
//  mess[0] = command;
 // mess[1] = payload;
  Serial2.write(command);
  Serial2.write(payload);
  Serial2.write(0x55);

byte b_array[10];
int counter = 0;
  delay(55);
  while (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
  while (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    b_array[counter] = Serial2.read(); 
   // Serial.println(b_array[counter],BIN);   // read it and send it out Serial (USB)
    counter++;
  }

if(bitRead(b_array[4],0) ) Serial.println("control gear failure");  
if(bitRead(b_array[4],1) ) Serial.println("lamp failure");  
if(bitRead(b_array[4],2) ) Serial.println("lamp on");  
if(bitRead(b_array[4],3) ) Serial.println("limit error");  
if(bitRead(b_array[4],4) ) Serial.println("fade running");
if(bitRead(b_array[4],5) ) Serial.println("reset state"); 
if(bitRead(b_array[4],6) ) Serial.println("short address is mask"); 
if(bitRead(b_array[4],7) ) Serial.println("power cycle seen is true"); 

}
