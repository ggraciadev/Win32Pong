#include "MovementComponent.h"
#include "../Objects/Actor.h"

MovementComponent::MovementComponent() {
	
}

void MovementComponent::BeginPlay() {
	ActorComponent::BeginPlay();
}
void MovementComponent::Tick(float deltaTime) {
	ActorComponent::Tick(deltaTime);
	m_actor->AddActorWorldOffset(m_movementDirection * m_currentSpeed * deltaTime);
}

void MovementComponent::EndPlay() {
	ActorComponent::EndPlay();
}