#ifndef PARALLELWATCHER_HPP
#define PARALLELWATCHER_HPP

#include <glad/glad.h>
#include <linmath.h>
#include "Watcher.hpp"

class ParallelWatcher: public Watcher {
public:
    void lookAt(vec4 eye, vec4 center, vec4 up);
    void ortho(float left, float right, float bottom, float top, float near, float far);
};



#endif
