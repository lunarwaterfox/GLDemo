#ifndef NORMALWORLDPROGRAM_HPP
#define NORMALWORLDPROGRAM_HPP

#include <glad/glad.h>
#include "Watcher.hpp"

class NormalWorldProgram {
private:
    GLuint _program;
    static GLuint createProgram();

    const Watcher* _watcher;
public:
    NormalWorldProgram() noexcept;
    ~NormalWorldProgram() noexcept;
    GLuint getProgram();

    void bindWatcher(const Watcher* watcher);
    void render();
};


#endif
