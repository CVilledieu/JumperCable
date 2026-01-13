#ifndef __CTX_H__
#define __CTX_H__

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

#include "nuklear_glfw_gl3.h"

#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024


extern struct nk_glfw glfw;
extern struct nk_context *ctx;
extern struct nk_colorf bgColor;


// Pre rendering setup functions
void initRenderContext(void);
void initComponents(void);

// Main rendering functions
void clearBuffer(void);
void setInputListeners(void);
void renderComponents(void);

// Post rendering cleanup functions
void endApp(void);


#endif