#ifndef VMATH_HPP
#define VMATH_HPP
#include "Vector2.hpp"

namespace Math {

	class VMath {
	public:

		/// static functions

		static float Dot(const Vector2& v0, const Vector2& v1);
		static Vector2 Normalized(const Vector2& vec);
		static Vector2 Reflect(const Vector2& vec, const Vector2& normal);

	};

}

#endif // !VMATH_HPP
