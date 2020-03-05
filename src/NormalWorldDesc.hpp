#ifndef NORMALWORLDDESC_HPP
#define NORMALWORLDDESC_HPP

#include <glad/glad.h>
#include "NormalWorldProgram.hpp"
#include "FovWatcher.hpp"

#include "BoardElement.hpp"

class NormalWorldDesc {
private:
    NormalWorldProgram _program;
    FovWatcher _fov;

    BoardElement *_board;
public:
    NormalWorldDesc() noexcept;
    ~NormalWorldDesc() noexcept;

    void createElement();
    void render(int width, int height);
};


#endif
