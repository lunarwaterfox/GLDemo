#include "Watcher.hpp"
#include <iostream>

Watcher::Watcher() noexcept {
    mat4x4_identity(_view);
    mat4x4_identity(_proj);
}

Watcher::Watcher(Watcher& watcher) noexcept {
    mat4x4_dup(_view, watcher._view);
    mat4x4_dup(_proj, watcher._proj);
}

Watcher& Watcher::operator=(Watcher& watcher) noexcept {
    mat4x4_dup(this->_view, watcher._view);
    mat4x4_dup(this->_proj, watcher._proj);

    return *this;
}

const mat4x4& Watcher::getViewMatrix() const {
    return _view;
}

const mat4x4& Watcher::getProjectMatrix() const {
    return _proj;
}

void Watcher::appendObject(Object& obj) {
    obj.createObject();
    _objects.push_back(&obj);
}

void Watcher::render(GLuint program) const {
    for (auto obj: _objects) {
        obj->render(program);
    }
}

Watcher::~Watcher() noexcept {

}
