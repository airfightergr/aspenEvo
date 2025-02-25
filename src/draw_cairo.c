
#include "draw_cairo.h"



#define PANEL_X 0
#define PANEL_Y 0
#define DISPLAY_FPS 20
#define DISPLAY_W 160
#define DISPLAY_H 761

static mt_cairo_render_t* render = NULL;

void display_cairo_draw(struct _cairo_t* cr, unsigned w, unsigned h, void* data) {
        UNUSED(data);


}


int loop_cairo_draw(XPLMDrawingPhase phase, int is_before, void* refcon) {
        UNUSED(phase);
        UNUSED(is_before);
        UNUSED(refcon);

        vect2_t panel_location = VECT2(PANEL_X, PANEL_Y);

        mt_cairo_render_draw(render, panel_location, VECT2(DISPLAY_W, DISPLAY_H));
        return 1;
}

void init_cairo_draw() {
        glewInit();
        mt_cairo_render_glob_init(false);
}


void enable_cairo_draw() {
        render = mt_cairo_render_init(DISPLAY_W, DISPLAY_H, DISPLAY_FPS, nullptr, display_cairo_draw, nullptr, nullptr);

        XPLMRegisterDrawCallback(loop_cairo_draw, xplm_Phase_Gauges, 1, nullptr);
}


void disable_cairo_draw() {
        XPLMUnregisterDrawCallback(loop_cairo_draw, xplm_Phase_Gauges, 1, NULL);
        mt_cairo_render_fini(render);
        render = NULL;

}
