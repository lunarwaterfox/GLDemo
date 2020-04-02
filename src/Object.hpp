#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <glad/glad.h>
#include <linmath.h>

class Object {
protected:
    mat4x4 _model;
public:
    Object() noexcept;
    virtual void createObject();
    virtual void render(GLuint program);

    void setModel(mat4x4 model);
};

#endif
