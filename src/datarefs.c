/*
C23 plugin for X-Plane
Ilias Tselios. All rights reserved. 2023
*/

#include "datarefs.h"
#include "XPLMDataAccess.h"
#include "acfutils/dr.h"
#include "acfutils/log.h"
#include "acfutils/types.h"
#include "globals.h"
#include <string.h>


// init datarefs
void init_datarefs(void) {

  // create datarefs
  dr_create_i(&xpndr_page, (int *)&xpndr_page, B_TRUE, "rw/sa227/avionics/gtx327/page");
  dr_create_i(&custom_avionics_bezel, (int *)&custom_avionics_bezel, B_TRUE, "rw/sa227/avionics/gtx327/custom_avionics_bezel");
  // kas297
  dr_create_i(&kas297_arm, (int *)&kas297_arm, B_TRUE, "rw/sa227/buttons/ap_alt_sel_arm");
  dr_create_f(&kas297_inner, (float *)&kas297_inner, B_TRUE, "rw/sa227/knobs/ap_alt_sel_inner");
  dr_create_f(&kas297_outer, (float *)&kas297_outer, B_TRUE, "rw/sa227/knobs/ap_alt_sel_outer");

  dr_create_f(&cockpit_lit_level_mean, (float *)&cockpit_lit_level_mean, B_TRUE, "rw/sa227/graphics/cockpit_lit_level_mean");

  // INDICATORS
  dr_create_f(&ind_pitch_trim, (float *)&ind_pitch_trim, B_TRUE, "rw/sa227/instruments/pitch_trim");
  dr_create_f(&ind_oat, (float *)&ind_oat, B_TRUE, "rw/sa227/instruments/oat_C");


  // find datarefs
  dr_find(&acf_path, "sim/aircraft/view/acf_relative_path");
  dr_find(&livery_path, "sim/aircraft/view/acf_livery_path");
  dr_find(&xpndr_code, "sim/cockpit2/radios/actuators/transponder_code");
  dr_find(&xpndr_ident, "sim/cockpit2/radios/indicators/transponder_id");
  dr_find(&xpndr_ete_hrs, "sim/cockpit2/clock_timer/elapsed_timer_hours");
  dr_find(&xpndr_ete_min, "sim/cockpit2/clock_timer/elapsed_timer_minutes");
  dr_find(&xpndr_ete_sec, "sim/cockpit2/clock_timer/elapsed_timer_seconds");
  dr_find(&instr_brit_manual, "sim/cockpit2/electrical/instrument_brightness_ratio_manual");
  dr_find(&instr_brit_auto, "sim/cockpit2/electrical/instrument_brightness_ratio_auto");
  dr_find(&cockpit_lit_level_r, "sim/graphics/misc/cockpit_light_level_r");
  dr_find(&cockpit_lit_level_g, "sim/graphics/misc/cockpit_light_level_g");
  dr_find(&cockpit_lit_level_b, "sim/graphics/misc/cockpit_light_level_b");

  dr_find(&AP_alt_dial, "sim/cockpit2/autopilot/altitude_dial_ft");
  dr_find(&AP_alt_armed, "sim/cockpit2/autopilot/altitude_hold_armed");
  dr_find(&plt_com_freq, "sim/cockpit2/radios/actuators/com1_frequency_hz_833");
  dr_find(&plt_stby_com_freq, "sim/cockpit2/radios/actuators/com1_standby_frequency_hz_833");
  dr_find(&cplt_com_freq, "sim/cockpit2/radios/actuators/com2_frequency_hz_833");
  dr_find(&plt_com1_tx, "sim/atc/com1_tx");
  dr_find(&xp_ind_pitch_trim, "sim/cockpit2/controls/elevator_trim");
  dr_find(&xp_ind_oat, "sim/cockpit2/temperature/outside_air_temp_degc");


}

  static char acf_dir_path[512] = "";
  char* acf_full_path;

  void init_datarefs_values() {
  if (!dr_find(&xpndr_page, "rw/sa227/avionics/gtx327/page")) {
  }
  else {
  dr_seti(&xpndr_page, 0);
  }

  dr_seti(&xpndr_code, 1200);

  dr_seti(&custom_avionics_bezel, 0);

  dr_seti(&cockpit_lit_level_mean, (dr_getf(&cockpit_lit_level_r) + dr_getf(&cockpit_lit_level_g) + dr_getf(&cockpit_lit_level_b)) / 3.0f);

  // kas297
  dr_setf(&kas297_arm, 0);
  dr_setf(&kas297_inner, 0);
  dr_setf(&kas297_outer, 0);

  dr_gets(&acf_path, acf_dir_path, sizeof(acf_dir_path));

  logMsg("Aircraft Path: %s", acf_dir_path);

  acf_full_path = acf_dir_path;

  logMsg("acf_full_path: %s", acf_full_path);
}


// Transfer directly dref values from XP to custom
void transfer_dref_values() {

    // Pitch trim
    if (dr_getf(&xp_ind_pitch_trim) < 0) {
        dr_setf(&ind_pitch_trim, 0.5 + (dr_getf(&xp_ind_pitch_trim) / 2 ));
    } else {
        dr_setf(&ind_pitch_trim, 0.5 + (dr_getf(&xp_ind_pitch_trim) / 2 ));
    }

    dr_setf(&ind_oat, dr_getf(&xp_ind_oat));

}


void destroy_datarefs() {

  dr_delete(&xpndr_page);
  dr_delete(&custom_avionics_bezel);

  // kas297
  dr_delete(&kas297_arm);
  dr_delete(&kas297_inner);
  dr_delete(&kas297_outer);
  dr_delete(&cockpit_lit_level_mean);
  dr_delete(&ind_pitch_trim);

  dr_delete(&acf_path);
  dr_delete(&livery_path);
  dr_delete(&xpndr_ident);
  dr_delete(&xpndr_code);
  dr_delete(&xpndr_ete_hrs);
  dr_delete(&xpndr_ete_min);
  dr_delete(&xpndr_ete_sec);
  dr_delete(&instr_brit_manual);
  dr_delete(&instr_brit_auto);
  dr_delete(&cockpit_lit_level_r);
  dr_delete(&cockpit_lit_level_g);
  dr_delete(&cockpit_lit_level_b);
  dr_delete(&AP_alt_dial);
  dr_delete(&AP_alt_armed);
  dr_delete(&plt_com_freq);
  dr_delete(&plt_stby_com_freq);
  dr_delete(&cplt_com_freq);
  dr_delete(&plt_com1_tx);

}
