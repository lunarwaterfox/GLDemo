#ifndef FOVWATCH_HPP
#define FOVWATCH_HPP

#include <glad/glad.h>
#include <linmath.h>
#include "Watcher.hpp"

class FovWatcher: public Watcher {
public:
    void lookAt(vec4 eye, vec4 center, vec4 up);
    void perspective(float fovyRadians, float aspect, float near, float far);
};


#endif
