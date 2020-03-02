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
    vec4 vecView = view * model * vec4(vPos, 1.0);
    vecView.x = vecView.x / (1 - vecView.z);
    vecView.y = vecView.y / (1 - vecView.z);
    vecView.z = 0;

    gl_Position = vecView;

    color = vCol;
    texcord = vTex;
}
