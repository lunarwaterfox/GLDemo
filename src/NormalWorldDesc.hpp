#ifndef NORMALWORLDDESC_HPP
#define NORMALWORLDDESC_HPP

#include <chrono>

#include <glad/glad.h>
#include "NormalWorldProgram.hpp"
#include "FovWatcher.hpp"
#include "BoardObject.hpp"
#include "ChessObject.hpp"
#include "ParallelWatcher.hpp"
#include "ZoneObject.hpp"

using namespace std;

class NormalWorldDesc {
private:
    NormalWorldProgram _program;
    FovWatcher _fov;
    ParallelWatcher _parallel;
    BoardObject _board;
    ChessObject _player;
    ChessObject _ai;
    ZoneObject _zone;

    GLboolean _doAnimate;
    chrono::steady_clock::time_point _animateBeginTime;
    float _animateDuration;
    float _animateStart;
    float _animateEnd;


    void initPlayer();
    void initAI();

    void movePlayer(float progress);
public:
    NormalWorldDesc();

    void createElement();
    void render(int width, int height);
    void zoneShowColor(float r, float g, float b);
    void playerDoAnimate(float start, float end, float delay);
};


#endif
