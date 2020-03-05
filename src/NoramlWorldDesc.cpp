#include "NormalWorldDesc.hpp"
#include "GLFWException.hpp"
#include "NormalWorldProgram.hpp"

//
NormalWorldDesc::NormalWorldDesc() noexcept: _program(0) {
}

void NormalWorldDesc::createElement() {
    _program = NormalWorldProgram::createProgram();

    _board = new BoardElement();
    _zone = new ZoneElement();
}

void NormalWorldDesc::render(int width, int height) {
    glUseProgram(_program);

    _board->render(width, height, _program);
    _zone->render(width, height, _program);
}


NormalWorldDesc::~NormalWorldDesc() noexcept {
    if (_program != 0) {
        glDeleteProgram(_program);
    }

    delete _board;
    delete _zone;
}
