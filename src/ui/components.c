#include "components.h"
#include "ctx.h"
#include "nuklear.h"

#define DEFAULT_FLAGS (NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE)

#define WINDOW_PAD_X 20
#define WINDOW_PAD_Y 20

#define COMPONENT_PAD_X 10
#define COMPONENT_PAD_Y 10


void settingsComponent(void);

void initComponents(void) {
    // Initialize any global state for components here if needed
    
}


void settingsComponent(void){
    const char* title = "Settings";

    nk_flags flags =  NK_WINDOW_MINIMIZABLE |  NK_WINDOW_TITLE | NK_WINDOW_BORDER;

    float componentWidth = 300;
    float componentHeight = 200;
    float xPos = glfw.width - componentWidth - WINDOW_PAD_X;
    float yPos = WINDOW_PAD_Y;
    
    struct nk_rect bounds = {xPos, yPos, componentWidth, componentHeight};

    if (nk_begin(ctx, title, bounds, flags)){
        // Component content goes here
        nk_layout_row_dynamic(ctx, 30, 1);
        nk_label(ctx, "Background:", NK_TEXT_LEFT);

        nk_layout_row_dynamic(ctx, 30, 2);
        if (nk_button_label(ctx, "Default"))
            bgColor = (struct nk_colorf){0.10f, 0.18f, 0.24f, 1.0f};
        if (nk_button_label(ctx, "Red"))
            bgColor = (struct nk_colorf){1.0f, 0.0f, 0.0f, 1.0f};
        if (nk_button_label(ctx, "Green"))
            bgColor = (struct nk_colorf){0.0f, 1.0f, 0.0f, 1.0f};
        if (nk_button_label(ctx, "Blue"))
            bgColor = (struct nk_colorf){0.0f, 0.0f, 1.0f, 1.0f};
    }
    nk_end(ctx);
}