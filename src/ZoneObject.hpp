#ifndef ZONEOBJECT_HPP
#define ZONEOBJECT_HPP

#include <glad/glad.h>
#include <linmath.h>
#include "Object.hpp"

class ZoneObject: public Object {
private:
    GLuint _vbo;
    GLuint _ebo;
    GLuint _texture;

    float _r;
    float _g;
    float _b;
public:
    ZoneObject();
    ~ZoneObject();

    void createObject();
    void render(GLuint program);
    void zoneShowColor(float r, float g, float b);
};

#endif
