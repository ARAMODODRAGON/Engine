#ifndef PHYSICS_STATICBODY_HPP
#define PHYSICS_STATICBODY_HPP
#include "Body.hpp"

namespace Physics {

	class Staticbody : public Body {
		friend class Collisions;
		friend class PhysicsScene;

	public:

		Staticbody() { }
		virtual ~Staticbody() override { }

	};

}

#endif // !PHYSICS_STATICBODY_HPP