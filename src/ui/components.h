#ifndef __COMPONENTS_H__
#define __COMPONENTS_H__

#define DEFAULT_FLAGS (NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE)

enum eSize {
    FULL = 100,
    HALF = 50,
    THIRD = 33,
    QUARTER = 25
};

extern const float COMPONENT_PAD_X;
extern const float COMPONENT_PAD_Y;
extern const float WINDOW_PAD_X;
extern const float WINDOW_PAD_Y;

extern const float HEADER_HEIGHT;

float calculateComponentHeight(int numRows, float rowHeight);
float calculateComponentWidth(int numCols, float colWidth);

float calculateCompHeight(float percentageOfScreen);
float calculateCompWidth(float percentageOfScreen);

#endif