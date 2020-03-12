#include "ChessObject.hpp"


typedef struct _GLVertex {
    float x, y, z;
    float r, g, b;
    float s, t;
} GLVertex;

void ChessObject::createObject() {
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glGenTextures(1, &_texture);
}

void ChessObject::render(GLuint program) {


    // vbo
    GLVertex vertices[] = {
        {-4.0f, -4.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f},
        { 4.0f, -4.0f, 0.0f, 1.0f, 1.0f, 1.0f, 4.0f, 1.0f},
        { 0.0f,  4.0f, 0.0f, 1.0f, 1.0f, 1.0f, 4.0f, 0.0f},
        { 0.0f,  0.0f, 4.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}
    };

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // ebo
    GLuint elements[] = {
        0, 1, 2
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    // texture
    float pixels[] = {
        1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f
    };

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);



    // vertex location
    GLint vpos_location = glGetAttribLocation(program, "vPos");
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) 0);

    GLint vcol_location = glGetAttribLocation(program, "vCol");
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 3));

    GLint vtex_location = glGetAttribLocation(program, "vTex");
    glEnableVertexAttribArray(vtex_location);
    glVertexAttribPointer(vtex_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 6));

    // texture location
    GLint tex_location = glGetUniformLocation(program, "sampler");
    glUniform1i(tex_location, 0);

    // uniform

    // model
    mat4x4 modelOffset = {
        {   1.0f,  0.0f, 0.0f, 0.0f},
        {   0.0f,  1.0f, 0.0f, 0.0f},
        {   0.0f,  0.0f, 1.0f, 0.0f},
        {-350.0f, 50.0f, 0.0f, 1.0f}
    };

    mat4x4 modelScale = {
        {10.0f,  0.0f,   0.0f, 0.0f},
        {0.0f,  10.0f,   0.0f, 0.0f},
        {0.0f,   0.0f,  10.0f, 0.0f},
        {0.0f,   0.0f,   0.0f, 1.0f}
    };

    mat4x4_identity(_model);
    mat4x4_mul(_model, modelOffset, modelScale);

    GLint model_location = glGetUniformLocation(program, "model");
    glUniformMatrix4fv(model_location, 1, GL_FALSE, (const GLfloat*) _model);

    // draw
    glUseProgram(program);

    // glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

ChessObject::~ChessObject() {
    glDeleteBuffers(1, &_vbo);
    glDeleteBuffers(1, &_ebo);
}
