#ifndef NORMALWORLDDESC_HPP
#define NORMALWORLDDESC_HPP

#include <glad/glad.h>
#include "NormalWorldProgram.hpp"
#include "FovWatcher.hpp"
#include "BoardObject.hpp"
#include "ChessObject.hpp"

class NormalWorldDesc {
private:
    NormalWorldProgram _program;
    FovWatcher _fov;
    BoardObject _board;
    ChessObject _player;
public:
    void createElement();
    void render(int width, int height);
};


#endif
