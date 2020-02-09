#ifndef MATH_HPP
#define MATH_HPP

namespace Math {

	// a static class that contains common math functions
	class Mathf {
	public:

		static float Clamp(float value, const float& min, const float& max);
		static float Lerp(const float& first, const float& second, const float& percent);
		static float Abs(const float& value);
		static bool NearlyZero(const float& value, const float& percision = 0.01f);
		static bool NearlyEqual(const float& valueA, const float& valueB, const float& percision = 0.01f);
		static float Halfway(const float& valueA, const float& valueB);
		static float Sqrt(const float& value);
	};

}

#endif // !MATH_HPP