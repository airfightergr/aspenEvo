// global.h

#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include "acfutils/log.h"
#include "acfutils/dr.h"
#include "acfutils/helpers.h"
#include "acfutils/sysmacros.h"

extern std::string pluginPath;
extern std::string pluginDirectory;
extern std::string acf_type;
extern int acf_type_int;

extern void logFunc(std::string);
void init_globals();

#endif // !GLOBALS_H
