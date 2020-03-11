#include "FovWatcher.hpp"
#include <iostream>

void FovWatcher::lookAt(vec4 eye, vec4 center, vec4 up) {
    mat4x4 lookAtMatrix;

    mat4x4_look_at(lookAtMatrix, eye, center, up);
    mat4x4_transpose(_view, lookAtMatrix);

    std::cout << _view[0][0] << ":" << _view[0][1] << ":" << _view[0][2] << ":" << _view[0][3] << std::endl
              << _view[1][0] << ":" << _view[1][1] << ":" << _view[1][2] << ":" << _view[1][3] << std::endl
              << _view[2][0] << ":" << _view[2][1] << ":" << _view[2][2] << ":" << _view[2][3] << std::endl
              << _view[3][0] << ":" << _view[3][1] << ":" << _view[3][2] << ":" << _view[3][3] << std::endl
              << std::endl;
}

void FovWatcher::perspective(float fovyRadians, float aspect, float near, float far) {
    // mat4x4_perspective(_proj, fovyRadians, aspect, near, far);
    // mat4x4_transpose(_proj, _proj);

    mat4x4 viewScale = {
        {1.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 1000.0f}
    };

    mat4x4_dup(_proj, viewScale);
}
