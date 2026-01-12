#include "ui/ctx.h"
#include "window/win.h"


int main(void){
    initMainWindow();
    
    initRenderContext();
    
    while(!glfwWindowShouldClose(mainWindow)){

        // Clears previous frame's buffer and polls for input events
        clearBuffer();
        setInputListeners();

        // Draws Components to the buffer then swaps the buffer to the screen
        renderComponents();
        glfwSwapBuffers(mainWindow);
    }

    endApp();
}