#ifndef NORMALWORLDPROGRAM_HPP
#define NORMALWORLDPROGRAM_HPP

#include <glad/glad.h>
#include "Watcher.hpp"

class NormalWorldProgram {
private:
    GLuint _program;
    Watcher* _watcher;
    static GLuint createProgram();

public:
    NormalWorldProgram() noexcept;
    ~NormalWorldProgram() noexcept;
    GLuint getProgram();

    void bindWatcher(Watcher &watcher);
    void render();
};


#endif
