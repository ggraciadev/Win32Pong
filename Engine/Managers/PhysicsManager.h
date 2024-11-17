#pragma once
#include "../Objects/Scene.h"
#include <set>
#include "../Components/CollisionComponent.h"


class PhysicsManager {

public:
	PhysicsManager();
	friend class GameManager;

protected:

	std::set<CollisionComponent*> m_collisions;		// List of references of all collisions


	virtual ~PhysicsManager();

public:

	void RegisterCollision(CollisionComponent* collision);
	void UnregisterCollision(CollisionComponent* collision);

	void UpdateCollisions();


};
