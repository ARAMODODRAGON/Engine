#ifndef COMPONENT_H
#define COMPONENT_H
#include "Common.h"
#include "GameObject.h"
class Transform;

enum class EventFlags : ubyte {
	None = 0b00000000,
	Update = 0b00000001,
	Draw = 0b00000010,
	OnCollision = 0b00000100,
};

class Component {
	// friend of gameobject
	friend GameObject;
	friend class PhysicsScene;

	// the attached gameobject & transform
	GameObject* gameobject;
	Transform* transform;

	// increase performance by calling events if specified by the enum
	EventFlags eventFlags;

public:

	Component();
	virtual ~Component();

	/// component functions
	template<class T>
	T* CreateComponent() { return gameobject->CreateComponent<T>(); }
	template<class T>
	T* GetComponent() { return gameobject->GetComponent<T>(); }

	/// events
	virtual void OnCreate() { }
	virtual void OnDestroy() { }
	virtual void Update(const float& delta) { }
	virtual void Draw() { }
	virtual void OnCollision() { }

	/// flags
	bool HasEventFlags(const EventFlags& flags);
	void AddEventFlags(const EventFlags& flags);
	void UnsetEventFlags(const EventFlags& flags);
	void SetAllEventFlags(const EventFlags& flags);

	/// getters

	// returns the attached transform
	GameObject* GetGameObject() { return gameobject; }
	Transform* GetTransform() { return transform; }


	/// setters

};

#endif // !COMPONENT_H
