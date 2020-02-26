#include "ShaderManager.hpp"


ShaderManager::ShaderManager() {
    
}

ShaderManager::ShaderManager(const ShaderManager&) {
    
    
}

ShaderManager& ShaderManager::operator=(const ShaderManager&) {
    return *this;
}


ShaderManager* ShaderManager::sharedManager() {
    static ShaderManager manager;
    
    return &manager;
}

GLuint ShaderManager::getNormalProgram() {
    return _shader.getProgram();
}
