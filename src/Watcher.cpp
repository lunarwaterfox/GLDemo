#include "Watcher.hpp"

Watcher::Watcher() noexcept {
    mat4x4_identity(_view);
    mat4x4_identity(_proj);
}

mat4x4& Watcher::getViewMatrix() {
    return _view;
}

mat4x4& Watcher::getProjectMatrix() {
    return _proj;
}

Watcher::~Watcher() noexcept {

}
