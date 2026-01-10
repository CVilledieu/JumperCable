#include "ctx.h"

renderContext_t g_renderContext = {NULL, {0}, {0}, {0.10f, 0.18f, 0.24f, 1.0f}};

renderContext_t* init_RenderContext(void) {
    return &g_renderContext;
}