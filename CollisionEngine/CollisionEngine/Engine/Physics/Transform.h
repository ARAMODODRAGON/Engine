#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "../Common.h"
#include "../GameObject.h"

class Transform {
	// friend
	friend GameObject;
	friend class PhysicsScene;

	// the parent transform
	Transform* parent;
	list<Transform*> childeren;

	// the attached gameobject
	GameObject* gameobject;

	// variables
	vec2 position;
	float rotation;

public:

	Transform(GameObject* object);
	Transform(GameObject* object, Transform* parent);
	Transform(GameObject* object, GameObject* parent);
	~Transform();

	/// getters
	vec2 GetWorldPosition();
	vec2 GetLocalPosition() { return position; }
	float GetWorldRotation();
	float GetLocalRotation() { return rotation; }
	GameObject* GetGameObject() { return gameobject; }
	Transform* GetParent() { return parent; }
	Transform* GetRoot();

	/// setters
	void SetWorldPosition(const vec2& pos);
	void SetLocalPosition(const vec2& pos) { position = pos; }
	void SetWorldRotation(const float& rot);
	void SetLocalRotation(const float& rot) { rotation = rot; }


	/// component functions
	template<class T>
	T* CreateComponent() { return gameobject->CreateComponent<T>(); }
	template<class T>
	T* GetComponent() { return gameobject->GetComponent<T>(); }

};


#endif // !TRANSFORM_H