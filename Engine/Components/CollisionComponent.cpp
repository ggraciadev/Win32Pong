#include "CollisionComponent.h"
#include "../Objects/Actor.h"
#include "../Managers/GameManager.h"
#include "BoxCollisionComponent.h"

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

bool CollisionComponent::CheckCollision(CollisionComponent* other) const {
	if (dynamic_cast<BoxCollisionComponent*>(other) != NULL) {
		return CheckCollision((BoxCollisionComponent*)other);
	}

	return false;
}

void CollisionComponent::TryAddCollidingComponent(CollisionComponent* other) {
	if (m_collidingComponents.find(other) != m_collidingComponents.end()) {
		return;
	}
	m_collidingComponents.insert(other);
	m_actor->OnActorBeginOverlap(other->GetOwnerActor(), other);
}

void CollisionComponent::TryRemoveCollidingComponent(CollisionComponent* other) {
	if (m_collidingComponents.find(other) == m_collidingComponents.end()) {
		return;
	}
	m_collidingComponents.erase(other);
	m_actor->OnActorEndOverlap(other->GetOwnerActor(), other);
}

bool CollisionComponent::IsColliding(CollisionComponent* other) const {
	return m_collidingComponents.find(other) != m_collidingComponents.end();
}