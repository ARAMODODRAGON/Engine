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
	static GLuint boundsVBO, boundsVAO;

	struct CircleShape {
		Vector2 position;
		float radius;
		CircleShape(Vector2 position_, float radius_)
			: position(position_), radius(radius_) { }
	};
	static list<CircleShape> circleShapes_list;

	struct BoundsShape {
		Vector2 position;
		Vector2 extents;
		BoundsShape(Vector2 position_, Vector2 extents_)
			: position(position_), extents(extents_) { }
	};
	static list<BoundsShape> boundsShapes_list;


public:

	static void Init();
	static void DrawShapes();
	static void Exit();

	static void Print(string text);
	static void PrintError(string text);

	static void DrawCircle(Vector2 position, float radius) {
		circleShapes_list.push_back(CircleShape(position, radius));
	}
	static void DrawBounds(Bounds b) {
		Vector2 extents;
		extents.x = (b.max.x - b.min.x) / 2.0f;
		extents.y = (b.max.y - b.min.y) / 2.0f;
		Vector2 position;
		position.x = b.min.x + extents.x;
		position.y = b.min.y + extents.y;
		boundsShapes_list.push_back(BoundsShape(position, extents));
	}


};

#endif // !DEBUG_HPP