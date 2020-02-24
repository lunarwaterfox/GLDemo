#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram() noexcept : _program(0) {
    
}


ShaderProgram::~ShaderProgram() noexcept {
    if (_program != 0) {
        glDeleteProgram(_program);
    }
}

void ShaderProgram::useProgram() {
    GLuint program = getProgram();
    glUseProgram(program);
}

GLuint ShaderProgram::getProgram() {
    if (_program == 0) {
        _program = createPrograme();
    }
    
    return _program;
}

GLuint ShaderProgram::createPrograme() {
    return 0;
}
