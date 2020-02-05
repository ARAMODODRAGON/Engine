#include "CollisionChecker.h"
#include "../Engine/Physics/Transform.h"
#include "../Engine/Debug.h"
#include "../Engine/Physics/CircleCollider.h"

static vec2 verts[] = {
	vec2(-0.2f,  0.2f), // top left
	vec2(0.2f,  0.2f), // top right
	vec2(-0.2f, -0.2f), // bottom left
	vec2(0.2f, -0.2f), // bottom right
};

/// mesh shape:
/// 0 -- 1
///	|  / |
/// | /  |
/// 2 -- 3

static ivec3 indices[] = {
	ivec3(1, 0, 2), // triangle A
	ivec3(1, 2, 3), // triangle B
};

CollisionChecker::CollisionChecker()
	: drawColor(0.0f, 0.0f, 1.0f, 1.0f) // blue
	, shader()
	, VBO(0)
	, VAO(0)
	, EBO(0)
	, colorLoc(0)
	, posLoc(0)
	, bd(nullptr) 
	, cc(nullptr)
{ }

CollisionChecker::~CollisionChecker() { }

void CollisionChecker::OnCreate() {
	// load shader
	shader.LoadShader("Testing/Shaders/TempShader.vert", "Testing/Shaders/TempShader.frag");

	// create a VAO, VBO, and EBO
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind Vertex Array Object
	glBindVertexArray(VAO);
	// copy the indicies into a buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// copy the vertices into the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	// set the verticies to the location 0
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (GLvoid*)0);

	// get uniforms
	colorLoc = glGetUniformLocation(shader.GetProgramID(), "color");
	posLoc = glGetUniformLocation(shader.GetProgramID(), "offset");

	// setup components
	bd = CreateComponent<Body>();
	if (bd) {
		cc = new CircleCollider();
		cc->SetRadius(0.2f);
		bd->SetCollider(cc);
	}

	// set event flags
	AddEventFlags(EventFlags::Update);
	AddEventFlags(EventFlags::Draw);
	AddEventFlags(EventFlags::OnCollision);
}

void CollisionChecker::OnDestroy() {
	// unload shader
	shader.UnloadShader();

	// delete buffers
	glDeleteBuffers(1, &VAO);
	glDeleteVertexArrays(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void CollisionChecker::Update(const float& delta) {
	/// the following keeps the object from going off screen
	vec2 pos = GetTransform()->GetLocalPosition();

	if (pos.x > 1.0f) pos.x = -1.0f;
	if (pos.x < -1.0f) pos.x = 1.0f;
	if (pos.y > 1.0f) pos.y = -1.0f;
	if (pos.y < -1.0f) pos.y = 1.0f;

	GetTransform()->SetLocalPosition(pos);
}

void CollisionChecker::Draw() {

	// use the shader
	shader.UseProgram();

	// set uniforms
	glUniform4f(colorLoc, drawColor.r, drawColor.g, drawColor.b, drawColor.a);
	drawColor = color(0.0f, 0.0f, 1.0f, 1.0f);
	vec2 pos = GetTransform()->GetLocalPosition();
	glUniform2f(posLoc, pos.x, pos.y);

	// bind the EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	// draw using the EBO
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);

	// unbind
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// remove program
	glUseProgram(0);
	
}

void CollisionChecker::OnCollision() {
	// set color to red
	drawColor = color(1.0f, 0.0f, 0.0f, 1.0f);
}

void CollisionChecker::SetVelocity(vec2 vel) {
	if (bd) bd->SetVelocity(vel);
}
