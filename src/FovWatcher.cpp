#include "FovWatcher.hpp"

void FovWatcher::lookAt(vec4 eye, vec4 center, vec4 up) {
    mat4x4_look_at(_view, eye, center, up);
}

void FovWatcher::perspective(float fovyRadians, float aspect, float near, float far) {
    mat4x4_perspective(_proj, fovyRadians, aspect, near, far);
}
