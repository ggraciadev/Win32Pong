#pragma once
#include "../Utils/Transform.h"
#include <d2d1.h>

class Actor;

/**
ActorComponent
This is the basic class for all the Components of an Actor
*/
class ActorComponent
{

public:
	ActorComponent();
	virtual ~ActorComponent();

protected:
	
	Actor*			m_actor = NULL;			// A reference of the actor that has the component
	Transform		m_transform;				// The Transform relative to the Actor for this component
	bool			m_isDrawable = false;	// If the component should be Rendered or not
	bool			m_canEverTick = false;	// If the component should be Tickable or not
	bool			m_PhysicsEnabled = false;	// If the components' physics should be updated or not

/**
This event is called at the begining of the destructor method
 */
	virtual void EndPlay() {};


public:

/**
 * Initalize the ActorComponent with the reference of its owner
 *
 * Default Transform is at Position(0,0), Rotation(0) and Scale(1,1)
 *
 * @param actor:  a reference to the owner Actor.
 */
	virtual void Init(Actor* actor);


/**
This event is called when the game starts or when the owner Actor is spawned
*/
	virtual void BeginPlay() {};

/**
This method checks if the component should be updated and calls the Tick method to be updated.
*/
	virtual void SafeTick(float deltaTime);

/**
This event is for the logic of the component, the behaviour that has to be updated frame by frame if needed.
*/
	virtual void Tick(float deltaTime) {};

/**
This method checks if the component should be rendered and calls the Draw method to be renedered.
 */
	virtual void SafeDraw();

/**
This event is for the rendering of the component if needed. This method should be overrided by every ActorComponent that uses it
*/
	virtual void Draw() {};


	/**
	* This method returns a reference of the owner actor
	* @return A reference of the owner actor
	*/
	Actor* GetOwnerActor() { return m_actor; }
/**
* This method returns a reference of the transform
* @return A reference of the transform of the ActorComponent
*/
	Transform* GetTransform() { return &m_transform; }

/**
 * Sets the position of the transform of this ActorComponent
 * @param position: Position to be assigned to the transform
*/
	void SetComponentPosition(Vector2D position);

/**
  * Sets the rotation of the transform of this ActorComponent
  * @param rotation: Rotation to be assigned to the transform
*/
	void SetComponentRotation(float rotation);

/**
 * Sets the scale of the transform of this ActorComponent
 * @param scale: Scale to be assigned to the transform
*/
	void SetComponentScale(Vector2D scale);
};