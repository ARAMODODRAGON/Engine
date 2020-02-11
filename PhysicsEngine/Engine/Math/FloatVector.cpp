#include "FloatVector.hpp"
#include <math.h>

namespace Math {

	float Sqrt(const float& f) {
		return sqrtf(f);
	}

	float Abs(const float& f) {
		return (f < 0 ? -f : f);
	}

	float Clamp(float f, const float& min, const float& max) {
		if (f < min) f = min; else if (f > max) f = max;
		return f;
	}

	float Lerp(const float& a, const float& b, const float& t) {
		return (b - a) * t + a;
	}

	bool NearlyZero(const float& value, const float& percision) {
		return Abs(value) < percision;
	}

	bool NearlyEqual(const float& a, const float& b, const float& percision) {
		return Abs(b - a) < percision;
	}

	float Halfway(const float& a, const float& b) {
		return (a + b) / 2.0f;
	}


	float Length(const float3& f) {
		return sqrtf(f.x * f.x + f.y * f.y + f.z * f.z);
	}

	float SqrLength(const float3& f) {
		return f.x * f.x + f.y * f.y + f.z * f.z;
	}

	float3 Normalize(const float3& f) {
		float len = sqrtf(f.x * f.x + f.y * f.y + f.z * f.z);
		return float3(f.x / len, f.y / len, f.z / len);
	}

	float Dot(const float3& f0, const float3& f1) {
		return f0.x * f1.x + f0.y * f1.y + f0.z * f1.z;
	}

	float3 Relfect(const float3& direction, float3 normal) {
		return direction + normal * Dot(-direction, normal) * 2.0f;
	}


	#pragma region Operators

	float2 operator+(const float2& lhs, const float2& rhs) {
		return float2(lhs.x + rhs.x, lhs.y + rhs.y);
	}
	float2 operator-(const float2& lhs, const float2& rhs) {
		return float2(lhs.x - rhs.x, lhs.y - rhs.y);
	}
	float2 operator*(const float2& lhs, const float& scalar) {
		return float2(lhs.x * scalar, lhs.y * scalar);
	}
	float2 operator/(const float2& lhs, const float& divisor) {
		if (divisor == 0.0f) return float2(0.0f);
		return float2(lhs.x * divisor, lhs.y * divisor);
	}

	float2& operator+=(float2& lhs, const float2& rhs) {
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}
	float2& operator-=(float2& lhs, const float2& rhs) {
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}
	float2& operator*=(float2& lhs, const float& scalar) {
		lhs.x *= scalar;
		lhs.y *= scalar;
		return lhs;
	}
	float2& operator/=(float2& lhs, const float& divisor) {
		if (divisor == 0.0f) return lhs = float2(0.0f);
		lhs.x /= divisor;
		lhs.y /= divisor;
		return lhs;
	}


	float3 operator+(const float3& lhs, const float3& rhs) {
		return float3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}
	float3 operator-(const float3& lhs, const float3& rhs) {
		return float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}
	float3 operator*(const float3& lhs, const float& scalar) {
		return float3(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
	}
	float3 operator/(const float3& lhs, const float& divisor) {
		if (divisor == 0.0f) return float3(0.0f);
		return float3();
	}

	float3& operator+=(float3& lhs, const float3& rhs) {
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		return lhs;
	}
	float3& operator-=(float3& lhs, const float3& rhs) {
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		return lhs;
	}
	float3& operator*=(float3& lhs, const float& scalar) {
		lhs.x *= scalar;
		lhs.y *= scalar;
		lhs.z *= scalar;
		return lhs;
	}
	float3& operator/=(float3& lhs, const float& divisor) {
		if (divisor == 0.0f) return lhs = float3(0.0f);
		lhs.x /= divisor;
		lhs.y /= divisor;
		lhs.z /= divisor;
		return lhs;
	}
	float3 operator-(const float3& f) {
		return float3(-f.x, -f.y, -f.z);
	}

	#pragma endregion

}