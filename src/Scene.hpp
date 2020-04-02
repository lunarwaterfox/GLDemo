#ifndef SCENE_HPP
#define SCENE_HPP

#include <random>
#include <glad/glad.h>
#include "GLWindow.hpp"
#include "NormalWorldDesc.hpp"
#include "Engine.hpp"

using namespace std;

class Scene: public GLWindow {
private:
    NormalWorldDesc _desc;
    Engine _engine;
    random_device _rd;
    default_random_engine _generator;
    uniform_int_distribution<int> _distribution;

    static void engineStateUpdateCallback(EngineState state, void* scene);
    int getRandom();

    void playerAnimateStep(int num);
    float transToPosition(int p);
protected:
    void windowDidLoad();
    void renderRect(int width, int height);
    void mouseDown(float x, float y);
    void release() const;
public:
    Scene();
};

#endif
