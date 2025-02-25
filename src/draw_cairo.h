#ifndef CAIRO_H
#define CAIRO_H

#include "acfutils/glew.h"
#include "acfutils/log.h"


#include "acfutils/mt_cairo_render.h"
#include <XPLMUtilities.h>
#include <XPLMGraphics.h>
#include <XPLMDataAccess.h>
#include <XPLMDisplay.h>
#include "acfutils/core.h"
#include "acfutils/geom.h"


#include "acfutils/assert.h"
#include <acfutils/core.h>
#include <acfutils/helpers.h>
#include <acfutils/sysmacros.h>

extern void init_cairo_draw();
extern void enable_cairo_draw();
extern void disable_cairo_draw();
extern void display_cairo_draw(cairo* cr, unsigned w, unsigned h, void* data);

#endif  // CAIRO_H
