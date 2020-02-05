#ifndef BODY_H
#define BODY_H
#include "../Common.h"
#include "../Component.h"
#include "../Math/Bounds.h"

class Collider;
class Transform;

enum class BodyType : ubyte {
	Dynamic,
	Kinematic,
	Static,
};

class Body : public Component {
	// friend of PhysicsScene
	friend class PhysicsScene;

	// is this body: Dynamic, Kinematic, Static
	BodyType bodyType;

	// the connected collider
	Collider* collider;

	// physics variables
	vec2 velocity;
	vec2 acceleration;
	float angularVelocity;
	float angularAcceleration;

	/// private events

	// alerts all the other components connected to the gameobject
	void CollisionAlert();

public:

	Body();
	~Body();


	/// getters

	// returns the attached collider
	Collider* GetCollider() { return collider; }
	vec2 GetVelocity() { return velocity; }
	vec2 GetAcceleration() { return acceleration; }
	float GetAngularVelocity() { return angularVelocity; }
	float GetAngularAcceleration() { return angularAcceleration; }

	// returns the type of body
	BodyType GetBodyType() { return bodyType; }

	// returns an updated bounds
	Bounds GetNewBounds();


	/// setters

	// sets the attached collider
	// deletes the previous one
	// @param coll: the new collider
	void SetCollider(Collider* coll);

	// sets the type that makes this body
	// @param type: 
	void SetBodyType(const BodyType& bodyType_) { bodyType = bodyType_; }
	void SetVelocity(const vec2& velocity_) { velocity = velocity_; }
	void SetAcceleration(const vec2& acceleration_) { acceleration = acceleration_; }
	void SetAngularVelocity(const float& angularVelocity_) { angularVelocity = angularVelocity_;	}
	void SetAngularAcceleration(const float& angularAcceleration_) { angularAcceleration = angularAcceleration_; }

};


#endif // !BODY_H