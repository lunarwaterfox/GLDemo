#ifndef NORMALWORLDDESC_HPP
#define NORMALWORLDDESC_HPP

#include <glad/glad.h>
#include "NormalWorldProgram.hpp"
#include "FovWatcher.hpp"
#include "BoardObject.hpp"

class NormalWorldDesc {
private:
    NormalWorldProgram _program;
    FovWatcher _fov;
    BoardObject _board;
public:
    void createElement();
    void render(int width, int height);
};


#endif
