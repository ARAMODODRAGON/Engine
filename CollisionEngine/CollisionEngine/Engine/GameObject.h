#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Common.h"
#include <type_traits>
#include "Graphics/Shader.h"
class Component;
class Transform;

class GameObject {
	/// TODO: create an object factory
	class ObjectFactory* factory;

	// the attached transform
	Transform* transform;

	// the list of components
	list<Component*> components;

	/// Temp
	Shader* shader;

public:

	GameObject();
	virtual ~GameObject() { OnDestroy(); }

	/// events
	void OnCreate();
	void OnDestroy();
	void Update(const float& delta);
	void Draw();
	void OnCollision();

	/// getters
	Transform* GetTransform() { return transform; }
	list<Component*>* GetComponentList() { return &components; }

	/// component functions
	template<class T>
	T* CreateComponent() {
		static_assert(std::is_base_of<Component, T>(), "T is not a child of Component");

		// create a new component of type T
		T* comp = new T();
		Component* c = comp;

		// add comp to the list
		components.push_back(comp);

		// add pointers
		c->gameobject = this;
		c->transform = transform;

		// call the oncreate
		comp->OnCreate();

		return comp;
	}
	template<class T>
	T* GetComponent() {
		static_assert(std::is_base_of<Component, T>(), "T is not a child of Component");

		// find the component
		for (Component* comp : components) {
			if (T* compofT = dynamic_cast<T*>(comp))
				return compofT;
		}
		return nullptr;
	}


};

#endif // !GAME_OBJECT_H
