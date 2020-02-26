#ifndef SHADERMANAGER_HPP
#define SHADERMANAGER_HPP

#include <glad/glad.h>
#include "NormalShaderProgram.hpp"

class ShaderManager {
public:
    static ShaderManager* sharedManager();
    GLuint getNormalProgram();
};


#endif
