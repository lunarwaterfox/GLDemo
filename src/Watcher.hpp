#ifndef WATCHER_HPP
#define WATCHER_HPP

#include <glad/glad.h>
#include <linmath.h>

class Watcher {
protected:
    mat4x4 _view;
    mat4x4 _proj;
public:
    Watcher() noexcept;
    ~Watcher() noexcept;

    mat4x4& getViewMatrix();
    mat4x4& getProjectMatrix();
};


#endif
