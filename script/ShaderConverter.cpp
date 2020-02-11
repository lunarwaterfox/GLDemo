#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream vertexFile(argv[1]);
    ifstream fragmentFile(argv[2]);
    ofstream headerFile("Shader.hpp");
    ofstream srcFile("Shader.cpp");
    string line;
    
    headerFile << "#ifndef SHADER_HPP" << endl;
    headerFile << "#define SHADER_HPP" << endl;
    headerFile << "namespace Shader {" << endl;
    headerFile << "const char* getVertexShader();" << endl;
    headerFile << "const char* getFragmentShader();" << endl;
    headerFile << "}" << endl;
    headerFile << "#endif" << endl;
    
    srcFile << "#include \"Shader.hpp\"" << endl;
    srcFile << "const char* Shader::getVertexShader() {" << endl;
    srcFile << "    static const char* shader_str =" << endl;
    
    while (getline(vertexFile, line)) {
        srcFile << "        \"" << line << "\\n\"" << endl;
    }
    
    srcFile << "    ;" << endl;
    srcFile << "    return shader_str;" << endl;
    srcFile << "}" << endl;
    
    srcFile << "const char* Shader::getFragmentShader() {" << endl;
    srcFile << "    static const char* shader_str =" << endl;
    
    while (getline(fragmentFile, line)) {
        srcFile << "        \"" << line << "\\n\"" << endl;
    }
    
    srcFile << "    ;" << endl;
    srcFile << "    return shader_str;" << endl;
    srcFile << "}" << endl;
    
    
    
    return 0;
}
