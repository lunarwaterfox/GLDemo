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


    GLuint element_buffer, vertex_buffer, vertex_array, texture;
    GLint vpos_location, vcol_location, vtex_location;
    
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

    GLuint program = _shader.getProgram();

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
    
    GLuint program = _shader.getProgram();
    glUseProgram(program);

//    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Scene::release() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
