#ifndef DEBUG_HPP
#define DEBUG_HPP
#include "../Common.hpp"
#include "../Math/Vector2.hpp"
using Math::Vector2;
#include "../Rendering/Shader.hpp"
#include "../Physics/Bounds.hpp"
#include "../Rendering/Shader.hpp"
using Rendering::Shader;
#include "../Rendering/Color.hpp"
using Rendering::Color;

class Debug {

	static Shader shader;
	static GLuint scalarLoc;
	static GLuint offsetLoc;
	static GLuint colorLoc;

	static GLuint circleVBO, circleVAO;
	static GLuint lineVBO, lineVAO;

	struct CircleShape {
		Color color;
		Vector2 position;
		float radius;
		CircleShape(Vector2 position_, float radius_, Color color_ = Color::WHITE)
			: position(position_), radius(radius_), color(color_) { }
	};
	static list<CircleShape> circleShapesList;

	struct LineShape {
		Color color;
		Vector2 position;
		Vector2 direction;
		LineShape(Vector2 start_, Vector2 end_, Color color_ = Color::WHITE)
			: position(start_), direction(end_ - start_), color(color_) { }
	};
	static list<LineShape> lineShapesList;

public:

	static void Init();
	static void DrawShapes();
	static void Exit();

	static void Print(string text);
	static void PrintError(string text);

	static void DrawCircle(Vector2 position, float radius, Color color = Color::WHITE) {
		circleShapesList.push_back(CircleShape(position, radius, color));
	}
	static void DrawBounds(Bounds b, Color color = Color::WHITE) {
		lineShapesList.push_back(LineShape(
			Vector2(b.min.x, b.min.y),
			Vector2(b.min.x, b.max.y),
			color
		));
		lineShapesList.push_back(LineShape(
			Vector2(b.min.x, b.max.y),
			Vector2(b.max.x, b.max.y),
			color
		));
		lineShapesList.push_back(LineShape(
			Vector2(b.max.x, b.max.y),
			Vector2(b.max.x, b.min.y),
			color
		));
		lineShapesList.push_back(LineShape(
			Vector2(b.max.x, b.min.y),
			Vector2(b.min.x, b.min.y),
			color
		));
	}
	static void DrawLine(Vector2 start, Vector2 end, Color color = Color::GREEN) {
		lineShapesList.push_back(LineShape(start, end, color));
	}


};

#endif // !DEBUG_HPP