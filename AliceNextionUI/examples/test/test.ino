#include <Nextion.h>

#include <AliceNextionUI.h>
#include <PageSplash.h>
#include <PageMain.h>
#include <PageMenu.h>
#include <PageTrim.h>
#include <PageChanSel.h>
#include <PageChanOpt.h>
#include <PageGeneralSett.h>

Nextion nex(Serial1);
AliceNextionUI ui(nex);

void setup()
{
	Serial.begin(9600);
	pinMode(13, OUTPUT);

  Serial1.begin(9600);
  nex.init();
  
	Serial.println("pages");
  Serial.println(ui.addPage(new PageSplash(&ui)));
	Serial.println(ui.addPage(new PageMain(&ui)));
	Serial.println(ui.addPage(new PageMenu(&ui)));
	Serial.println(ui.addPage(new PageTrim(&ui)));
	Serial.println(ui.addPage(new PageChanSel(&ui)));
	Serial.println(ui.addPage(new PageChanOpt(&ui)));
	Serial.println(ui.addPage(new PageGeneralSett(&ui)));
	
	Serial.println(ui.showPage(PG_SPLASH));
}

void loop()
{
  ui.poll();
}