#ifndef BODY_H
#define BODY_H
#include "../Common.h"

class Collider;
class Transform;

enum class BodyType : ubyte {
	Dynamic,
	Kinematic,
	Static,
};

class Body { 
	// body and collider are friends
	friend class Collider;

	// is this body: Dynamic, Kinematic, Static
	BodyType bodyType;

	// the connected collider and transform
	Transform* transform;
	Collider* collider;

	// physics variables
	vec2 velocity;
	vec2 acceleration;

public:

	Body();
	~Body();


	/// getters

	// returns the attached collider
	Collider* GetCollider() { return collider; }

	// returns the type of body
	BodyType GetBodyType() { return bodyType; }

	// returns the attached transform
	Transform* GetTransform() { return transform; }

	/// setters

	// sets the attached collider
	// delets the previous one
	// @param coll: the new collider
	void SetCollider(Collider* coll);

	// sets the attached transform
	void SetTransform(Transform* transform);

	// sets the type that makes this body
	// @param type: 
	void SetBodyType(const BodyType& type);

	// 

};


#endif // !BODY_H