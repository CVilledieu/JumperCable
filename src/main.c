#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "nuklear.h"
#include "nuklear_glfw_gl3.h"

#include "ui/ui.h"
#include "ui/widgets.h"
#include "window/win.h"


int main(void){
    renderContext_t* renderContext = newRenderContext();
    renderContext->window = newWindowCtx();

    while(!glfwWindowShouldClose(renderContext->window)){
        clearBuffer();
        glfwPollEvents();
        nk_glfw3_new_frame(&renderContext->glfw);

        drawWidgets();

        /* Render nuklear */
        nk_glfw3_render(&renderContext->glfw, NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);
        glfwSwapBuffers(renderContext->window);
    }

    endApp();
}