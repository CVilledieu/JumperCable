#include "ui.h"

renderContext_t renderContext = {NULL, {0}, {0}, {0.10f, 0.18f, 0.24f, 1.0f}};

#define MAX_WIDGETS 10
static int widgetCount = 0;
static struct Widget* WidgetList[MAX_WIDGETS] = {0};

void initUi(struct nk_glfw *glfwPtr, GLFWwindow *windowPtr) {
    renderContext->ctx = nk_glfw3_init(glfwPtr, windowPtr, NK_GLFW3_INSTALL_CALLBACKS);
    struct nk_font_atlas *atlas;
    nk_glfw3_font_stash_begin(glfwPtr, &atlas);
    nk_glfw3_font_stash_end(glfwPtr);
    
    initWidgets(renderContext);
}


void drawUI(void){
    struct nk_context *ctx = renderContext->ctx;
    struct nk_colorf bg = *renderContext->bgColor;
    
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

int addWidget(Widget* widget) {
    if (widgetCount < MAX_WIDGETS) {
        for (int i = 0; i < MAX_WIDGETS; i++) {
            if (WidgetList[i] == NULL) {
                WidgetList[i] = widget;
                widgetCount++;
                return i;
            }
        }
    }
    fprintf(stderr, "No available widget slots\n");
    return -1;
}