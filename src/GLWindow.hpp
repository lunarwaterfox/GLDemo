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
    string title;
    int width;
    int height;

    virtual void windowDidLoad();
    virtual void render(int width, int height);
    virtual void release();
    
public:
    GLFWwindow* window;
    
    GLWindow() noexcept;
    ~GLWindow() noexcept;

    void makeWindowVisible();
};

#endif
