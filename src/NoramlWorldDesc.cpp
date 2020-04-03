#include "NormalWorldDesc.hpp"
#include "GLFWException.hpp"
#include "NormalWorldProgram.hpp"

NormalWorldDesc::NormalWorldDesc(): _doAnimate(false), _animateDuration(0) {

}

void NormalWorldDesc::createElement() {
    vec4 eyef = {0.0f, -500.0f, 400.0f, 0.0f};
    vec4 centerf = {0.0f, 0.0f, 0.0f, 0.0f};
    vec4 upf = {0.0f, 1.0f, 0.0f, 0.0f};

    _fov.lookAt(eyef, centerf, upf);
    _fov.appendObject(&_board);

    initPlayer();
    _fov.appendObject(&_player);

    initAI();
    _fov.appendObject(&_ai);

    vec4 eyep = {0.0f, 0.0f, 0.0f, 0.0f};
    vec4 centerp = {0.0f, 0.0f, 100.0f, 0.0f};
    vec4 upp = {0.0f, 1.0f, 0.0f, 0.0f};
    _parallel.lookAt(eyep, centerp, upp);
    _parallel.appendObject(&_zone);
}

void NormalWorldDesc::render(int width, int height) {
    _fov.perspective(M_PI / 2, (float)height / (float)width, 400, 2000);
    _parallel.ortho(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0, 0, 100);

    if (_doAnimate) {
        chrono::steady_clock::time_point cur = chrono::steady_clock::now();
        int second = chrono::duration_cast<chrono::seconds>(cur - _animateBeginTime).count();

        float progress = 1;
        if (second < _animateDuration) {
            progress = second / _animateDuration;
        }

        movePlayer(progress);

        if (progress == 1) {
            _doAnimate = false;
        }
    }



    _program.bindWatcher(&_fov);
    _program.render();

    _program.bindWatcher(&_parallel);
    _program.render();
}

void NormalWorldDesc::movePlayer(float progress) {
    float start = _animateStart;
    float end = _animateEnd;

    float cur = start + (end - start) * progress;

    mat4x4 model;

    mat4x4 modelOffset = {
        {   1.0f,  0.0f, 0.0f, 0.0f},
        {   0.0f,  1.0f, 0.0f, 0.0f},
        {   0.0f,  0.0f, 1.0f, 0.0f},
        {    cur, 50.0f, 0.0f, 1.0f}
    };

    mat4x4 modelScale = {
        {10.0f,  0.0f,   0.0f, 0.0f},
        {0.0f,  10.0f,   0.0f, 0.0f},
        {0.0f,   0.0f,  10.0f, 0.0f},
        {0.0f,   0.0f,   0.0f, 1.0f}
    };

    mat4x4_identity(model);
    mat4x4_mul(model, modelOffset, modelScale);

    _player.setModel(model);
}

void NormalWorldDesc::zoneShowColor(float r, float g, float b) {
    _zone.zoneShowColor(r, g, b);
}

void NormalWorldDesc::playerDoAnimate(float start, float end, float delay) {
    _animateBeginTime = chrono::steady_clock::now();
    _animateStart = start;
    _animateEnd = end;
    _animateDuration = delay;
    _doAnimate = true;
}


void NormalWorldDesc::initPlayer() {
    mat4x4 model;

    mat4x4 modelOffset = {
        {   1.0f,  0.0f, 0.0f, 0.0f},
        {   0.0f,  1.0f, 0.0f, 0.0f},
        {   0.0f,  0.0f, 1.0f, 0.0f},
        {-350.0f, 50.0f, 0.0f, 1.0f}
    };

    mat4x4 modelScale = {
        {10.0f,  0.0f,   0.0f, 0.0f},
        {0.0f,  10.0f,   0.0f, 0.0f},
        {0.0f,   0.0f,  10.0f, 0.0f},
        {0.0f,   0.0f,   0.0f, 1.0f}
    };

    mat4x4_identity(model);
    mat4x4_mul(model, modelOffset, modelScale);

    _player.setModel(model);
}

void NormalWorldDesc::initAI() {
    mat4x4 model;

    mat4x4 modelOffset = {
        {   1.0f,   0.0f, 0.0f, 0.0f},
        {   0.0f,   1.0f, 0.0f, 0.0f},
        {   0.0f,   0.0f, 1.0f, 0.0f},
        {-350.0f, -50.0f, 0.0f, 1.0f}
    };

    mat4x4 modelScale = {
        {10.0f,  0.0f,   0.0f, 0.0f},
        {0.0f,  10.0f,   0.0f, 0.0f},
        {0.0f,   0.0f,  10.0f, 0.0f},
        {0.0f,   0.0f,   0.0f, 1.0f}
    };

    mat4x4_identity(model);
    mat4x4_mul(model, modelOffset, modelScale);

    _ai.setModel(model);
}
