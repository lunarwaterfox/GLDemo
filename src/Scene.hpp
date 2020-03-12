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
    void renderRect(int width, int height);
    void mouseDown(float x, float y);
    void release() const;
};

#endif
