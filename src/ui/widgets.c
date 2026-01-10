#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "widgets.h"
#include "ui.h"

// Forward declaration of test layout function for demo widget
void testLayout(void);
void settingsWidget(struct nk_context *ctx, struct nk_colorf *bgColor);


void initWidgets(renderContext_t* renderContext) {

    // Initialize settings widget
    settingsWidget(renderContext);

}

void drawWidget(renderContext_t* ctx, Widget* widget) {
    if (nk_begin(ctx, widget->title, widget->bounds, widget->flags)) {
        // Widget content goes here
            widget->layout();
        }
    nk_end(ctx);
}

Widget* newWidget(const char* title, struct nk_rect bounds, nk_flags flags) {
    Widget* widget = (Widget*)malloc(sizeof(Widget));
    widget->id = addWidget(widget);
    if(widget->id == -1) {
        free(widget);
        return;
    }

    strncpy(widget->title, title, MAX_TITLE_LENGTH - 1);
    widget->title[MAX_TITLE_LENGTH - 1] = '\0';

    widget->bounds = bounds;
    widget->flags = flags;
    return widget;
}

void setLayout(Widget* widget, void (*layout)(void)) {
    if (widget) {
        widget->layout = layout;
    }
}

// void testLayout(void){
//     enum {EASY, HARD};
//     static int op = EASY;
//     static int property = 20;
//     static float slider_value = 0.5f;
    
//     nk_layout_row_static(ctx, 30, 80, 1);
//     if (nk_button_label(ctx, "Button"))
//         fprintf(stdout, "Button pressed!\n");
    
//     nk_layout_row_dynamic(ctx, 30, 2);
//     if (nk_option_label(ctx, "Easy", op == EASY)) op = EASY;
//     if (nk_option_label(ctx, "Hard", op == HARD)) op = HARD;

//     nk_layout_row_dynamic(ctx, 25, 1);
//     nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);

//     nk_layout_row_dynamic(ctx, 20, 1);
//     nk_label(ctx, "Slider:", NK_TEXT_LEFT);
//     nk_layout_row_dynamic(ctx, 25, 1);
//     nk_slider_float(ctx, 0, &slider_value, 1.0f, 0.01f);

//     nk_layout_row_dynamic(ctx, 20, 1);
//     nk_labelf(ctx, NK_TEXT_LEFT, "Value: %.2f", slider_value);
    
//     nk_layout_row_dynamic(ctx, 30, 1);
//     bg.r = nk_propertyf(ctx, "#R:", 0, bg.r, 1.0f, 0.01f, 0.005f);
//     bg.g = nk_propertyf(ctx, "#G:", 0, bg.g, 1.0f, 0.01f, 0.005f);
//     bg.b = nk_propertyf(ctx, "#B:", 0, bg.b, 1.0f, 0.01f, 0.005f);


// }

void settingsLayout(struct nk_context *ctx, struct nk_colorf *bgColor) {

    nk_layout_row_static(ctx, 30, 80, 1);
    if (nk_button_label(ctx, "Button"))
        fprintf(stdout, "Button pressed!\n");
}

void settingsWidget(struct nk_context *ctx, struct nk_colorf *bgColor) {
    float width = 300;
    float height = 400;
    float xPos = DEFAULT_WINDOW_WIDTH - width - HORIZONTAL_PADDING;
    float yPos = VERTICAL_PADDING;
    struct nk_rect bounds = nk_rect(xPos, yPos, width, height);
    nk_flags flags = DEFAULT_FLAGS;

    Widget* widget = newWidget("Settings", bounds, flags);

    setLayout(widget, settingsLayout);
}