#ifndef SCENE_HPP
#define SCENE_HPP

#include <glad/glad.h>
#include "GLWindow.hpp"

class Scene: public GLWindow {
private:
    GLint mvp_location;
    GLuint program;
    
protected:
    void windowDidLoad();
    void render(int width, int height);
};

#endif
