#include "DebugDraw.hpp"

namespace Utility {

	SINGLETON_DEFINITION(DebugDraw);

	Math::float2 DebugDraw::lineVerts[] = {
		Math::float2(0.0f),
		Math::float2(1.0f),
	};
	Graphics::Shader DebugDraw::lineShader;
	GLuint DebugDraw::lineVBO = 0;
	GLuint DebugDraw::lineVAO = 0;
	GLuint DebugDraw::scalarLoc = 0;
	GLuint DebugDraw::offsetLoc = 0;
	GLuint DebugDraw::colorLoc = 0;
	std::list<DebugDraw::DrawRay> DebugDraw::drawRayList;


	void DebugDraw::Init() {
		// setup the two verts
		glGenBuffers(1, &lineVBO);
		glGenVertexArrays(1, &lineVAO);
		glBindVertexArray(lineVAO);
		glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(lineVerts), lineVerts, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Math::float2), (GLvoid*)0);

		lineShader.LoadShader("Engine/Utility/DebugDrawShader/LineShader.vert", "Engine/Utility/DebugDrawShader/LineShader.frag");
		lineShader.UseProgram();
		scalarLoc = glGetUniformLocation(lineShader.GetProgramID(), "scalar");
		offsetLoc = glGetUniformLocation(lineShader.GetProgramID(), "offset");
		colorLoc = glGetUniformLocation(lineShader.GetProgramID(), "color");
	}

	void DebugDraw::Exit() {
		lineShader.UnloadShader();

		glDeleteVertexArrays(1, &lineVAO);
		glDeleteBuffers(1, &lineVBO);
	}

	void DebugDraw::DrawShapes() {
		lineShader.UseProgram();

		glBindVertexArray(lineVAO);
		for (DrawRay& ray : drawRayList) {

			glUniform4f(colorLoc, ray.color.r, ray.color.g, ray.color.b, ray.color.a);
			glUniform2f(scalarLoc, ray.direction.x, ray.direction.y);
			glUniform2f(offsetLoc, ray.position.x, ray.position.y);

			// draw lines
			glDrawArrays(GL_LINE_LOOP, 0, 4);
		}
		drawRayList.clear();

		glUseProgram(0);
		glBindVertexArray(0);
	}

	//	0.0f, -1.0f
	//	0.5f, -0.866f
	//	0.866f, -0.5f
	//	1.0f, 0.0f
	//	0.866f, 0.5f
	//	0.5f, 0.866f
	//	0.0f, 1.0f
	//	-0.5f, 0.866f
	//	-0.866f, 0.5f
	//	-1.0f, 0.0f
	//	-0.866f, -0.5f
	//	-0.5f, -0.866f
	
	void DebugDraw::DrawCircle(Math::float2 position, float radius, Graphics::Color color) {
		// draw 13 lines
		DrawLine(Math::float2(0.0f, -1.0f) * radius + position, Math::float2(0.5f, -0.866f) * radius + position, color);
		DrawLine(Math::float2(0.5f, -0.866f) * radius + position, Math::float2(0.866f, -0.5f) * radius + position, color);
		DrawLine(Math::float2(0.866f, -0.5f) * radius + position, Math::float2(1.0f, 0.0f) * radius + position, color);
		
		DrawLine(Math::float2(1.0f, 0.0f) * radius + position, Math::float2(0.866f, 0.5f) * radius + position, color);
		DrawLine(Math::float2(0.866f, 0.5f) * radius + position, Math::float2(0.5f, 0.866f) * radius + position, color);
		DrawLine(Math::float2(0.5f, 0.866f) * radius + position, Math::float2(0.0f, 1.0f) * radius + position, color);
		
		DrawLine(Math::float2(0.0f, 1.0f) * radius + position, Math::float2(-0.5f, 0.866f) * radius + position, color);
		DrawLine(Math::float2(-0.5f, 0.866f) * radius + position, Math::float2(-0.866f, 0.5f) * radius + position, color);
		DrawLine(Math::float2(-0.866f, 0.5f) * radius + position, Math::float2(-1.0f, 0.0f) * radius + position, color);
		
		DrawLine(Math::float2(-1.0f, 0.0f) * radius + position, Math::float2(-0.866f, -0.5f) * radius + position, color);
		DrawLine(Math::float2(-0.866f, -0.5f) * radius + position, Math::float2(-0.5f, -0.866f) * radius + position, color);
		DrawLine(Math::float2(-0.5f, -0.866f) * radius + position, Math::float2(0.0f, -1.0f) * radius + position, color);
		
	}

	void DebugDraw::DrawLine(Math::float2 start, Math::float2 end, Graphics::Color color) {
		singleton->drawRayList.push_back(DrawRay(start, end, color));
	}


}
