#include "components.h"
#include "ctx.h"
#include "nuklear.h"

#include "components/settings.h"


const float WINDOW_PAD_X = 10.0f;
const float WINDOW_PAD_Y = 10.0f;

const float TITLE_BAR_HEIGHT = 30.0f; 
const float HEADER_HEIGHT = 30.0f;



float calculateComponentHeight(int numRows, float rowHeight) {
    return (numRows * rowHeight) + (2 * WINDOW_PAD_Y) + TITLE_BAR_HEIGHT;
}

float calculateComponentWidth(int numCols, float colWidth) {
    return (numCols * colWidth)  + (2 * WINDOW_PAD_X);
}

// Calculates width of component based on the percentage of screen it should take up.
float calculateCompWidth(float percentageOfScreen){
    float availableWidth = glfw.width - (2 * WINDOW_PAD_X);
    float width = (availableWidth / 100) * percentageOfScreen;
    return width;
}

float calculateCompHeight(float percentageOfScreen){
    float availableHeight = glfw.height - (2 * WINDOW_PAD_Y);
    float height = (availableHeight / 100) * percentageOfScreen;
    return height;
}

// void setStyling(){
//     struct nk_rect header = nk_window_get_content_region(ctx);
//     // Or check the style directly
//     float header_height = ctx->style.window.header.min_size.y;
// }
