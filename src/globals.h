// global.h

#ifndef GLOBALS_H
#define GLOBALS_H

#include <string.h>
#include "acfutils/log.h"
#include "acfutils/dr.h"
#include "acfutils/helpers.h"
#include "acfutils/sysmacros.h"

extern char* pluginPath;
extern char* pluginDirectory;
extern char* acf_type;
extern int acf_type_int;

void init_globals();
void cleanup_globals(void);

#endif // !GLOBALS_H
