#ifndef GLFWEXCEPTION_HPP
#define GLFWEXCEPTION_HPP

#include <exception>
#include <string>

using namespace std;

class GLFWException: public exception {
private:
    string desc;
public:
    GLFWException(string desc) noexcept;
};

#endif
