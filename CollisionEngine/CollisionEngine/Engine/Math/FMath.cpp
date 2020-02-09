#include "FMath.hpp"
#include <math.h>

namespace Math {

	float FMath::Clamp(float value, const float& min, const float& max) {
		if (value < min) value = min; else if (value > max) value = max;
		return value;
	}

	float FMath::Lerp(const float& first, const float& second, const float& percent) {
		return (second - first) * percent + first;
	}

	float FMath::Abs(const float& value) {
		return (value < 0.0f ? -value : value);
	}

	bool FMath::NearlyZero(const float& value, const float& percision) {
		return Abs(value) < percision;
	}

	bool FMath::NearlyEqual(const float& valueA, const float& valueB, const float& percision) {
		return Abs(valueB - valueA) < percision;
	}

	float FMath::Halfway(const float& valueA, const float& valueB) {
		return (valueA + valueB) / 2.0f;
	}

	float FMath::Sqrt(const float& value) {
		return sqrtf(value);
	}
	

}