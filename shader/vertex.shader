#version 150

in vec3 vPos;
in vec3 vCol;
in vec2 vTex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec3 color;
out vec2 texcord;

void main() {
    gl_Position = proj * view * model * vec4(vPos, 1.0);
    color = vCol;
    texcord = vTex;
}
