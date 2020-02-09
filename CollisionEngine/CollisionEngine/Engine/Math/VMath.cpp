#include "VMath.hpp"
#include "FMath.hpp"

namespace Math {

	float VMath::Dot(const Vector2& v0, const Vector2& v1) {
		return v0.x * v1.x + v0.y * v1.y;
	}

	Vector2 VMath::Normalized(const Vector2& vec) {
		float len = vec.Length();
		if (FMath::NearlyZero(len, 0.00000000000001f)) return Vector2::ZERO;
		return Vector2(vec.x / len, (vec.y / len));
	}

	Vector2 VMath::Reflect(const Vector2& vec, const Vector2& normal) {
		return vec + normal * Dot(-vec, normal) * 2.0f;
	}

}