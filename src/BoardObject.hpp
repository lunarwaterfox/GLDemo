#ifndef BOARDOBJECT_HPP
#define BOARDOBJECT_HPP

#include <glad/glad.h>
#include <linmath.h>
#include "Object.hpp"

class BoardObject: public Object {
private:
    GLuint _vbo;
    GLuint _ebo;
    GLuint _texture;
public:
    ~BoardObject();
    
    void createObject();
    void render(GLuint program);
};

#endif
