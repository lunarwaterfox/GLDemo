#ifndef SCENE_HPP
#define SCENE_HPP

#include <glad/glad.h>
#include "GLWindow.hpp"

class Scene: public GLWindow {
private:
    GLuint program;
    GLint vCol;
    
protected:
    void windowDidLoad();
    void render(int width, int height);
    void release();
};

#endif
