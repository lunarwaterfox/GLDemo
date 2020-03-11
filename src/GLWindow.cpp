#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "GLWindow.hpp"
#include "GLFWException.hpp"

void GLWindow::keyback(GLFWwindow* window, int key, int scancode, int action, int mods) noexcept {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLWindow::GLWindow() noexcept : _window(nullptr), _title(""), _width(640), _height(640) {
}

GLWindow::~GLWindow() noexcept {
    release();

    if (_window) {
        glfwDestroyWindow(_window);
    }
}

void GLWindow::render() {
    _window = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
    if (!_window) {
        throw GLFWException("");
    }

    glfwSetKeyCallback(_window, GLWindow::keyback);

    glfwMakeContextCurrent(_window);
    gladLoadGL();
    glfwSwapInterval(1);

    windowDidLoad();

    while (!glfwWindowShouldClose(_window)) {
        int width, height;
        glfwGetFramebufferSize(_window, &width, &height);

        renderRect(width, height);

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    release();
}

void GLWindow::windowDidLoad() {


}

void GLWindow::renderRect(int width, int height) {


}

void GLWindow::release() {

}
