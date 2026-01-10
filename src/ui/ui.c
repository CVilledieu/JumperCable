#include "ui.h"
#include "ctx.h"

void initUi(struct nk_glfw *glfwPtr, GLFWwindow *windowPtr) {
    renderContext.ctx = *nk_glfw3_init(glfwPtr, windowPtr, NK_GLFW3_INSTALL_CALLBACKS);
    struct nk_font_atlas *atlas;
    nk_glfw3_font_stash_begin(glfwPtr, &atlas);
    nk_glfw3_font_stash_end(glfwPtr);
    
    initWidgets(renderContext);
}


void drawUI(void){
    struct nk_context *ctx = &renderContext.ctx;
    struct nk_colorf bg = renderContext.bgColor;

    for (int i = 0; i < MAX_WIDGETS; i++) {
        Widget* widget = WidgetList[i];

        if (!widget) continue;

        drawWidget(ctx, widget);
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
