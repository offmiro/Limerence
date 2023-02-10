//
// Created by user on 07/02/2023.
//
#include "iostream"
#include "GLFW/glfw3.h"

class shader {
public:
    shader(std::string &vertexFile, std::string &fragmentFile);
    ~shader();

    void bind();
    void unbind();

private:
    void compileShader(const std::string &file, unsigned int id);
    void linkShader();
    unsigned int m_programId;
    unsigned int m_vertexId;
    unsigned int m_fragmentId;
};