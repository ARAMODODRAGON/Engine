#ifndef PHYSICS_BODIES_HPP
#define PHYSICS_BODIES_HPP
#include "Shapes.hpp"

namespace Physics {

	struct Rigidbody {
		// should this body be updated
		bool simulate = false;
		unsigned int id;

		// body position/rotation variables
		float3 position = float3(0.0f);
		float3 velocity = float3(0.0f);
		float3 acceleration = float3(0.0f);
		float3 rotation = float3(0.0f);
		float3 angularVelocity = float3(0.0f);
		float3 angularAcceleration = float3(0.0f);

		// body shape variables
		ShapeType shapeType = ShapeType::Sphere;
		union { // this is to reduce the memory usage while still keeping it value only
			Sphere sphereShape;
			Line lineShape;
			Capsule capsuleShape;
			Plane planeShape;
			Box boxShape;
		};

		Rigidbody(float3 position_ = 0.0f) {
			sphereShape = Sphere();
			static unsigned int __id__ = 0;
			id = __id__++;
			position = position_;
		}
	};

	struct Staticbody {
		// should this body be updated
		bool simulate = true;
		unsigned int id;

		// body position/rotation variables
		float3 position;
		float3 rotation;

		// body shape variables
		ShapeType shapeType = ShapeType::Sphere;
		union { // this is to reduce the memory usage while still keeping it value only
			Sphere circleShape;
			Line lineShape;
			Capsule capsuleShape;
			Plane planeShape;
			Box boxShape;
		};

		Staticbody(float3 position_ = 0.0f) {
			circleShape = Sphere();
			static unsigned int __id__ = 0;
			id = __id__++;
			position = position_;
		}
	};
}

#endif // !PHYSICS_BODIES_HPP