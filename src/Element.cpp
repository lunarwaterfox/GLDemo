#include "Element.hpp"

Element::Element() noexcept {
    mat4x4_identity(_model);
    mat4x4_identity(_view);
    mat4x4_identity(_proj);
}

void Element::render(int width, int height) {

}
