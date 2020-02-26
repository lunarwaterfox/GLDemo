#ifndef SCENE_HPP
#define SCENE_HPP

#include <glad/glad.h>
#include "GLWindow.hpp"
#include "BoardElement.hpp"
#include "ZoneElement.hpp"

class Scene: public GLWindow {
private:
    BoardElement *_board;
    ZoneElement *_zone;
protected:
    void windowDidLoad();
    void render(int width, int height);
    void release();
};

#endif
