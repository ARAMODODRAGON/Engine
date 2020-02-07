#include "Vector2.hpp"
#include <math.h>

float Vector2::Length() {
	return sqrtf(x * x + y * y);
}

float Vector2::SqrLength() {
	return x * x + y * y;
}

Vector2 Vector2::Normalized() {
	float len = Length();
	return Vector2(x / len, y / len);
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
