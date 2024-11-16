#include "MySceneManager.h"
#include "../Scenes/TestScene.h"

Scene* MySceneManager::GetNewScene(int sceneIndex) {
	Scene* result = NULL;

	switch ((MyGameScenes)sceneIndex)
	{
	case MyGameScenes::SCENE_MAIN_MENU:
		result = new TestScene();
		break;
	case MyGameScenes::SCENE_PONG:

		break;
	case MyGameScenes::SCENE_GAME_OVER:
		break;
	default:
		break;
	}

	return result;
}