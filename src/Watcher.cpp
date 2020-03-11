#include "Watcher.hpp"

Watcher::Watcher() noexcept {
    mat4x4_identity(_view);
    mat4x4_identity(_proj);
}

const mat4x4& Watcher::getViewMatrix() const {
    return _view;
}

const mat4x4& Watcher::getProjectMatrix() const {
    return _proj;
}

void Watcher::appendObject(Object* obj) {
    obj->createObject();
    _objects.push_back(obj);
}

void Watcher::render(GLuint program) const {
    for (auto obj: _objects) {
        obj->render(program);
    }
}

Watcher::~Watcher() noexcept {

}
