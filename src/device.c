/*
Dimensions (WxH)
bezel: 1333x352
screen: 761x160 - aspect ratio: 4.755:1
*/


#include "device.h"
#include "XPLMDisplay.h"
#include "acfutils/dr.h"
#include "acfutils/log.h"
#include <string.h>

XPLMCommandRef aspenEvo_pop = NULL;
int aspenEvo_pop_handler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void *inRefcon);

XPLMAvionicsID aspenEvo_handle;


// Variables
static double auto_brt[32];
static double man_brt[32];


void aspenEvo_bezel_draw(float inAmbiantR, float inAmbiantG, float inAmbiantB, void *inRefcon) {

}


void aspenEvo_screen_draw(void *inRefcon) {


}


int aspenEvo_bezel_click_f(int x, int y, XPLMMouseStatus inMouse, void *inRefcon) {

  // if (inMouse == xplm_MouseDown) {
  //   logMsg("Bezel left clicked!");
  // }
    return 0;
}


int aspenEvo_bezel_rclick_f(int x, int y, XPLMMouseStatus inMouse, void *inRefcon) {
    // if (inMouse == xplm_MouseDown) {
    //   logMsg("Bezel right clicked!");
    // }
    return 0;
}


int aspenEvo_bezel_scroll_f(int x, int y, int wheel, int clicks, void *inRefcon) {

   return 1;
}


int aspenEvo_bezel_cursor_f(int x, int y, void *inRefcon) {
  return xplm_CursorDefault;
}


int aspenEvo_keyboard_f(char inKey, XPLMKeyFlags inFlags, char inVirtualKey, void *inRefcon, int losingFocus) {
    return 1;
}


float aspenEvo_britness_f(float inRheoValue, float inAmbiantBrightness, float inBusVoltRation, void *inRefcon) {
  dr_getvf(&instr_brit_auto, auto_brt, 0, 32);
  return auto_brt[2];
}


void aspenEvo_init() {

    dr_find(&instr_brit_auto, "sim/cockpit2/electrical/instrument_brightness_ratio_auto");
    dr_find(&instr_brit_manual, "sim/cockpit2/electrical/instrument_brightness_ratio_manual");
    // dr_find(&cockpit_lit_level_r, "sim/graphics/misc/cockpit_light_level_r");
    // dr_find(&cockpit_lit_level_g, "sim/graphics/misc/cockpit_light_level_g");
    // dr_find(&cockpit_lit_level_b, "sim/graphics/misc/cockpit_light_level_b");

    char deviceID[64];
    snprintf(deviceID, 64, "aspenEvo_e5");

    char deviceName[256];
    snprintf(deviceName, 256, "AspenEvo Avionics");

    XPLMCreateAvionics_t aspenEvo;
    aspenEvo.structSize = sizeof(aspenEvo);
    aspenEvo.screenWidth = 405;
    aspenEvo.screenHeight = 759;
    aspenEvo.bezelWidth = 500;
    aspenEvo.bezelHeight = 996;
    aspenEvo.screenOffsetX = 32;
    aspenEvo.screenOffsetY = 150;
    aspenEvo.drawOnDemand = 0;
    aspenEvo.bezelDrawCallback = aspenEvo_bezel_draw;
    aspenEvo.drawCallback = aspenEvo_screen_draw;
    aspenEvo.bezelClickCallback = &aspenEvo_bezel_click_f;
    aspenEvo.bezelRightClickCallback = &aspenEvo_bezel_rclick_f;
    aspenEvo.bezelScrollCallback = &aspenEvo_bezel_scroll_f;
    aspenEvo.bezelCursorCallback = &aspenEvo_bezel_cursor_f;
    aspenEvo.screenTouchCallback = NULL;
    aspenEvo.screenRightTouchCallback = NULL;
    aspenEvo.screenScrollCallback = NULL;
    aspenEvo.screenCursorCallback = NULL;
    aspenEvo.keyboardCallback = aspenEvo_keyboard_f;
    aspenEvo.brightnessCallback = aspenEvo_britness_f;
    aspenEvo.deviceID = deviceID;
    aspenEvo.deviceName = deviceName;
    aspenEvo_handle = XPLMCreateAvionicsEx(&aspenEvo);

    aspenEvo_pop = XPLMCreateCommand("itxd/aspenEvo/cmd/avionics/aspenEvo/pop_out", "Pop Out AspenEvo");

    XPLMRegisterCommandHandler(aspenEvo_pop, aspenEvo_pop_handler, 1, (void *)0);

}


int aspenEvo_pop_handler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void *inRefcon) {

  if (XPLMIsAvionicsPopupVisible(aspenEvo_handle) == 0) {
      if (inPhase == 0) {
          XPLMSetAvionicsPopupVisible(aspenEvo_handle, 1);
    }
  }
  else{
      if (inPhase == 0) {
        XPLMSetAvionicsPopupVisible(aspenEvo_handle, 0);
      }
    }

  return 0;
}


void aspenEvo_destroy() {
  XPLMDestroyAvionics(aspenEvo_handle);
}
