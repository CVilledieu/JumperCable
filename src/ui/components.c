
#include "components.h"
#include "ctx.h"

void SettingsComponent(void){
    const char* title = "Settings";
    struct nk_rect bounds = {HORIZONTAL_PADDING, VERTICAL_PADDING, 300, 400};
    nk_flags flags = DEFAULT_FLAGS;

    if (nk_begin(g_renderContext.ctx, title, bounds, flags)){
        // Component content goes here
        nk_layout_row_dynamic(g_renderContext.ctx, 30, 1);
        nk_label(g_renderContext.ctx, "Background:", NK_TEXT_LEFT);

        nk_layout_row_dynamic(g_renderContext.ctx, 30, 2);
        if (nk_button_label(g_renderContext.ctx, "Default"))
            g_renderContext.bgColor = (struct nk_colorf){0.10f, 0.18f, 0.24f, 1.0f};
        if (nk_button_label(g_renderContext.ctx, "Red"))
            g_renderContext.bgColor = (struct nk_colorf){1.0f, 0.0f, 0.0f, 1.0f};
        if (nk_button_label(g_renderContext.ctx, "Green"))
            g_renderContext.bgColor = (struct nk_colorf){0.0f, 1.0f, 0.0f, 1.0f};
        if (nk_button_label(g_renderContext.ctx, "Blue"))
            g_renderContext.bgColor = (struct nk_colorf){0.0f, 0.0f, 1.0f, 1.0f};
    }
    nk_end(g_renderContext.ctx);
}