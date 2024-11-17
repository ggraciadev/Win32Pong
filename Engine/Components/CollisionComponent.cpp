#include "CollisionComponent.h"
#include "../Objects/Actor.h"
#include "../Managers/GameManager.h"

CollisionComponent::CollisionComponent() {
	m_PhysicsEnabled = true;
	RegisterToPhysicsManager();
}

CollisionComponent::~CollisionComponent() {
	m_physicsManager->UnregisterCollision(this);
}

void CollisionComponent::BeginPlay() {
	ActorComponent::BeginPlay();
}

void CollisionComponent::RegisterToPhysicsManager() {
	m_physicsManager = GameManager::GetInstance<GameManager>()->GetPhysicsManager();
	m_physicsManager->RegisterCollision(this);
}

void CollisionComponent::EndPlay() {
	ActorComponent::EndPlay();
	
}

void CollisionComponent::PhysicsTick() {

}