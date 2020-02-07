#ifndef VECTOR2_HPP
#define VECTOR2_HPP

struct Vector2 {

	float x, y;

	Vector2(const float& value = 0.0f) : x(value), y(value) { }
	Vector2(const float& x_, const float& y_) : x(x_), y(y_) { }

	float Length();
	float SqrLength();
	Vector2 Normalized();

	/// operators

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(const float& scalar) const;
	Vector2 operator/(const float& divisor) const;

	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2& operator*=(const float& scalar);
	Vector2& operator/=(const float& divisor);

	Vector2 operator-() const;


	static float Dot(const Vector2& v0, const Vector2& v1);
};

#endif // !VECTOR2_HPP