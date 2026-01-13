#include "ui/components.h"
#include "ui/ctx.h"

const char* TITLE = "Display";

void displayComponent(void){

    // Number being passed to these functions is based on amount of space the Component should take up on the screen. For example, passing 5 to calculateCompWidth means the component will take up 5/10 of the total width of the mainWindow since SCREEN_COLS is set to 10. Same applies to calculateCompHeight and SCREEN_ROWS.
    float compWidth = calculateCompWidth(FULL);
    float compHeight = calculateCompHeight(FULL);

    // Calculating row height and column width for the layout of the component based on the total height and width of the component itself. At the moment the component is divided into 7 rows and 3 columns, but this can be easily changed by passing different values to the division.
    float rowHeight = compHeight / 7;
    float colWidth = compWidth / 3;
    
    // Positing component in to the top left corner of the screen with some padding from the edges.
    float xPos = WINDOW_PAD_X;
    float yPos = WINDOW_PAD_Y;
    
    struct nk_rect bounds = {xPos, yPos, compWidth, compHeight};
    
    if(nk_begin(ctx, TITLE, bounds, NK_WINDOW_BORDER | NK_WINDOW_TITLE)){
        nk_layout_row_static(ctx, rowHeight, colWidth, 3);
        nk_label(ctx, "Display Settings", NK_TEXT_CENTERED);
        nk_label(ctx, "Resolution", NK_TEXT_LEFT);
        nk_label(ctx, "Fullscreen", NK_TEXT_LEFT);
    }
    nk_end(ctx);
}