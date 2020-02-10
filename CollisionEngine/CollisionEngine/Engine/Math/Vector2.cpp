#include "Vector2.hpp"
#include "FMath.hpp"

namespace Math {

	float Vector2::Length() const {
		return FMath::Sqrt(x * x + y * y);
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

	bool Vector2::operator==(const Vector2& other) const {
		return x == other.x && y == other.y;
	}

	bool Vector2::operator!=(const Vector2& other) const {
		return x != other.x || y != other.y;
	}

	const Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);
	const Vector2 Vector2::UP = Vector2(0.0f, 1.0f);
	const Vector2 Vector2::DOWN = Vector2(0.0f, -1.0f);
	const Vector2 Vector2::LEFT = Vector2(-1.0f, 0.0f);
	const Vector2 Vector2::RIGHT = Vector2(1.0f, 0.0f);
}