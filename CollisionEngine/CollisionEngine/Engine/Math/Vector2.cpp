#include "Vector2.hpp"
#include "Mathf.hpp"

namespace Math {

	float Vector2::Length() const {
		return Mathf::Sqrt(x * x + y * y);
	}

	float Vector2::SqrLength() const {
		return x * x + y * y;
	}

	void Vector2::Normalize() {
		float len = Length();
		x /= len;
		y /= len;
	}


	Vector2 Vector2::operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 Vector2::operator-(const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}
	Vector2 Vector2::operator*(const float& scalar) const {
		return Vector2(x * scalar, y * scalar);
	}
	Vector2 Vector2::operator/(const float& divisor) const {
		return Vector2(x / divisor, y / divisor);
	}

	Vector2& Vector2::operator+=(const Vector2& other) {
		x += other.x; y += other.y;
		return *this;
	}
	Vector2& Vector2::operator-=(const Vector2& other) {
		x -= other.x; y -= other.y;
		return *this;
	}
	Vector2& Vector2::operator*=(const float& scalar) {
		x *= scalar; y *= scalar;
		return *this;
	}
	Vector2& Vector2::operator/=(const float& divisor) {
		x /= divisor; y /= divisor;
		return *this;
	}

	Vector2 Vector2::operator-() const {
		return Vector2(-x, -y);
	}


	float Vector2::Dot(const Vector2& v0, const Vector2& v1) {
		return v0.x * v1.x + v0.y * v1.y;
	}

	Vector2 Vector2::Normalized(const Vector2& vec) {
		float len = vec.Length();
		if (Mathf::NearlyZero(len, 0.00000000000001f)) return Vector2::ZERO;
		return Vector2(vec.x / len, (vec.y / len));
	}

	Vector2 Vector2::Reflect(const Vector2& vec, const Vector2& normal) {
		return vec + normal * Vector2::Dot(-vec, normal) * 2.0f;
	}


	const Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);
	const Vector2 Vector2::UP = Vector2(0.0f, 1.0f);
	const Vector2 Vector2::DOWN = Vector2(0.0f, -1.0f);
	const Vector2 Vector2::LEFT = Vector2(-1.0f, 0.0f);
	const Vector2 Vector2::RIGHT = Vector2(1.0f, 0.0f);
}