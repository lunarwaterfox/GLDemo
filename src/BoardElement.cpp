#include <glad/glad.h>
#include "BoardElement.hpp"

typedef struct _GLVertex {
    float x, y;
    float r, g, b;
    float s, t;
} GLVertex;

typedef struct _GLElement {
    float a1, a2, a3;
} GLElement;

BoardElement::BoardElement() noexcept {
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);
    
    glGenTextures(1, &_texture);
}

BoardElement::~BoardElement() noexcept {
//    glDeleteBuffer(1, &_vbo);
//    glDeleteBuffer(1, &_ebo);
}


void BoardElement::render() {
    // vbo
    GLVertex vertices[] = {
        {-0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        { 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 8.0f, 0.0f},
        { 0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 8.0f, 8.0f},
        {-0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 8.0f}
    };
    
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // ebo
    GLElement elements[] = {
        {0, 1, 2},
        {2, 3, 0}
    };
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
    
    // texture
    float pixels[] = {
        0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
    };
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}
