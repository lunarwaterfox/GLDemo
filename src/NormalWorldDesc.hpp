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
    ChessObject _ai;
    ZoneObject _zone;

    boolean _doAnimate;
    float _animateBegin;

    void initPlayer();
    void initAI();
public:
    NormalWorldDesc();
    ~NormalWorldDesc();

    void createElement();
    void render(int width, int height);
    void zoneShowColor(float r, float g, float b);
    void playerDoAnimate(float start, float end, float delay);
};


#endif
