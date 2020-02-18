#version 150

in vec2 position;
in vec3 col;
in vec2 texcoord;

out vec3 color;
out vec2 tr;

void main() {
    gl_Position = vec4(position, 0.0, 1.0);
    color = col;
    tr = texcoord;
}
