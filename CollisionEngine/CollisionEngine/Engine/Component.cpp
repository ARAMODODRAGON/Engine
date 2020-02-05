#include "Component.h"

Component::Component()
	: gameobject(nullptr)
	, transform(nullptr)
	, eventFlags(EventFlags::None) { }

Component::~Component() { }

bool Component::HasEventFlags(const EventFlags& flags) {
	return static_cast<bool>((int)eventFlags & (int)flags);
}
void Component::AddEventFlags(const EventFlags& flags) {
	(int&)eventFlags |= (int)flags;
}
void Component::UnsetEventFlags(const EventFlags& flags) { 
	(int&)eventFlags &= ~(int)flags;
}
void Component::SetAllEventFlags(const EventFlags& flags) {
	eventFlags = flags;
}

