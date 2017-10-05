/*
powered by r@mkumar
this is spi slave program in which receive the message from the 
spi master through spi communication
*/

#include <SPI.h>
char buff[50];
volatile byte indx;
volatile boolean process;

void setup()
{
  Serial.begin(115200);
  pinMode(MISO,OUTPUT);
  SPCR |= _BV(SPE);
  indx = 0;
  process = false;
  SPI.attachInterrupt();
}
ISR (SPI_STC_vect)
{
  byte  c = SPDR;
  if(indx < sizeof buff)
  {
    buff [indx++] = c;
    if(c=='\r')
    process = true;
  }
}

void loop()
{
  if(process)
  {
    process = false;
    Serial.println(buff);
    indx =0;
  }
}
