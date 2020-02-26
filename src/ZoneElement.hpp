#ifndef ZONEELEMENT_HPP
#define ZONEELEMENT_HPP

#include "Element.hpp"
#include <glad/glad.h>

class ZoneElement: public Element {
private:
    GLuint _vbo;
    GLuint _ebo;
    GLuint _texture;
public:
    ZoneElement() noexcept;
    ~ZoneElement() noexcept;
    
    void render();
};

#endif
