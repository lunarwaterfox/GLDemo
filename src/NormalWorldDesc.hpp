#ifndef NORMALWORLDDESC_HPP
#define NORMALWORLDDESC_HPP

#include <glad/glad.h>
#include "NormalWorldProgram.hpp"
#include "FovWatcher.hpp"
#include "BoardObject.hpp"
#include "ChessObject.hpp"
#include "ParallelWatcher.hpp"
#include "ZoneObject.hpp"

class NormalWorldDesc {
private:
    NormalWorldProgram _program;
    FovWatcher _fov;
    ParallelWatcher _parallel;
    BoardObject _board;
    ChessObject _player;
    ZoneObject _zone;
public:
    void createElement();
    void render(int width, int height);
};


#endif
