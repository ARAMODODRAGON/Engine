#ifndef DEBUG_HPP
#define DEBUG_HPP
#include "../Common.hpp"
#include "../Math/Vector2.hpp"
using Math::Vector2;
#include "../Rendering/Shader.hpp"
#include "../Physics/Bounds.hpp"

class Debug {

	static Shader shader;
	static GLuint scalarLoc;
	static GLuint offsetLoc;
	static GLuint colorLoc;

	static GLuint circleVBO, circleVAO;
	static GLuint lineVBO, lineVAO;

	struct CircleShape {
		Vector2 position;
		float radius;
		CircleShape(Vector2 position_, float radius_)
			: position(position_), radius(radius_) { }
	};
	static list<CircleShape> circleShapesList;

	struct LineShape {
		Vector2 position;
		Vector2 direction;
		LineShape(Vector2 start_, Vector2 end_)
			: position(start_), direction(end_ - start_) { }
	};
	static list<LineShape> lineShapesList;

public:

	static void Init();
	static void DrawShapes();
	static void Exit();

	static void Print(string text);
	static void PrintError(string text);

	static void DrawCircle(Vector2 position, float radius) {
		circleShapesList.push_back(CircleShape(position, radius));
	}
	static void DrawBounds(Bounds b) {
		lineShapesList.push_back(LineShape(
			Vector2(b.min.x, b.min.y),
			Vector2(b.min.x, b.max.y)
		));
		lineShapesList.push_back(LineShape(
			Vector2(b.min.x, b.max.y),
			Vector2(b.max.x, b.max.y)
		));
		lineShapesList.push_back(LineShape(
			Vector2(b.max.x, b.max.y),
			Vector2(b.max.x, b.min.y)
		));
		lineShapesList.push_back(LineShape(
			Vector2(b.max.x, b.min.y),
			Vector2(b.min.x, b.min.y)
		));
	}
	static void DrawLine(Vector2 start, Vector2 end) {
		lineShapesList.push_back(LineShape(start, end));
	}


};

#endif // !DEBUG_HPP