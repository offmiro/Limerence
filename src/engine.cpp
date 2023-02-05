#include <GLFW/glfw3.h>
#include <iostream>
#include "render/window.h"

int main(void)
{
    window* win = new window(1280, 720, "Name");
    win->initWindow();

    while (win->isRunning()){
        win->renderWindow();
    }

    win->deleteWindow();
}