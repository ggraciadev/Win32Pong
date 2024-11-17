#pragma once
#include "ActorComponent.h"
#include <set>

class PhysicsManager;
class BoxCollisionComponent;

class CollisionComponent : public ActorComponent
{
public:
	CollisionComponent();
	~CollisionComponent();
	friend class PhysicsManager;

private:
	void RegisterToPhysicsManager();

protected:

	PhysicsManager* m_physicsManager;
	std::set<CollisionComponent*>	m_collidingComponents;			// The other collision components currently colliding with this one

/**
This event is called at the begining of the destructor method
 */
	virtual void EndPlay();

	bool CheckCollision(CollisionComponent* other) const;
	virtual bool CheckCollision(BoxCollisionComponent* other) const { return false; }

	void TryAddCollidingComponent(CollisionComponent* other);
	void TryRemoveCollidingComponent(CollisionComponent* other);
public:
/**
This event is called when the game starts or when the owner Actor is spawned
*/
	virtual void BeginPlay();

	bool IsColliding(CollisionComponent* other) const;



	
};