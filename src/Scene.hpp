#ifndef SCENE_HPP
#define SCENE_HPP

#include <glad/glad.h>
#include "GLWindow.hpp"
#include "NormalWorldDesc.hpp"
#include "Engine.hpp"

class Scene: public GLWindow {
private:
    NormalWorldDesc _desc;
    Engine _engine;

    static void engineStateUpdateCallback(EngineState state, void* scene);
protected:
    void windowDidLoad();
    void renderRect(int width, int height);
    void mouseDown(float x, float y);
    void release() const;
};

#endif
