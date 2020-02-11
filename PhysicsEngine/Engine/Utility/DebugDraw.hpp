#ifndef UTILITY_DEBUG_DRAW_HPP
#define UTILITY_DEBUG_DRAW_HPP
#include "../common.hpp"
#include <memory>
#include <glew.h>
#include "../Graphics/Shader.hpp"
#include "../Math/FloatVector.hpp"
#include "../Graphics/Color.hpp"
#include <list>

namespace Utility {
	
	class DebugDraw {
		SINGLETON_DECLERATION(DebugDraw) { }

		static Math::float2 lineVerts[];
		static Graphics::Shader lineShader;
		static GLuint lineVBO, lineVAO;
		static GLuint scalarLoc;
		static GLuint offsetLoc;
		static GLuint colorLoc;

		struct DrawRay {
			Math::float2 position;
			Math::float2 direction;
			Graphics::Color color;

			DrawRay(Math::float2 start_, Math::float2 end_, Graphics::Color color_)
				: position(start_), direction(end_ - start_), color(color_) { }
		};
		static std::list<DrawRay> drawRayList;

	public:

		void Init();
		void Exit();
		void DrawShapes();

		static void DrawCircle(Math::float2 position, float radius, Graphics::Color color = Graphics::Color::GREEN);
		static void DrawLine(Math::float2 start, Math::float2 end, Graphics::Color color = Graphics::Color::GREEN);

	};

}

#endif // !DEBUG_DRAW_HPP