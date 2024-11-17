#pragma once
#include "ActorComponent.h"

class PhysicsManager;

class CollisionComponent : public ActorComponent
{

public:
	CollisionComponent();
	~CollisionComponent();

private:
	void RegisterToPhysicsManager();

protected:

	PhysicsManager* m_physicsManager;

/**
This event is called at the begining of the destructor method
 */
	virtual void EndPlay();

public:
/**
This event is called when the game starts or when the owner Actor is spawned
*/
	virtual void BeginPlay();


/**
This event is for the rendering of the component if needed. This method should be overrided by every ActorComponent that uses it
*/
	virtual void PhysicsTick();

	
};