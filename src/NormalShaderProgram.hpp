#ifndef NORMALSHADERPROGRAM_HPP
#define NORMALSHADERPROGRAM_HPP

#include <glad/glad.h>
#include "ShaderProgram.hpp"

class NormalShaderProgram: public ShaderProgram {
private:
    GLuint createPrograme();
    
public:
    NormalShaderProgram() noexcept;
    ~NormalShaderProgram() noexcept;
};


#endif
