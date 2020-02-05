#include "GameObject.h"
#include "Physics/Transform.h"
#include "Component.h"

GameObject::GameObject()
	: factory(nullptr)
	, transform(nullptr)
	, components(list<Component*>())
	, shader(nullptr) { }

void GameObject::OnCreate() {
	// create and attach the transform to the gameobject
	transform = new Transform(this);

	// temp
	shader = new Shader();
	shader->LoadShader("Testing/Shaders/TempShader.vert", "Testing/Shaders/TempShader.frag");
}

void GameObject::OnDestroy() {
	if (components.size() > 0) {
		// delete the components
		for (Component* comp : components) {
			comp->OnDestroy();
			delete comp;
		}
		// clear the list
		components.clear();
	}

	// delete the transform
	delete transform; transform = nullptr;

	// temp
	shader->UnloadShader();
	delete shader; shader = nullptr;
}

void GameObject::Update(const float& delta) {
	for (Component* comp : components)
		if (comp->HasEventFlags(EventFlags::Update)) comp->Update(delta);
}

void GameObject::Draw() {
	for (Component* comp : components)
		if (comp->HasEventFlags(EventFlags::Draw)) comp->Draw();
}

void GameObject::OnCollision() {
	for (Component* comp : components)
		if (comp->HasEventFlags(EventFlags::OnCollision)) comp->OnCollision();
}
