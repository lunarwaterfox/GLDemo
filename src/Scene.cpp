#include <linmath.h>
#include "Shader.hpp"
#include "Scene.hpp"
#include "GLFWException.hpp"

void Scene::windowDidLoad() {
    struct {
        float x, y;
        float r, g, b;
        float s, t;
    } vertices[] = {
        {-0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        { 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 8.0f, 0.0f},
        { 0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 8.0f, 8.0f},
        {-0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 8.0f}
    };
    
    GLuint element[] = {
        0, 1, 2,
        2, 3, 0
    };
    
    float pixels[] = {
        0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
    };
    
    
    static const char* vertex_shader_text = Shader::getVertexShader();
    static const char* fragment_shader_text = Shader::getFragmentShader();

    GLuint element_buffer, vertex_buffer, vertex_array, texture;
    GLuint vertex_shader, fragment_shader;
    GLint vpos_location, vcol_location, vtex_location;
    GLint success;
    char infoLog[8192];
    
    // VAO
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);

    // VBO
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // EBO
    glGenBuffers(1, &element_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(element), element, GL_STATIC_DRAW);
    
    // Texture
    glGenTextures(1, &texture);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Shader
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
    
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        throw GLFWException(infoLog);
    }
    
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
    
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        throw GLFWException(infoLog);
    }

    // Program
    program = glCreateProgram();
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

    // vertex location
    vpos_location = glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) 0);
    
    vcol_location = glGetAttribLocation(program, "col");
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 2));
    
    vtex_location = glGetAttribLocation(program, "texcoord");
    glEnableVertexAttribArray(vtex_location);
    glVertexAttribPointer(vtex_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 5));
    
    // texture location
    
    GLint tex_location = glGetUniformLocation(program, "tex");
    glUniform1i(tex_location, 0);
    
//    vCol = glGetUniformLocation(program, "triangleColor");
//    glUniform3f(vCol, 1.0f, 0.0f, 0.0f);
}

void Scene::render(int width, int height) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    glUseProgram(program);

//    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Scene::release() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
