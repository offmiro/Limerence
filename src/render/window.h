
#include "GLFW/glfw3.h"
#include "string"

class window {
public:
   window(int width, int height, const char* title);
   void initWindow();
   void renderWindow();
   bool isRunning();


private:
    int width;
    int height;
    const char* title;

    bool runCheck = true;

    GLFWwindow *glfwin;

};
