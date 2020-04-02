#include "Object.hpp"

Object::Object() noexcept {
    mat4x4_identity(_model);
}

void Object::render(GLuint program) {
}

void Object::createObject() {
}

void Object::setModel(mat4x4 model) {
    mat4x4_dup(_model, model);
}
