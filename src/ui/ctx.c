#define NK_IMPLEMENTATION
#define NK_GLFW_GL3_IMPLEMENTATION

#include "ctx.h"
#include "window/win.h"
#include "components.h"

struct nk_glfw glfw = {0};
struct nk_context *ctx = NULL;
struct nk_colorf bgColor = {0};

void initRenderContext(void) {
    nk_glfw3_init(&glfw, mainWindow, NK_GLFW3_INSTALL_CALLBACKS);
    struct nk_font_atlas *atlas;
    nk_glfw3_font_stash_begin(&glfw, &atlas);
    nk_glfw3_font_stash_end(&glfw);
    ctx = &glfw.ctx;
    bgColor = (struct nk_colorf){0.10f, 0.18f, 0.24f, 1.0f};
}


void clearBuffer(void){
    glClearColor(bgColor.r, bgColor.g, bgColor.b, bgColor.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void setInputListeners(void) {
    glfwPollEvents();
    nk_glfw3_new_frame(&glfw);
}

void renderComponents(void) {
    settingsComponent();

    nk_glfw3_render(&glfw, NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);
}



void endApp(void) {
    nk_glfw3_shutdown(&glfw);
    glfwDestroyWindow(glfw.win);
    glfwTerminate();
}