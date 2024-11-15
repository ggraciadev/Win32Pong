#include "GameManager.h"

GameManager::GameManager() {
	pRunning = true;
}

GameManager::~GameManager() {
	pSceneInitialized = false;
}

GameManager* GameManager::pInstance = nullptr;

void GameManager::InitGameManager(ID2D1HwndRenderTarget* renderTarget, MainWindow* window) {
	pRenderTarget = renderTarget;
	pMainWindow = window;
}

void GameManager::InitScene() {
	if (pCurrentScene != NULL) {
		pCurrentScene->Init();
		pSceneInitialized = true;
	}
}

void GameManager::StartScene() {
	if (pCurrentScene != NULL) {
		pCurrentScene->BeginPlay();
	}

}

void GameManager::UpdateScene(float deltaTime) {
	if (!pSceneInitialized) { return; }
	if (pCurrentScene != NULL) {
		pCurrentScene->Tick(deltaTime);
	}
}

void GameManager::RenderScene() {
	if (!pSceneInitialized) { return; }
	pMainWindow->StartRender();
	if (pCurrentScene != NULL) {
		pCurrentScene->Draw();
	}
	pMainWindow->EndRender();
}
void GameManager::SetCurrentScene(Scene* scene) {
	if (pCurrentScene != NULL) {
		delete pCurrentScene;
		pCurrentScene = NULL;
	}
	pCurrentScene = scene;
}