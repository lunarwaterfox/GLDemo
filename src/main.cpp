#include "GLFWManager.hpp"

int main(int argc, char* argv[]) {
    GLFWManager manager;

    try {
        manager.init();
        manager.render();
    } catch (GLFWException e) {
        return 1;
    }

    return 0;
}
