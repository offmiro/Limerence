//
// Created by user on 05/02/2023.
//

#include "window.h"
#include "iostream"

window::window(int width, int height, const char *title) {
    this->width = width;
    this->height = height;
    this->title = title;
}


void window::initWindow() {
    if(!glfwInit())
        std::cout << "Error initializing GLFW" << std::endl;

    glfwin = glfwCreateWindow(width, height, title, 0, 0);

    if(!glfwin)
        std::cout << "Error creating Window" << std::endl;

    glfwMakeContextCurrent(glfwin);

}

void window::renderWindow() {
    glfwPollEvents();
    glfwSwapBuffers(glfwin);
}
bool window::isRunning() {
    return runCheck;
}


