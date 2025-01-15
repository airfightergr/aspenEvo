/*
KAP140 Autopilot plugin for X-Plane
Copyright (c) 2024 - Ilias Tselios
*/

#include "main.h"
#include "device.h"
#include "globals.h"

#if IBM
#include <windows.h>
#endif
#if LIN
#include <GL/gl.h>
#endif
#if __GNUC__ && APL
#include <OpenGL/gl.h>
#endif
#if __GNUC__ && IBM
#include <GL/gl.h>
#endif


char PLUGIN_VER[] = "0.0.1";


// Plugin Init
PLUGIN_API int XPluginStart( char * outName, char * outSig, char * outDesc ) {

  XPLMEnableFeature("XPLM_USE_NATIVE_PATHS", 1);
  XPLMEnableFeature("XPLM_WANTS_DATAREF_NOTIFICATION", 1);

// plugin info
	strcpy(outName, "ASPEN_EVOLUTION");
	strcpy(outSig, "itxd.plugins.aspenEvo");
	strcpy(outDesc, "Aspen Evolution Avionics Plugin");

    log_init(XPLMDebugString, "[AspenEvo]: ");
    logMsg("Aspen Evolution Avionics plugin: %s", PLUGIN_VER);

    init_globals();
    aspenEvo_init();

    return 1;
}


PLUGIN_API int XPluginEnable(void) {
    return 1;
}



PLUGIN_API void XPluginDisable(void) {
    aspenEvo_destroy();
}


PLUGIN_API void XPluginStop(void) {
	aspenEvo_destroy();
}


PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFrom, long inMsg, void * inParam) {


}
