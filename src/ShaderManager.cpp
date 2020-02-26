#include "ShaderManager.hpp"

ShaderManager* ShaderManager::sharedManager() {
    static ShaderManager manager;
    
    return &manager;
}

GLuint ShaderManager::getNormalProgram() {
    return 0;
}
