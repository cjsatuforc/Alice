#include <inttypes.h>

#include <UniversalInput.h>
#include <UniversalButtons.h>
#include <U8glib.h>
#include <M2tk.h>

#include "SerialLog.h"
#include "IRadio.h"
#include "IChannel.h"
#include "UIManager.h"


IChannel channels[] = {
  IChannel("Test One", 0, 0, 1500, 2500)
};

#define LCD_D0_PIN 38
#define LCD_D1_PIN 41
#define LCD_D2_PIN 40
#define LCD_D3_PIN 37
#define LCD_D4_PIN 36
#define LCD_D5_PIN 35
#define LCD_D6_PIN 34
#define LCD_D7_PIN 33
#define LCD_EN_PIN 14
#define LCD_CS1_PIN 32
#define LCD_CS2_PIN 31
#define LCD_DI_PIN 30
#define LCD_RW_PIN 15

#define LCD_BL_PIN 4

U8GLIB_KS0108_128 glcd(
    LCD_D0_PIN, LCD_D1_PIN, LCD_D2_PIN, LCD_D3_PIN,
    LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN,
    LCD_EN_PIN,
    LCD_CS1_PIN, LCD_CS2_PIN,
    LCD_DI_PIN,
    LCD_RW_PIN
  );

UIManager ui(glcd);
UniversalButtons uiButtons;


void setup()
{
  setup_serial_logger();

  uiButtons.setDefaultButtonConfig(1, 1);

  uiButtons.addButton(BUTTON_LEFT, 47);
  uiButtons.addButton(BUTTON_UP, 49);
  uiButtons.addButton(BUTTON_DOWN, 45);
  uiButtons.addButton(BUTTON_RIGHT, 43);
  uiButtons.addButton(BUTTON_MENU_SELECT, 44);  // F1
  uiButtons.addButton(BUTTON_CHANNELS, 48);     // F2
  uiButtons.addButton(BUTTON_MACROS, 42);       // F3
  uiButtons.addButton(BUTTON_EXIT, 46);         // F4

  uiButtons.setStateChangeCallback(uiButtonHandle);

#ifdef GLCD_ROTATE_180
  glcd.setRot180();
#endif
}


void loop()
{
  uiButtons.poll();
}


void uiButtonHandle(buttonid_t id, uint8_t state)
{
  // Ignore button releases
  if(!state)
    return;

  ui.handleButtonPress((uibutton_t)id);
}
