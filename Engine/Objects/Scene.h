#pragma once
#include <vector>
#include <d2d1.h>
#include "Actor.h"

class Scene {

public:
	Scene();
	virtual ~Scene();

protected:

    std::vector<Actor*>         pActors;        // Actors in this scene

public:
/**
This event is called when the game starts
*/
    void BeginPlay();

/**
This event is called to initialize a Scene
*/
    virtual void Init();

/**
This event is for the logic of the component, the behaviour that has to be updated frame by frame if needed.
*/
    void Tick(float deltaTime);

/**
This event is for the rendering of the Actor. This method automaticaly calls the SafeDraw of all its ActorComponents
*/
    void Draw();

/**
* This method adds an Actor to the actors list
* @param actor: The actor to add to the list
* @return Returns if the actor has been added successfuly to the list
*/
    bool AddActorToScene(Actor* actor);


/**
* This method returns the index of the actor in the actors list
* @param actor: The actor to chock in the list
* @return Returns the index of the actor in the actors list or -1 if not found
*/
int GetActorIndexInScene(const Actor* actor) const;

/**
* This method returns if an actor is in scene
* @param actor: The actor to chock in the list
* @return Returns if the actor is in the scene
*/
    bool IsActorInScene(const Actor* actor) const;

/**
* This method returns if an actor is already in scene
* @param actor: The actor to chock in the list
* @return Returns if the actor has been removed or not
*/
    bool RemoveActorFromScene(Actor* actor);

/**
* This method destroys an actor and removes it from the list
* @param actor: The actor to be destroyed
*/
    void DestroyActor(Actor* actor);

};