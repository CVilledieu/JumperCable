#include "ui/components.h"
#include "ui/ctx.h"


typedef struct {
    int active;
    const char* name;
    struct nk_colorf color;
} Theme;

static Theme themes[] = {
    {1, "Default", (struct nk_colorf){0.10f, 0.18f, 0.24f, 1.0f}},
    {0, "White", (struct nk_colorf){1.0f, 1.0f, 1.0f, 1.0f}},
    {0, "Black", (struct nk_colorf){0.0f, 0.0f, 0.0f, 1.0f}},
    {0, "Blue", (struct nk_colorf){0.0f, 0.0f, 0.3f, 1.0f}},
    {0, "Red", (struct nk_colorf){1.0f, 0.0f, 0.0f, 1.0f}},
    {0, "Green", (struct nk_colorf){0.0f, 1.0f, 0.0f, 1.0f}},
};

static const char* TITLE = "[S] Settings";
static int numThemes = sizeof(themes) / sizeof(Theme);

void updateActiveTheme(int index) {

    for (int i = 0; i < numThemes; i++) {
        if(i == index){
            themes[i].active = 1;
            bgColor = themes[i].color;
        } else {
            themes[i].active = 0;
        }
    }
}


void isMinimized(void){
    float width = 30;
    float height = TITLE_BAR_HEIGHT;
    float xPos = glfw.width - width - WINDOW_PAD_X;
    float yPos = WINDOW_PAD_Y;
    
    struct nk_rect bounds = {xPos, yPos, width, height};
    if(nk_begin(ctx, TITLE, bounds, NK_WINDOW_BORDER | NK_WINDOW_TITLE | NK_WINDOW_MINIMIZABLE | NK_WINDOW_MINIMIZED)){
    }
    nk_end(ctx);
}

void isNotMinimized(void){

    float numCols = 2;
    float colWidth = 80;

    float numRows = 3;
    float rowHeight = 30;
    float rowPadding = 5;

    float width =  calculateComponentWidth(numCols, colWidth);
    float height = calculateComponentHeight(numRows, (rowHeight + rowPadding));    

    float xPos = glfw.width - width - WINDOW_PAD_X;
    float yPos = WINDOW_PAD_Y;


    struct nk_rect bounds = {xPos, yPos, width, height};
    if(nk_begin(ctx, TITLE, bounds, NK_WINDOW_BORDER | NK_WINDOW_TITLE | NK_WINDOW_MINIMIZABLE)){
        // Component content goes here
        nk_layout_row_static(ctx, rowHeight, (colWidth * numCols), 1);
        nk_label(ctx, "Settings", NK_TEXT_CENTERED);

        nk_layout_row_static(ctx, rowHeight, colWidth, numCols);
        for (int i = 0; i < numThemes; i++) {
            if(nk_radio_label(ctx, themes[i].name, &themes[i].active)) {
                updateActiveTheme(i);
            }
            if ((i+1)%(int)numCols == 0){
                nk_layout_row_static(ctx, rowHeight, colWidth, numCols);
            }
        }
    }
    nk_end(ctx);
}


void settingsComponent(void){
    if (nk_window_is_collapsed(ctx, TITLE)) {
        isMinimized();
        
    } else {
        isNotMinimized();
    }
    return;
}


// Old styling code for reference:
//
// float ratio[] = {0.1f, 0.4f, 0.4f, 0.01f};  // 10% padding each side
// nk_layout_row(ctx, NK_DYNAMIC, rowHeight, 4, ratio);
// nk_spacing(ctx, 1);
// if (nk_button_label(ctx, "Default")) { bgColor = (struct nk_colorf){0.10f, 0.18f, 0.24f, 1.0f};}
// if (nk_button_label(ctx, "White")) { bgColor = (struct nk_colorf){1.0f, 1.0f, 1.0f, 1.0f};}

// nk_layout_row(ctx, NK_DYNAMIC, rowHeight, 4, ratio);
// nk_spacing(ctx, 1);
// if (nk_button_label(ctx, "Black")) { bgColor = (struct nk_colorf){0.0f, 0.0f, 0.0f, 1.0f};}
// if (nk_button_label(ctx, "Blue")) { bgColor = (struct nk_colorf){0.0f, 0.0f, 0.5f, 1.0f};}

// // nk_layout_row_static(ctx, rowHeight, (colWidth * 2), 1);
// // nk_layout_row_static(ctx, rowHeight, colWidth, numCols);
// // if (nk_button_label(ctx, "Default"))
// //     bgColor = (struct nk_colorf){0.10f, 0.18f, 0.24f, 1.0f};
// // if (nk_button_label(ctx, "Red"))
// //     bgColor = (struct nk_colorf){1.0f, 0.0f, 0.0f, 1.0f};
// // if (nk_button_label(ctx, "Green"))
// //     bgColor = (struct nk_colorf){0.0f, 1.0f, 0.0f, 1.0f};
// // if (nk_button_label(ctx, "Blue"))
// //     bgColor = (struct nk_colorf){0.0f, 0.0f, 1.0f, 1.0f};