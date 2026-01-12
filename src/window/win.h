#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define DEFAULT_WINDOW_WIDTH 1200
#define DEFAULT_WINDOW_HEIGHT 800

extern GLFWwindow* mainWindow;
void initMainWindow(void) ;

#endif