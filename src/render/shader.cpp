//
// Created by user on 06/02/2023.
//

#include "shader.h"
#include "GLFW/glfw3.h"


shader::shader(const char *vertexShader, const char *fragmentShader) {

}


int shader::compileShader(unsigned int type, const std::string &sourceFile) {
    unsigned int createShaderWithType = glCreateShader(type);
    const char* srcToC_STR = sourceFile.c_str();
    glShaderSource(createShaderWithType, 1, &srcToC_STR, nullptr);
    glCompileShader(createShaderWithType);

    return createShaderWithType;
}

int shader::createShader(const std::string &vertexShader, const std::string &fragmentShader) {
    unsigned int shaderProgram = glCreateProgram();
    unsigned int compiledVertexShader = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int compiledFragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(shaderProgram, compiledVertexShader);
    glAttachShader(shaderProgram, compiledFragmentShader);

    glLinkProgram(shaderProgram);
    glValidateProgram(shaderProgram);

    glDeleteShader(compiledVertexShader);
    glDeleteShader(compiledFragmentShader);


}

void shader::bind() const {

}

void shader::unbind() const {

}
