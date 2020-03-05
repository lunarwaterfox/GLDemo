#include "NormalWorldDesc.hpp"
#include "GLFWException.hpp"
#include "NormalWorldProgram.hpp"

//
NormalWorldDesc::NormalWorldDesc() noexcept {
}

void NormalWorldDesc::createElement() {
    vec4 eye = {0.0f, -50.0f, 50.0f, 1.0f};
    vec4 center = {0.0f, 0.0f, 0.0f, 1.0f};
    vec4 up = {0.0f, 1.0f, 0.0f, 1.0f};

    _fov.lookAt(eye, center, up);


    _board = new BoardElement();
}

void NormalWorldDesc::render(int width, int height) {
    _fov.perspective(M_PI, height / width, 40, 200);
    _program.bindWatcher(_fov);


    _board->render(width, height, _program.getProgram());
}

NormalWorldDesc::~NormalWorldDesc() noexcept {
    delete _board;
}
