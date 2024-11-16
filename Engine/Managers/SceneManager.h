#pragma once
#include "../Objects/Scene.h"
#include <vector>

class SceneManager {

public:
	SceneManager();
	virtual ~SceneManager();

protected:

	Scene*					pCurrentScene = NULL;		// A reference to the current scene
	int						pCurrentSceneIndex = -1;	// Index of the current scene
	int						pPreviousSceneIndex = -1;	// Index of the previous scene

public:
/**
* This method is used to Change the current scene of the game. You should redefine this method in order to make it work
* @param index that should be used in order to know the scene to load
*/
	void ChangeScene(int sceneIndex);

/**
* Returns a reference to the current scene
* @return A reference to the current scene
*/
	inline Scene* GetCurrentScene() const { return pCurrentScene; }

protected:
/**
This method deletes the current scene if it is not NULL
*/
	void FlushCurrentScene();

/**
* This method creates and returns a new scene based on the scene index passed by parameter. Must be overrided on a Custom SceneManager
* @param sceneIndex: An index that should be used to know which scene to spawn. Suggestion: Use an enum to have indexed all the scenes
* @return A reference to the scene created
*/
	virtual Scene* GetNewScene(int sceneIndex) = 0;

/**
This method is called to create and initialize the current scene
*/
	void InitScene();

/**
This method is called when the current Scene starts
*/
	void StartScene();

/**
* This methos is called to update the current Scene
* @param deltaTime: Time ellapsed from the previous frame
*/
	void UpdateScene(float deltaTime);

/**
* This methos is called to set the current scene
* @param scene: The new current scene
*/
	void SetCurrentScene(Scene* scene);

/**
This method is called to render the current Scene
*/
	void RenderScene();
};
