#ifndef __CTX_H__
#define __CTX_H__

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL3_IMPLEMENTATION
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT

#define DEFAULT_WINDOW_WIDTH 1200
#define DEFAULT_WINDOW_HEIGHT 800

#define HORIZONTAL_PADDING 20
#define VERTICAL_PADDING 20


#include "nuklear.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "nuklear_glfw_gl3.h"

extern renderContext_t g_renderContext;

typedef struct renderContext {
    GLFWwindow *window;
    struct nk_glfw glfw;
    struct nk_context ctx;
    struct nk_colorf bgColor;
} renderContext_t;

renderContext_t* init_RenderContext(void);

#endif