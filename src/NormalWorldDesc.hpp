#ifndef NORMALWORLDDESC_HPP
#define NORMALWORLDDESC_HPP

#include <glad/glad.h>

#include "BoardElement.hpp"
#include "ZoneElement.hpp"

class NormalWorldDesc {
private:
    GLuint _program;

    BoardElement *_board;
    ZoneElement *_zone;
public:
    NormalWorldDesc() noexcept;
    ~NormalWorldDesc() noexcept;

    void createElement();
    void render(int width, int height);
};


#endif
