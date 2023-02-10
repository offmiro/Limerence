//
// Created by user on 07/02/2023.
//

#include "shader.h"
#include "vector"

shader::shader(std::string &vertexFile, std::string &fragmentFile) {
    m_programId = glCreateProgram();
    if(m_programId == 0) std::cout << "Error creating shader program ";
    m_vertexId = glCreateShader(GL_VERTEX_SHADER);
    if(m_vertexId == 0) std::cout << "Error creating vertex shader ";
    m_fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
    if(m_fragmentId  == 0) std::cout << "Error creating fragment shader ";

    compileShader(vertexFile, m_vertexId);
    compileShader(fragmentFile, m_fragmentId);

    linkShader();

}

void shader::compileShader(const std::string &file, unsigned int id) {
    const char* content = file.c_str();

    glShaderSource(id, 1, &content, NULL);
    glCompileShader(id);

    int success = 0;

    glGetShaderiv(id,GL_COMPILE_STATUS,&success);

    if(success == GL_FALSE){
        int maxLen = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLen);
        std::vector<char> errorMessage(maxLen);
        glGetProgramInfoLog(m_programId, maxLen, &maxLen, &errorMessage[0]);
        std::cout << "Compile error!" << std::endl;

    }

}

void shader::linkShader() {
    glAttachShader(m_programId, m_vertexId);
    glAttachShader(m_programId, m_fragmentId );

    glLinkProgram(m_programId);

    int success = 0;

    if(success == GL_FALSE){
        int maxLen = 0;
        glGetShaderiv(m_programId, GL_INFO_LOG_LENGTH, &maxLen);
        std::vector<char> errorMessage(maxLen);
        glGetProgramInfoLog(m_programId, maxLen, &maxLen, &errorMessage[0]);
        std::cout << "Link error!" << std::endl;
    }


}

void shader::bind() {
    glUseProgram(m_programId);
}

void shader::unbind() {
    glUseProgram(0);
}

shader::~shader() {
    glUseProgram(0);
}
