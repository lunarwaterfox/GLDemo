#ifndef SCENE_HPP
#define SCENE_HPP

#include <glad/glad.h>
#include "GLWindow.hpp"
#include "BoardElement.hpp"

class Scene: public GLWindow {
private:
    BoardElement *_board;
    BoardElement *_board2;
protected:
    void windowDidLoad();
    void render(int width, int height);
    void release();
};

#endif
