#include "ctx.h"

renderContext_t g_renderContext = {0};

renderContext_t* initRenderContext(void) {
    g_renderContext.window = NULL;
    g_renderContext.glfw = (struct nk_glfw){0};
    g_renderContext.ctx = (struct nk_context){0};
    g_renderContext.bgColor = (struct nk_colorf){0.10f, 0.18f, 0.24f, 1.0f};
    g_renderContext.widgetCount = 0;
    return &g_renderContext;
}

void clearBuffer(void){
    glClearColor(g_renderContext.bgColor.r, g_renderContext.bgColor.g, g_renderContext.bgColor.b, g_renderContext.bgColor.a);
    glClear(GL_COLOR_BUFFER_BIT);
}


void endApp(void) {
    nk_glfw3_shutdown(&g_renderContext.glfw);
    glfwDestroyWindow(g_renderContext.window);
    glfwTerminate();
}