#ifndef WATCHER_HPP
#define WATCHER_HPP

#include <glad/glad.h>
#include <linmath.h>
#include <vector>
#include "Object.hpp"

class Watcher {
protected:
    mat4x4 _view;
    mat4x4 _proj;
    
    std::vector<Object *> _objects;
public:
    Watcher() noexcept;
    Watcher(Watcher& watcher) noexcept;
    Watcher& operator=(Watcher& watcher) noexcept;
    ~Watcher() noexcept;
    
    mat4x4& getViewMatrix();
    mat4x4& getProjectMatrix();
    
    void appendObject(Object& obj);
    void render(GLuint program);
};


#endif
