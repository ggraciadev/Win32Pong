#include "BoxCollisionComponent.h"
#include "../Objects/Actor.h"

BoxCollisionComponent::BoxCollisionComponent() {
	
}

void BoxCollisionComponent::PhysicsTick() {
	CollisionComponent::PhysicsTick();
	
}

void BoxCollisionComponent::BeginPlay() {
	CollisionComponent::BeginPlay();
}

void BoxCollisionComponent::EndPlay() {
	CollisionComponent::EndPlay();
}