#ifndef BOARDELEMENT_HPP
#define BOARDELEMENT_HPP

#include "Element.hpp"
#include <glad/glad.h>
#include "NormalShaderProgram.hpp"

class BoardElement: public Element {
private:
    GLuint _vbo;
    GLuint _ebo;
    GLuint _texture;
public:
    BoardElement() noexcept;
    ~BoardElement() noexcept;
    
    void render();    
};

#endif
