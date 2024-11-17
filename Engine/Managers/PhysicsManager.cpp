#include "PhysicsManager.h"

PhysicsManager::PhysicsManager() {

}

PhysicsManager::~PhysicsManager() {

}

void PhysicsManager::RegisterCollision(CollisionComponent* collision) {
	if (collision != NULL) {
		m_collisions.insert(collision);
	}
}

void PhysicsManager::UnregisterCollision(CollisionComponent* collision) {
	if (collision != NULL) {
		m_collisions.erase(collision);
	}
}