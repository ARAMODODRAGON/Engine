#include "Transform.h"

vec2 Transform::GetWorldPosition() {
	if (parent)
		return parent->GetWorldPosition() + position;
	return position;
}

vec2 Transform::GetLocalPosition() {
	return position;
}

float Transform::GetWorldRotation() {
	if (parent)
		return parent->GetWorldRotation() + rotation;
	return rotation;
}

float Transform::GetLocalRotation() {
	return rotation;
}

GameObject* Transform::GetGameObject() {
	return gameobject;
}

void Transform::SetWorldPosition(const vec2& position_) {
	if (parent)
		position = position_ - parent->GetWorldPosition();
	else
		position = position_;
}

void Transform::SetLocalPosition(const vec2& position_) {
	position = position_;
}

void Transform::SetWorldRotation(const float& rotation_) {
	if (parent)
		rotation = rotation_ - parent->GetWorldRotation();
	else
		rotation = rotation_;
}

void Transform::SetLocalRotation(const float& rotation_) {
	rotation = rotation_;
}
