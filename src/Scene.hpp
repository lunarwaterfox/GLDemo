#ifndef SCENE_HPP
#define SCENE_HPP

#include <glad/glad.h>
#include "GLWindow.hpp"
#include "NormalWorldDesc.hpp"

class Scene: public GLWindow {
private:
    NormalWorldDesc _desc;
protected:
    void windowDidLoad();
    void render(int width, int height);
    void release();
};

#endif
