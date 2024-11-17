#include "ActorComponent.h"


ActorComponent::ActorComponent() {
	m_transform.SetPosition(Vector2D(0, 0));
	m_transform.SetRotation(0);
	m_transform.SetScale(Vector2D(1, 1));
}


ActorComponent::~ActorComponent() {

}

void ActorComponent::Init(Actor* actor) {
	m_actor = actor;
}

void ActorComponent::SetComponentPosition(Vector2D position) {
	m_transform.SetPosition(position);
}

void ActorComponent::SetComponentRotation(float rotation) {
	m_transform.SetRotation(rotation);
}

void ActorComponent::SetComponentScale(Vector2D scale) {
	m_transform.SetScale(scale);
}

void ActorComponent::SafeTick(float deltaTime) {
	if(m_canEverTick) {
		Tick(deltaTime);
	}
}

void ActorComponent::SafeDraw() {
	if (m_isDrawable) {
		Draw();
	}
}