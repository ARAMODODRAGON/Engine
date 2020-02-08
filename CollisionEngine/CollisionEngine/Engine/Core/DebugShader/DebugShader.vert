#version 450 core
layout (location = 0) in vec2 vertpos;

uniform vec2 scalar;
uniform vec2 offset;

void main() {
	
	gl_Position = vec4(vertpos.x * scalar.x + offset.x, vertpos.y * scalar.y + offset.y, 0.0, 1.0);
	//gl_Position = vec4(vertpos, 0.0, 1.0);
}