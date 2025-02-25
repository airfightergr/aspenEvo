#include "globals.h"
#include "XPLMPlugin.h"
#include "XPLMUtilities.h"
#include "acfutils/log.h"
#include "datarefs.h"

#include <stdlib.h>
#include <string.h>
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

char* pluginPath;
char* pluginDirectory;
char* subfolder;
char* acf_type;
int acf_type_int;

void init_globals() {

  // get the full plugin path
  char plg_buff[1024];
  XPLMGetPluginInfo(XPLMGetMyID(), NULL, plg_buff, NULL, NULL);
  pluginPath = strdup(plg_buff);        // allocate memory for pluginPath and copy plg_buff

  logMsg("pluginPath: \"%s\"", pluginPath);

  // find the last slash and get the plugin path up to last slash '/'
  char* lastSlashPos = strrchr(pluginPath, '/');
  if (lastSlashPos != NULL) {
          *lastSlashPos = '\0'; // null-terminate at the last slash to get the directory
          pluginDirectory = strdup(pluginPath); // allocate memory for pluginDirectory and copy pluginPath
          *lastSlashPos = '/';  // restore the slash for consistency
          logMsg("Plugin Directory: %s", pluginDirectory);
  } else {
          // handle case where no slash is found (unlikely for a plugin path)
          logMsg("No slash found in %s", pluginPath);
          pluginDirectory = strdup(pluginPath); // assuming pluginPath is the directory itself
  }

}


void cleanup_globals(void) {
        // free allocated memory
        if (pluginPath != NULL) {
                free(pluginPath);
                pluginPath = NULL;
        }
        if (pluginDirectory != NULL) {
                free(pluginDirectory);
                pluginDirectory = NULL;
        }
}
