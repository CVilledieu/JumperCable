#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT


#include "nuklear.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "widgets.h"


static struct nk_context *ctx;
static struct nk_colorf bg = {0.10f, 0.18f, 0.24f, 1.0f};



#define MAX_WIDGETS 10
static int widgetCount = 0;
static struct Widget* WidgetList[MAX_WIDGETS] = {0};

// Main UI drawing function called from main draw loop
// iterates through WidgetList and draws each visible widget
// Widget content is defined by its layout function pointer
void drawWidgets(void){
    glClearColor(bg.r, bg.g, bg.b, bg.a);

    for (int i = 0; i < MAX_WIDGETS; i++) {
        Widget* widget = WidgetList[i];

        if (!widget) continue;

        if (nk_begin(ctx, widget->title, widget->bounds, widget->flags)) {
        // Widget content goes here
            widget->layout();
        }
        nk_end(ctx);
    }
}

int getNewWidgetId(void){
    if(widgetCount < MAX_WIDGETS) {
        for (int i = 0; i < MAX_WIDGETS; i++) {
            if (WidgetList[i] == NULL) {
                return i;
            }
        } 
    }
   
    fprintf(stderr, "No available widget slots\n");
    return -1;
}

void newWidget(const char* title, struct nk_rect bounds, nk_flags flags, void (*layout)(void)) {
    Widget* widget = (Widget*)malloc(sizeof(Widget));
    widget->id = getNewWidgetId();
    if(widget->id == -1) {
        free(widget);
        return;
    }

    strncpy(widget->title, title, MAX_TITLE_LENGTH - 1);
    widget->title[MAX_TITLE_LENGTH - 1] = '\0';

    widget->bounds = bounds;
    widget->flags = flags;
    widget->layout = layout;

    WidgetList[widget->id] = widget;
    widgetCount++;
}


// Forward declaration of test layout function for demo widget
void testLayout(void);
void settingsWidget(void);

// Initializes widgets and adds them to WidgetList for drawing
void initWidgets(struct nk_context *ctxPtr){
    ctx = ctxPtr;
    settingsWidget();
}

void settingsLayout(void){
    nk_layout_row_dynamic(ctx, 30, 1);
    nk_label(ctx, "Background Color:", NK_TEXT_LEFT);

    nk_layout_row_dynamic(ctx, 20, 2);
    if (nk_button_label(ctx, "Black"))
        bg = (struct nk_colorf){0.0f, 0.0f, 0.0f, 1.0f};
    if (nk_button_label(ctx, "Dark Blue"))
        bg = (struct nk_colorf){0.0f, 0.0f, 0.2f, 1.0f};
    if (nk_button_label(ctx, "White"))
        bg = (struct nk_colorf){1.0f, 1.0f, 1.0f, 1.0f};
    if (nk_button_label(ctx, "Default"))
        bg = (struct nk_colorf){0.10f, 0.18f, 0.24f, 1.0f};

}

void settingsWidget(void) {
    const char title[] = "Settings";
    struct nk_rect bounds = nk_rect(1000, 0, 200, 150);
    nk_flags flags = NK_WINDOW_BORDER | NK_WINDOW_TITLE | NK_WINDOW_SCALABLE | NK_WINDOW_MINIMIZABLE;
    newWidget("Settings", bounds, flags, settingsLayout);
}

void testLayout(void){
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
    bg.r = nk_propertyf(ctx, "#R:", 0, bg.r, 1.0f, 0.01f, 0.005f);
    bg.g = nk_propertyf(ctx, "#G:", 0, bg.g, 1.0f, 0.01f, 0.005f);
    bg.b = nk_propertyf(ctx, "#B:", 0, bg.b, 1.0f, 0.01f, 0.005f);


}