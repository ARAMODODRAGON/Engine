#ifndef MATH_FLOAT_VECTOR_HPP
#define MATH_FLOAT_VECTOR_HPP

namespace Math {

	float Sqrt(const float& f);
	float Abs(const float& f);

	struct float2 {
		float x, y;

		float2(float value = 0.0f) 
			: x(value), y(value) { }
		float2(float x_, float y_) 
			: x(x_), y(y_) { }
	};

	float2 operator+(const float2& lhs, const float2& rhs);
	float2 operator-(const float2& lhs, const float2& rhs);
	float2 operator*(const float2& lhs, const float& scalar);
	float2 operator/(const float2& lhs, const float& divisor);

	float2& operator+=(float2& lhs, const float2& rhs);
	float2& operator-=(float2& lhs, const float2& rhs);
	float2& operator*=(float2& lhs, const float& scalar);
	float2& operator/=(float2& lhs, const float& divisor);

	struct float3 {
		float x, y, z;

		float3(float value = 0.0f) 
			: x(value), y(value), z(value) { }
		float3(float x_, float y_, float z_) 
			: x(x_), y(y_), z(z_) { }
	};

	float3 operator+(const float3& lhs, const float3& rhs);
	float3 operator-(const float3& lhs, const float3& rhs);
	float3 operator*(const float3& lhs, const float& scalar);
	float3 operator/(const float3& lhs, const float& divisor);

	float3& operator+=(float3& lhs, const float3& rhs);
	float3& operator-=(float3& lhs, const float3& rhs);
	float3& operator*=(float3& lhs, const float& scalar);
	float3& operator/=(float3& lhs, const float& divisor);

	float3 operator-(const float3& f);

	float Length(const float3& f);
	float SqrLength(const float3& f);
	float3 Normalize(const float3& f);
	float Dot(const float3& f0, const float3& f1);
	float3 Relfect(const float3& direction, float3 normal);

	struct float4 {
		float x, y, z, w;

		float4(float value = 0.0f) 
			: x(value), y(value), z(value), w(value) { }
		float4(float x_, float y_, float z_, float w_) 
			: x(x_), y(y_), z(z_), w(w_) { }
	};




}

#endif // !MATH_FLOAT_VECTOR_HPP