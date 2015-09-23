#ifndef __ALICENEXTIONUI_ALICENEXTIONUI
#define __ALICENEXTIONUI_ALICENEXTIONUI

#include <Nextion.h>

enum AliceNextionUIPageID
{
  PG_SPLASH       = 0,
  PG_MAIN         = 1,
  PG_MENU         = 2,
  PG_TRIM         = 3,
  PG_CHANSEL      = 4,
  PG_CHANOPT      = 5,
  PG_GENERALSETT  = 6,
  
  PG_NULL
};

class IAliceNextionUIPage;

class AliceNextionUI
{
public:
  AliceNextionUI(Nextion &nex);
  
  bool addPage(IAliceNextionUIPage *page);
  IAliceNextionUIPage *getPage(AliceNextionUIPageID id);
  bool showPage(AliceNextionUIPageID id);
  
  void update();
  void poll();
  
  Nextion &nextion();

private:
  Nextion &m_nextion;
  IAliceNextionUIPage *m_pages[PG_NULL];
};

#endif