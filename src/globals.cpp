#include "globals.h"
#include "XPLMPlugin.h"
#include "XPLMUtilities.h"
#include "datarefs.h"

#include <cstddef>
#include <cstring>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::string pluginPath;
std::string pluginDirectory;
std::string subfolder;
std::string acf_type;
int acf_type_int;


void logFunc(std::string string) {

  std::string logMessage = "[RW SA227]: " + string + "\n";
  XPLMDebugString(logMessage.c_str());

}


void init_globals() {

  // get the full plugin path
  char plg_buff[1024];
  XPLMGetPluginInfo(XPLMGetMyID(), NULL, plg_buff, NULL, NULL);
  pluginPath = plg_buff;

  // logFunc(pluginPath);
  logMsg("pluginPath: \"%s\"", pluginPath.c_str());

  // find the last slash and get the plugin path up to last slash '/'
  // size_t lastSlashPos = std::max(pluginPath.find_last_of('/'), pluginPath.find_last_of('\\'));
    size_t lastSlashPos = pluginPath.find_last_of('/');
    logMsg("Last slash position: %zu", lastSlashPos);

  // Find the second-to-last backslash (end of kap140_plugin)
    size_t secondLastBackslashPos = pluginPath.find_last_of('/', lastSlashPos - 1);
    logMsg("Second-to-last backslash position: %zu", secondLastBackslashPos);

  if (secondLastBackslashPos  != std::string::npos) {
    pluginDirectory = pluginPath.substr(0, secondLastBackslashPos  + 1);
    logMsg("pluginDirectory: %s", pluginDirectory.c_str());
  } else {
    pluginDirectory = pluginPath;
    logMsg("No slash found: %s", pluginDirectory.c_str());
  }



  // if (lastSlashPos != std::string::npos) {
  //   size_t secondLastSlashPos = pluginPath.find_last_of('/', lastSlashPos - 1);
  //   if (secondLastSlashPos != std::string::npos) {
  //     pluginDirectory = pluginPath.substr(0, secondLastSlashPos + 1);
  //   }
  //   else {
  //     pluginDirectory = pluginPath;
  //   }
  // }
  // else {
  //   pluginDirectory = pluginPath;
  // }

  // logFunc(pluginDirectory);
  


  // get acf name
  std::string inputString = acf_full_path; // get the full path
  size_t lastSlashPos2 = inputString.find_last_of('/'); //find the pos of the last slash
  std::string acf_name = inputString.substr(lastSlashPos2 + 1);

  const int lgth = acf_name.length();
  char *acf_name_ch = new char[lgth + 1];
  strcpy(acf_name_ch, acf_name.c_str());

  if (strcmp(acf_name_ch, "SA227_Passenger.acf") == 0) {
    acf_type = "Passenger";
    acf_type_int = 0;
  }
  else if (strcmp(acf_name_ch, "SA227_Freight.acf") == 0) {
    acf_type = "Freight";
    acf_type_int = 1;
  }

  logFunc(acf_type.c_str());

}
