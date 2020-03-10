#ifndef GLWINDOW_HPP
#define GLWINDOW_HPP

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

class GLWindow {
private:
    static void keyback(GLFWwindow* window, int key, int scancode, int action, int mods) noexcept;

protected:
    string _title;
    int _width;
    int _height;
    GLFWwindow* _window;

    virtual void windowDidLoad();
    virtual void renderRect(int width, int height);
    virtual void release();

public:
    GLWindow() noexcept;
    ~GLWindow() noexcept;

    void render();
};

#endif
