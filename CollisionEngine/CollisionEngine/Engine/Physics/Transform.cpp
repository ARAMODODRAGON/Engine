#include "Transform.h"

Transform::Transform(GameObject* object)
	: parent(nullptr)
	, childeren(list<Transform*>())
	, gameobject(object)
	, position(vec2(0))
	, rotation(0) { }

Transform::Transform(GameObject* object, Transform* parent)
	: parent(parent)
	, childeren(list<Transform*>())
	, gameobject(object)
	, position(vec2(0))
	, rotation(0) { }

Transform::Transform(GameObject* object, GameObject* parent)
	: parent(parent->GetTransform())
	, childeren(list<Transform*>())
	, gameobject(object)
	, position(vec2(0))
	, rotation(0) { }

Transform::~Transform() { }

vec2 Transform::GetWorldPosition() {
	if (parent)
		return parent->GetWorldPosition() + position;
	return position;
}

float Transform::GetWorldRotation() {
	if (parent)
		return parent->GetWorldRotation() + rotation;
	return rotation;
}

Transform* Transform::GetRoot() {
	if (parent)
		return parent->GetRoot();
	return this;
}

void Transform::SetWorldPosition(const vec2& pos) {
	if (parent)
		position = pos - parent->GetWorldPosition();
	else
		position = pos;
}

void Transform::SetWorldRotation(const float& rot) {
	if (parent)
		rotation = rot - parent->GetWorldRotation();
	else
		rotation = rot;
}
