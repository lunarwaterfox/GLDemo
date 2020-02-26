#version 150

in vec3 color;
in vec2 texcord;
 
out vec4 outColor;
uniform sampler2D sampler;

void main() {
    outColor = texture(sampler, texcord) * vec4(color, 1.0);
}