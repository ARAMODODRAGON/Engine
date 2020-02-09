#include "Mathf.hpp"
#include <math.h>

namespace Math {

	float Mathf::Clamp(float value, const float& min, const float& max) {
		if (value < min) value = min; else if (value > max) value = max;
		return value;
	}

	float Mathf::Lerp(const float& first, const float& second, const float& percent) {
		return (second - first) * percent + first;
	}

	float Mathf::Abs(const float& value) {
		return (value < 0.0f ? -value : value);
	}

	bool Mathf::NearlyZero(const float& value, const float& percision) {
		return Abs(value) < percision;
	}

	bool Mathf::NearlyEqual(const float& valueA, const float& valueB, const float& percision) {
		return Abs(valueB - valueA) < percision;
	}

	float Mathf::Halfway(const float& valueA, const float& valueB) {
		return (valueA + valueB) / 2.0f;
	}

	float Mathf::Sqrt(const float& value) {
		return sqrtf(value);
	}
	

}