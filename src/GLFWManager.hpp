#ifndef GLFWMANAGER_HPP
#define GLFWMANAGER_HPP

#include "GLFWException.hpp"
#include "GLWindow.hpp"

class GLFWManager {
private:
    static void errorback(int error, const char* desc) noexcept;
public:
    GLFWManager() noexcept;
    ~GLFWManager() noexcept;
    void init();
    void makeWindowCurrent(GLWindow& window);
};

#endif
