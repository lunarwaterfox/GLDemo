#define GLFW_INCLUDE_NONE
#include <iostream>
#include <GLFW/glfw3.h>

#include "GLFWManager.hpp"
#include "GLFWException.hpp"

using namespace std;

void GLFWManager::errorback(int error, const char* desc) noexcept {
    cout << "Error: " << desc << endl;
}

GLFWManager::GLFWManager() noexcept {
    glfwSetErrorCallback(GLFWManager::errorback);
}

GLFWManager::~GLFWManager() noexcept {
    glfwTerminate();
}

void GLFWManager::init() {
    if (!glfwInit()) {
        throw GLFWException("");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void GLFWManager::makeWindowCurrent(GLWindow& window) {
    window.makeWindowVisible();
}
