/*
Dimensions (WxH)
bezel: 1333x352
screen: 761x160 - aspect ratio: 4.755:1
*/


#include "device.h"
#include "XPLMDisplay.h"
#include "acfutils/dr.h"
#include "acfutils/log.h"
#include <cstring>
#include <string>

XPLMCommandRef aspenEvo_pop = NULL;

XPLMAvionicsID aspenEvo_handle;

int aspenEvo_pop_handler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void *inRefcon);

GLuint aspenEvo_bezel = 0;
GLuint aspenEvo_back = 0;
// GLuint kap140_digit_font = 0;

// Variables
static double auto_brt[32];
static double man_brt[32];


// function to draw our textures full or part of them
void drawTexture_aspenEvo(GLuint textid, float c_x1, float c_y1, float c_x2, float c_y2, float x, float y, float width, float height) {

    GLuint textureID = textid;

    glBindTexture(GL_TEXTURE_2D, textureID);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // float fac = 1.0f;
    // glColor3f(1 * fac, 1 * fac, 1 * fac);
    // glColor3f(dr_getf(&cockpit_lit_level_b), dr_getf(&cockpit_lit_level_b), dr_getf(&cockpit_lit_level_b));
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
      glTexCoord2f(c_x1, c_y1); glVertex2f(x, y);
      glTexCoord2f(c_x1, c_y2); glVertex2f(x, y + height);
      glTexCoord2f(c_x2, c_y2); glVertex2f(x + width, y + height);
      glTexCoord2f(c_x2, c_y1); glVertex2f(x + width, y);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
}


// Draw the digits from the digitFont texture
void drawDigit_aspenEvo(GLuint textid, int num) {

    dr_getvf(&instr_brit_manual, man_brt, 0, 32);

    GLuint textureID = textid;

    float coord_x = num * 0.09375f;

    glBindTexture(GL_TEXTURE_2D, textureID);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor3f(man_brt[0], man_brt[0], man_brt[0]);
    // glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
      glTexCoord2f(coord_x, 0.90625f);              glVertex2f(0, 0);
      glTexCoord2f(coord_x, 1.0f);                  glVertex2f(0, 92);
      glTexCoord2f(coord_x + 0.09375f, 1.0f);       glVertex2f(92, 92);
      glTexCoord2f(coord_x + 0.09375f, 0.90625f);   glVertex2f(92, 0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
}


void aspenEvo_bezel_draw(float inAmbiantR, float inAmbiantG, float inAmbiantB, void *inRefcon) {

    XPLMSetGraphicsState(
                           0 /* no fog */,
                           0 /* no texture units */,
                           0 /* no lighting */,
                           0 /* no alpha testing */,
                           1 /* do alpha blend */,
                           1 /* do depth testing */,
                           0 /* do depth writing */
      );

      glDisable(GL_TEXTURE_2D);
      glDisable(GL_CULL_FACE);
      drawTexture_aspenEvo(aspenEvo_bezel, 0, 0, 1, 1, 0, 0, 500, 996);
}


void aspenEvo_screen_draw(void *inRefcon) {

    XPLMSetGraphicsState(
                           0 /* no fog */,
                           0 /* no texture units */,
                           0 /* no lighting */,
                           1 /* no alpha testing */,
                           1 /* do alpha blend */,
                           0 /* do depth testing */,
                           0 /* do depth writing */
      );

      glDisable(GL_TEXTURE_2D);
      glDisable(GL_CULL_FACE);

      // Draw background
      drawTexture_aspenEvo(aspenEvo_back, 0, 0, 1.0, 1.0, 0, 0, 405, 759);
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
    aspenEvo.drawOnDemand = false;
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

    // load textures
    std::string bezel_image = pluginDirectory + "resources/images/aspenEvo_bezel.png";
    aspenEvo_bezel = loadSingleTexture(bezel_image.c_str());
    logMsg("Bezel path: %s", bezel_image.c_str());

    std::string display_back = pluginDirectory + "resources/images/aspenEvo_display.png";
    aspenEvo_back = loadSingleTexture(display_back.c_str());
    logMsg("Display back path: %s", display_back.c_str());

    // std::string digitsFont = pluginDirectory + "resources/images/avionics/digitalFonts.png";
    // ctl22c_digit_font = loadSingleTexture(digitsFont.c_str());

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
