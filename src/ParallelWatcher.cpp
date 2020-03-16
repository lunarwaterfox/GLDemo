#include "ParallelWatcher.hpp"

void ParallelWatcher::lookAt(vec4 eye, vec4 center, vec4 up) {
    mat4x4_look_at(_view, eye, center, up);
}

void ParallelWatcher::ortho(float left, float right, float bottom, float top, float near, float far) {
    mat4x4_ortho(_proj, left, right, bottom, top, near, far);
}
