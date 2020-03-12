#include <linmath.h>
#include "Shader.hpp"
#include "Scene.hpp"
#include "GLFWException.hpp"
#include <iostream>

void Scene::windowDidLoad() {
    GLuint vao;
    // VAO
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    _desc.createElement();
}

void Scene::renderRect(int width, int height) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    _desc.render(width, height);
}

void Scene::mouseDown(float x, float y) {
    std::cout << x << "-" << y << std::endl;

}

void Scene::release() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
