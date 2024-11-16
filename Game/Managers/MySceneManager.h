#pragma once
#include "../../Engine/Managers/SceneManager.h"

// Enumeration to list every scene of the game
enum MyGameScenes {SCENE_MAIN_MENU, SCENE_PONG, SCENE_GAME_OVER }; 

class MySceneManager : public SceneManager {

public:

/**
* This method creates and returns a new scene based on the scene index passed by parameter.
* @param sceneIndex: An index that should be used to know which scene to spawn.
* @return A reference to the scene created
*/
	virtual Scene* GetNewScene(int sceneIndex);
};