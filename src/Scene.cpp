#include <linmath.h>
#include "Shader.hpp"
#include "Scene.hpp"
#include "GLFWException.hpp"
#include <iostream>


void Scene::engineStateUpdateCallback(EngineState state, void* context) {;
    Engine* engine = (Engine *)context;

    switch (state) {
    case PLAYER_STEP:
        std::cout << "player step finish." << std::endl;
        engine->playerStepFinish();
        break;
    case PLAYER_WIN:
        std::cout << "player win." << std::endl;
        break;
    case AI_TURN:
        std::cout << "ai get 2." << std::endl;
        engine->aiGetNumber(2);
        break;
    case AI_STEP:
        std::cout << "ai step finish." << std::endl;
        engine->aiStepFinish();
        break;
    case AI_WIN:
        std::cout << "ai win." << std::endl;
        break;
    default:
        break;
    }
}

void Scene::windowDidLoad() {
    GLuint vao;
    // VAO
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    _desc.createElement();

    _engine.registerEngineCallback(engineStateUpdateCallback, &_engine);
    _engine.begin();
}

void Scene::renderRect(int width, int height) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    _desc.render(width, height);
}

void Scene::mouseDown(float x, float y) {
    std::cout << "player get 3." << std::endl;
    _engine.playerGetNumber(3);
}

void Scene::release() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
