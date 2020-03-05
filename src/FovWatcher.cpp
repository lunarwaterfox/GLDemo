#include "FovWatcher.hpp"

void FovWatcher::lookAt(vec4 eye, vec4 center, vec4 up) {
    mat4x4 viewScale = {
        {2.0f / 1000, 0.0f,          0.0f, 0.0f},
        {0.0f,         2.0f / 1000, 0.0f, 0.0f},
        {0.0f,         0.0f,          1.0f, 0.0f},
        {0.0f,         0.0f,          0.0f, 1.0f}
    };


    mat4x4_identity(_view);
    mat4x4_mul(_view, _view, viewScale);
}

void FovWatcher::perspective(float fovyRadians, float aspect, float near, float far) {

}
