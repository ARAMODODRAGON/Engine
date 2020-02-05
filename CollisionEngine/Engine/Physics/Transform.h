#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "../Common.h"
#include <list>
using std::list;
class GameObject;

class Transform { 

	// the parent transform
	Transform* parent;
	list<Transform*> childeren;

	// the attached gameobject
	GameObject* gameobject;

	// variables
	vec2 position;
	float rotation;

public:

	/// getters
	vec2 GetWorldPosition();
	vec2 GetLocalPosition();
	float GetWorldRotation();
	float GetLocalRotation();
	GameObject* GetGameObject();

	/// setters
	void SetWorldPosition(const vec2& position);
	void SetLocalPosition(const vec2& position);
	void SetWorldRotation(const float& rotation);
	void SetLocalRotation(const float& rotation);

};


#endif // !TRANSFORM_H