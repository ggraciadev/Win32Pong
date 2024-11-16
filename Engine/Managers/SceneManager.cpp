#include "SceneManager.h"

SceneManager::SceneManager() {

}

SceneManager::~SceneManager() {
	FlushCurrentScene();
}

void SceneManager::ChangeScene(int sceneIndex) {
	Scene* tempScene = GetNewScene(sceneIndex);
	if (tempScene == NULL) { return; }

	pPreviousSceneIndex = pCurrentSceneIndex;
	pCurrentSceneIndex = sceneIndex;

	FlushCurrentScene();
	SetCurrentScene(tempScene);
	InitScene();
	StartScene();
}

void SceneManager::FlushCurrentScene() {
	if (pCurrentScene != NULL) {
		delete pCurrentScene;
		pCurrentScene = NULL;
	}
}

void SceneManager::InitScene() {
	if (pCurrentScene != NULL) {
		pCurrentScene->Init();
	}
}

void SceneManager::StartScene() {
	if (pCurrentScene != NULL) {
		pCurrentScene->BeginPlay();
	}
}

void SceneManager::UpdateScene(float deltaTime) {
	if (pCurrentScene != NULL) {
		pCurrentScene->Tick(deltaTime);
	}
}

void SceneManager::SetCurrentScene(Scene* scene) {
	if (scene != NULL) {
		pCurrentScene = scene;
	}
}

void SceneManager::RenderScene() {
	if (pCurrentScene != NULL) {
		pCurrentScene->Draw();
	}
}