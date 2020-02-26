#include <glad/glad.h>
#include "ZoneElement.hpp"
#include "ShaderManager.hpp"

typedef struct _GLVertex {
    float x, y;
    float r, g, b;
    float s, t;
} GLVertex;

ZoneElement::ZoneElement() noexcept {
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);
    
    glGenTextures(1, &_texture);
}

ZoneElement::~ZoneElement() noexcept {
    glDeleteBuffers(1, &_vbo);
    glDeleteBuffers(1, &_ebo);
}


void ZoneElement::render() {
    // vbo
    GLVertex vertices[] = {
        { 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
        { 0.0f, 0.5f, 1.0f, 1.0f, 1.0f, 8.0f, 0.0f},
        { 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 8.0f, 8.0f},
        { 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 8.0f}
    };

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // ebo
    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    // texture
    float pixels[] = {
        1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,
    };
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // shader
    GLuint program = ShaderManager::sharedManager()->getNormalProgram();

    // vertex location
    GLint vpos_location = glGetAttribLocation(program, "vPos");
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) 0);

    GLint vcol_location = glGetAttribLocation(program, "vCol");
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 2));

    GLint vtex_location = glGetAttribLocation(program, "vTex");
    glEnableVertexAttribArray(vtex_location);
    glVertexAttribPointer(vtex_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 5));

    // texture location
    GLint tex_location = glGetUniformLocation(program, "sampler");
    glUniform1i(tex_location, 0);

    // uniform
    mat4x4 scale = {
        {2.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 2.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 2.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };
    
    GLint model_location = glGetUniformLocation(program, "model");
    glUniformMatrix4fv(model_location, 1, GL_FALSE, (const GLfloat*) scale);
    
    GLint view_location = glGetUniformLocation(program, "view");
    glUniformMatrix4fv(view_location, 1, GL_FALSE, (const GLfloat*) _view);
    
    GLint proj_location = glGetUniformLocation(program, "proj");
    glUniformMatrix4fv(proj_location, 1, GL_FALSE, (const GLfloat*) _proj);

    // draw
    glUseProgram(program);

    // glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
