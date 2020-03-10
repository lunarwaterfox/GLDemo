//#include <linmath.h>

#include "NormalWorldProgram.hpp"
#include "Shader.hpp"
#include "GLFWException.hpp"

// static
GLuint NormalWorldProgram::createProgram() {
    static const char* vertex_shader_text = Shader::getVertexShader();
    static const char* fragment_shader_text = Shader::getFragmentShader();

    GLint success;
    char infoLog[8192];

    // vertex shader
    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);

    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        throw GLFWException(infoLog);
    }

    // fragment shader
    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        throw GLFWException(infoLog);
    }

    // Program
    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        throw GLFWException(infoLog);
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;
}

//
NormalWorldProgram::NormalWorldProgram() noexcept: _program(0) {

}

GLuint NormalWorldProgram::getProgram() {
    if (_program == 0) {
        _program = createProgram();
    }

    return _program;
}

void NormalWorldProgram::bindWatcher(const Watcher* watcher) {
    GLuint program = getProgram();

    const mat4x4& _view = watcher->getViewMatrix();
    const mat4x4& _proj = watcher->getProjectMatrix();

    // view
    GLint view_location = glGetUniformLocation(program, "view");
    glUniformMatrix4fv(view_location, 1, GL_FALSE, (const GLfloat*) _view);

    // proj
    GLint proj_location = glGetUniformLocation(program, "proj");
    glUniformMatrix4fv(proj_location, 1, GL_FALSE, (const GLfloat*) _proj);

    _watcher = watcher;
}

void NormalWorldProgram::render() {
    _watcher->render(_program);
}

NormalWorldProgram::~NormalWorldProgram() noexcept {
    if (_program != 0) {
        glDeleteProgram(_program);
    }
}
