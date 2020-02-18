#version 150

//uniform vec3 triangleColor;

in vec3 color;
in vec2 tr;
 
out vec4 outColor;
uniform sampler2D tex;

void main() {
    outColor = texture(tex, tr) * vec4(color, 1.0);
}