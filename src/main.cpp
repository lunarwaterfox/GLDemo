#include "GLFWManager.hpp"
#include "Scene.hpp"

int main(int argc, char* argv[]) {
    GLFWManager manager;
    Scene window;

    try {
        manager.init();
        manager.makeWindowCurrent(window);
    } catch (GLFWException e) {
        return 1;
    }

    return 0;
}
