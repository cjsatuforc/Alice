#include <SoftwareSerial.h>
#include <Nextion.h>

#include <AliceNextionUI.h>
#include <PageSplash.h>
#include <PageMain.h>
#include <PageMenu.h>

SoftwareSerial nextionSerial(10, 11); // RX, TX
Nextion nex(nextionSerial);
AliceNextionUI ui(nex);

void setup()
{
	Serial.begin(9600);
	pinMode(13, OUTPUT);

  nextionSerial.begin(9600);
  nex.init();
  
	Serial.println("pages");
  Serial.println(ui.addPage(new PageSplash(&ui)));
	Serial.println(ui.addPage(new PageMain(&ui)));
	Serial.println(ui.addPage(new PageMenu(&ui)));
	
	Serial.println(ui.showPage(PG_SPLASH));
}

void loop()
{
  ui.poll();
}