#include "err.h"
#include <stdio.h>

void Window_ErrCallback(int error, const char* description){
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}