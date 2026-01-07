#include "ui.h"
#include <stdio.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT

#include "nuklear.h"

void exampleGUI(struct nk_context *ctx, struct nk_colorf *bg){
    if (nk_begin(ctx, "Demo", nk_rect(50, 50, 300, 400), NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE)) {
        enum {EASY, HARD};
        static int op = EASY;
        static int property = 20;
        static float slider_value = 0.5f;
        
        nk_layout_row_static(ctx, 30, 80, 1);
        if (nk_button_label(ctx, "Button"))
            fprintf(stdout, "Button pressed!\n");

        nk_layout_row_dynamic(ctx, 30, 2);
        if (nk_option_label(ctx, "Easy", op == EASY)) op = EASY;
        if (nk_option_label(ctx, "Hard", op == HARD)) op = HARD;

        nk_layout_row_dynamic(ctx, 25, 1);
        nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);

        nk_layout_row_dynamic(ctx, 20, 1);
        nk_label(ctx, "Slider:", NK_TEXT_LEFT);
        nk_layout_row_dynamic(ctx, 25, 1);
        nk_slider_float(ctx, 0, &slider_value, 1.0f, 0.01f);

        nk_layout_row_dynamic(ctx, 20, 1);
        nk_labelf(ctx, NK_TEXT_LEFT, "Value: %.2f", slider_value);
        
        nk_layout_row_dynamic(ctx, 30, 1);
        bg->r = nk_propertyf(ctx, "#R:", 0, bg->r, 1.0f, 0.01f, 0.005f);
        bg->g = nk_propertyf(ctx, "#G:", 0, bg->g, 1.0f, 0.01f, 0.005f);
        bg->b = nk_propertyf(ctx, "#B:", 0, bg->b, 1.0f, 0.01f, 0.005f);
    }

    nk_end(ctx);
}

void exampleSecondWinodw(struct nk_context *ctx){
    if (nk_begin(ctx, "Tools", nk_rect(400, 50, 250, 200), NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_TITLE)) {
        nk_layout_row_dynamic(ctx, 25, 1);
        nk_label(ctx, "JumperCable Utilities", NK_TEXT_CENTERED);
        
        nk_layout_row_dynamic(ctx, 30, 1);
        if (nk_button_label(ctx, "Tool 1"))
            fprintf(stdout, "Tool 1 activated\n");
        if (nk_button_label(ctx, "Tool 2"))
            fprintf(stdout, "Tool 2 activated\n");
        if (nk_button_label(ctx, "Tool 3"))
            fprintf(stdout, "Tool 3 activated\n");
    }
    nk_end(ctx);
}
