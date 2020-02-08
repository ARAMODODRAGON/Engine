#include "Debug.hpp"
#include "../Math/Point.hpp"
#include <iostream>


Shader Debug::shader;
GLuint Debug::scalarLoc = 0;
GLuint Debug::offsetLoc = 0;
GLuint Debug::colorLoc = 0;

GLuint Debug::circleVBO = 0;
GLuint Debug::circleVAO = 0;
GLuint Debug::boundsVAO = 0;
GLuint Debug::boundsVBO = 0;

list<Debug::CircleShape> Debug::circleShapes_list;
list<Debug::BoundsShape> Debug::boundsShapes_list;

#pragma region vertex and indices arrays

static Vector2 circleVerts[] = {
	Vector2(0.0f, -1.0f),
	Vector2(0.5f, -0.866f),
	Vector2(0.866f, -0.5f),
	Vector2(1.0f, 0.0f),
	Vector2(0.866f, 0.5f),
	Vector2(0.5f, 0.866f),
	Vector2(0.0f, 1.0f),
	Vector2(-0.5f, 0.866f),
	Vector2(-0.866f, 0.5f),
	Vector2(-1.0f, 0.0f),
	Vector2(-0.866f, -0.5f),
	Vector2(-0.5f, -0.866f),
};

static Vector2 boundsVerts[] = {
	Vector2(-1.0f, -1.0f),
	Vector2(1.0f, -1.0f),
	Vector2(1.0f, 1.0f),
	Vector2(-1.0f, 1.0f),
	Vector2(-1.0f, -1.0f),
};

#pragma endregion


void Debug::Init() {
	shader.LoadShader("Engine/Core/DebugShader/DebugShader.vert", "Engine/Core/DebugShader/DebugShader.frag");

	scalarLoc = 0; colorLoc = 0;

	glGenBuffers(1, &circleVBO);
	glGenVertexArrays(1, &circleVAO);
	glBindVertexArray(circleVAO);
	glBindBuffer(GL_ARRAY_BUFFER, circleVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circleVerts), circleVerts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vector2), (GLvoid*)0);

	glGenBuffers(1, &boundsVBO);
	glGenVertexArrays(1, &boundsVAO);
	glBindVertexArray(boundsVAO);
	glBindBuffer(GL_ARRAY_BUFFER, boundsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(boundsVerts), boundsVerts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vector2), (GLvoid*)0);


	shader.UseProgram();
	scalarLoc = glGetUniformLocation(shader.GetProgramID(), "scalar");
	offsetLoc = glGetUniformLocation(shader.GetProgramID(), "offset");
	colorLoc = glGetUniformLocation(shader.GetProgramID(), "color");
}

void Debug::DrawShapes() {
	shader.UseProgram();
	glUniform4f(colorLoc, 0.0f, 1.0f, 0.0f, 1.0f); // green

	glBindVertexArray(circleVAO);
	for (CircleShape& circle : circleShapes_list) {

		glUniform2f(scalarLoc, circle.radius, circle.radius);
		glUniform2f(offsetLoc, circle.position.x, circle.position.y);

		// draw circles
		glDrawArrays(GL_LINE_LOOP, 0, 12);

	}
	circleShapes_list.clear();

	glBindVertexArray(boundsVAO);
	for (BoundsShape& bound : boundsShapes_list) {

		glUniform2f(scalarLoc, bound.extents.x, bound.extents.y);
		glUniform2f(offsetLoc, bound.position.x, bound.position.y);

		// draw bounds
		glDrawArrays(GL_LINE_LOOP, 0, 4);
	}
	boundsShapes_list.clear();

	glBindVertexArray(0);
}

void Debug::Exit() {
	shader.UnloadShader();

	glDeleteVertexArrays(1, &circleVAO);
	glDeleteBuffers(1, &circleVBO);
	glDeleteVertexArrays(1, &boundsVAO);
	glDeleteBuffers(1, &boundsVBO);
}

void Debug::Print(std::string text) {
	std::cout << text << std::endl;
}

void Debug::PrintError(std::string text) {
	std::cout << "[ERROR]: " << text << std::endl;
}

