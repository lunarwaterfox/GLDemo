#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <glm/glm.hpp>
#include <linmath.h>

class Element {
protected:
    mat4x4 _model;
    mat4x4 _view;
    mat4x4 _proj;
public:
    Element() noexcept;
    virtual void render();
};

#endif
