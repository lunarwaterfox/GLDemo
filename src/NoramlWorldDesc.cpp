#include "NormalWorldDesc.hpp"
#include "GLFWException.hpp"
#include "NormalWorldProgram.hpp"

void NormalWorldDesc::createElement() {
    vec4 eyef = {0.0f, -500.0f, 400.0f, 0.0f};
    vec4 centerf = {0.0f, 0.0f, 0.0f, 0.0f};
    vec4 upf = {0.0f, 1.0f, 0.0f, 0.0f};

    _fov.lookAt(eyef, centerf, upf);
    _fov.appendObject(&_board);
    _fov.appendObject(&_player);

    vec4 eyep = {0.0f, 0.0f, 0.0f, 0.0f};
    vec4 centerp = {0.0f, 0.0f, 100.0f, 0.0f};
    vec4 upp = {0.0f, 1.0f, 0.0f, 0.0f};
    _parallel.lookAt(eyep, centerp, upp);
    _parallel.appendObject(&_zone);
}

void NormalWorldDesc::render(int width, int height) {
    _fov.perspective(M_PI / 2, (float)height / (float)width, 400, 2000);
    _parallel.ortho(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0, 0, 100);

    _program.bindWatcher(&_fov);
    _program.render();

    _program.bindWatcher(&_parallel);
    _program.render();
}

void NormalWorldDesc::zoneShowColor(float r, float g, float b) {
    _zone.zoneShowColor(r, g, b);
}
