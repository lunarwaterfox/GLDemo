#include "Object.hpp"

Object::Object() noexcept {
    mat4x4_identity(_model);
}

void Object::render(GLuint program) {
}

void Object::createObject() {
}
