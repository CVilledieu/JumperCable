#include "gui/draw.h"
#include "util/err.h"
#include <stdio.h>

int main(void)
{
    if (initGui() != 0) {
        fprintf(stderr, "Failed to initialize GUI\n");
        return 1;
    }

    drawLoop();

    cleanupGui();
    return 0;
}
