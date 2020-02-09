#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace Math {
	struct Vector2 {

		float x, y;

		Vector2(const float& value = 0.0f) : x(value), y(value) { }
		Vector2(const float& x_, const float& y_) : x(x_), y(y_) { }


		/// functions

		float Length() const;
		float SqrLength() const;
		void Normalize();


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


		/// static functions

		static float Dot(const Vector2& v0, const Vector2& v1);
		static Vector2 Normalized(const Vector2& vec);
		static Vector2 Reflect(const Vector2& vec, const Vector2& normal);

		/// static constants

		static const Vector2 ZERO;
		static const Vector2 UP;
		static const Vector2 DOWN;
		static const Vector2 LEFT;
		static const Vector2 RIGHT;

	};
}

#endif // !VECTOR2_HPP