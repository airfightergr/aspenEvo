//
// Created by ilias on 10/2/23.
//

#ifndef DATAREFS_H
#define DATAREFS_H
// System includes
#include <string.h>
#include <stdio.h>

// X-Plane includes
#include "XPLMDataAccess.h"

#include <acfutils/log.h>
#include "acfutils/dr.h"

// functions
void aircraft_type();
void init_datarefs();
void init_datarefs_values();
void transfer_dref_values();
void destroy_datarefs();

extern char *acf_full_path;

static dr_t xpndr_page, xpndr_ident, xpndr_code, xpndr_ete_hrs, xpndr_ete_min, xpndr_ete_sec;
static dr_t custom_avionics_bezel;

static dr_t kas297_outer, kas297_inner, kas297_arm;
static dr_t ind_pitch_trim, ind_oat;


// x-plane drefs
static dr_t acf_path, livery_path;
static dr_t instr_brit_manual, instr_brit_auto, cockpit_lit_level_r, cockpit_lit_level_g, cockpit_lit_level_b, cockpit_lit_level_mean;

static dr_t AP_alt_dial, AP_alt_armed;
static dr_t plt_com_freq, plt_stby_com_freq, cplt_com_freq, plt_com1_tx;
static dr_t xp_ind_pitch_trim, xp_ind_oat;


#endif // DATAREFS_H
