#ifndef SHADERMANAGER_HPP
#define SHADERMANAGER_HPP

#include <glad/glad.h>
#include "NormalShaderProgram.hpp"

class ShaderManager {
public:
    static ShaderManager* sharedManager();
    GLuint getNormalProgram();
private:
    ShaderManager();
    ShaderManager(const ShaderManager&);
    ShaderManager& operator=(const ShaderManager&);
    
    NormalShaderProgram _shader;
};


#endif
