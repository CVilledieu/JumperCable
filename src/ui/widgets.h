#ifndef __WIDGETS_H__
#define __WIDGETS_H__

#define MAX_TITLE_LENGTH 32
#define DEFAULT_FLAGS (NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE)

typedef struct Widget {
    int id;
    char title[MAX_TITLE_LENGTH];
    struct nk_rect bounds;
    nk_flags flags;
    void (*layout)(void);
} Widget;

void initWidgets(renderContext_t* renderContext);
void drawWidget(renderContext_t* ctx, Widget* widget);


#endif