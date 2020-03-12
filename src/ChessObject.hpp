#ifndef CHESSOBJECT_HPP
#define CHESSOBJECT_HPP

#include <glad/glad.h>
#include <linmath.h>
#include "Object.hpp"

class ChessObject: public Object {
private:
    GLuint _vbo;
    GLuint _ebo;
    GLuint _texture;
public:
    ~ChessObject();

    void createObject();
    void render(GLuint program);
};

#endif
