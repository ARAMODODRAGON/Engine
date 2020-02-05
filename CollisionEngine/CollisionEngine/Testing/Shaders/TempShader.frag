#version 450 core
out vec4 fragcolor;

uniform vec4 color;

void main() {
	fragcolor = color;
}