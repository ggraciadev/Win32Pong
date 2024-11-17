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

void PhysicsManager::UpdateCollisions() {
	int i = 0;
	for (auto it = m_collisions.begin(); it != m_collisions.end(); ++it) {
		auto jt = m_collisions.begin();
		std::advance(jt, ++i);

		for (jt; jt != m_collisions.end(); ++jt) {
			if ((*it)->CheckCollision(*jt)) {
				(*it)->TryAddCollidingComponent(*jt);
				(*jt)->TryAddCollidingComponent(*it);
			}
			else {
				(*it)->TryRemoveCollidingComponent(*jt);
				(*jt)->TryRemoveCollidingComponent(*it);
			}
		}
	}
}