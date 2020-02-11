#ifndef PHYSICS_BODIES2D_HPP
#define PHYSICS_BODIES2D_HPP
#include "Shapes2D.hpp"

namespace Physics {

	struct Rigidbody2D {
		// should this body be updated
		bool simulate = false;
		unsigned int id;

		// body position/rotation variables
		float2 position = float2(0.0f);
		float2 velocity = float2(0.0f);
		float2 acceleration = float2(0.0f);
		float2 rotation = float2(0.0f);
		float2 angularVelocity = float2(0.0f);
		float2 angularAcceleration = float2(0.0f);

		// body shape variables
		ShapeType2D shapeType = ShapeType2D::AABox;
		union { // this is to reduce the memory usage while still keeping it value only
			Circle2D circleShape;
			Line2D lineShape;
			Capsule2D capsuleShape;
			Box2D boxShape;
			AABox2D aaboxShape;
		};

		Rigidbody2D(float2 position_ = 0.0f) {
			aaboxShape = AABox2D();
			static unsigned int __id__ = 0;
			id = __id__++;
			position = position_;
		}
	};

	struct Staticbody2D {
		// should this body be updated
		bool simulate = true;
		unsigned int id;

		// body position/rotation variables
		float2 position;
		float2 rotation;

		// body shape variables
		ShapeType2D shapeType = ShapeType2D::AABox;
		union { // this is to reduce the memory usage while still keeping it value only
			Circle2D circleShape;
			Line2D lineShape;
			Capsule2D capsuleShape;
			Box2D boxShape;
			AABox2D aaboxShape;
		};

		Staticbody2D(float2 position_ = 0.0f) {
			aaboxShape = AABox2D();
			static unsigned int __id__ = 0;
			id = __id__++;
			position = position_;
		}
	};
}

#endif // !PHYSICS_BODIES2D_HPP