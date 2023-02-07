//
// Created by user on 06/02/2023.
//

#ifndef LIMERENCE_SHADER_H
#define LIMERENCE_SHADER_H

#include "GLFW/glfw3.h"
#include "iostream"

class shader {
public:

    shader(const char* vertexShader, const char* fragmentShader);

    virtual inline void bind() const;
    virtual inline void unbind() const;

    int compileShader(unsigned int type, const std::string& sourceFile);
    int createShader(const std::string& vertexShader, const std::string& fragmentShader);

private:
    unsigned int shaderId;
    bool isShaderCompiled;

};


#endif //LIMERENCE_SHADER_H
