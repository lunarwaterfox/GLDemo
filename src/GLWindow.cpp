#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "GLWindow.hpp"
#include "GLFWException.hpp"

void GLWindow::keyback(GLFWwindow* window, int key, int scancode, int action, int mods) noexcept {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLWindow::GLWindow() noexcept : window(nullptr), title(""), width(640), height(480) {
}

GLWindow::~GLWindow() noexcept {
    release();
    
    if (window) {
        glfwDestroyWindow(window);
    }
}

void GLWindow::makeWindowVisible() {
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        throw GLFWException("");
    }

    glfwSetKeyCallback(window, GLWindow::keyback);
 
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);

    windowDidLoad();

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        
        render(width, height);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void GLWindow::windowDidLoad() {


}

void GLWindow::render(int width, int height) {


}

void GLWindow::release() {
    
}
