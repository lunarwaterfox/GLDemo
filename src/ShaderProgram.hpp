#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <glad/glad.h>

class ShaderProgram {
public:
    ShaderProgram() noexcept;
    virtual ~ShaderProgram() noexcept;
    void useProgram();
    GLuint getProgram();
    
    
protected:
    GLuint _program;

    virtual GLuint createPrograme();
};


#endif
