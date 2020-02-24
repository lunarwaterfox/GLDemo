#ifndef SCENE_HPP
#define SCENE_HPP

#include <glad/glad.h>
#include "GLWindow.hpp"
#include "NormalShaderProgram.hpp"
#include "BoardElement.hpp"

class Scene: public GLWindow {
private:
    NormalShaderProgram _shader;
//    BoardElement _board;
    
protected:
    void windowDidLoad();
    void render(int width, int height);
    void release();
};

#endif
