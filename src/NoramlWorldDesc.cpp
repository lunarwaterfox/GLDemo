#include "NormalWorldDesc.hpp"
#include "GLFWException.hpp"
#include "NormalWorldProgram.hpp"

void NormalWorldDesc::createElement() {
    vec4 eye = {0.0f, 500.0f, 1000.0f, 0.0f};
    vec4 center = {0.0f, 0.0f, 0.0f, 0.0f};
    vec4 up = {0.0f, 1.0f, 0.0f, 0.0f};

    _fov.lookAt(eye, center, up);
    _fov.appendObject(&_board);
}

void NormalWorldDesc::render(int width, int height) {
    _fov.perspective(M_PI / 2, (float)height / (float)width, 400, 2000);
    _program.bindWatcher(&_fov);
    _program.render();
}
