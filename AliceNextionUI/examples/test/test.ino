#include <SoftwareSerial.h>
#include <Nextion.h>

#include <AliceNextionUI.h>
#include <PageSplash.h>

SoftwareSerial nextionSerial(10, 11); // RX, TX
Nextion nex(nextionSerial);
AliceNextionUI ui(nex);

void setup()
{
	Serial.begin(9600);
	pinMode(13, OUTPUT);

  nextionSerial.begin(9600);
  nex.init();
  
  ui.addPage(new PageSplash(&ui));
}

void loop()
{
  ui.poll();
}