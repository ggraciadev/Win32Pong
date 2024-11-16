#include "GameManager.h"
#include "../Objects/Actor.h"

GameManager::GameManager() {
	pRunning = true;
}

GameManager::~GameManager() {
	pGameInitialized = false;
	if (pSceneManager != NULL) {
		delete pSceneManager;
	}
}

GameManager* GameManager::pInstance = nullptr;

void GameManager::InitGameManager(ID2D1HwndRenderTarget* renderTarget, MainWindow* window) {
	pRenderTarget = renderTarget;
	pMainWindow = window;
	if (pGameInitialized) { return; }

	CreateManagers();
	if (pSceneManager == NULL) { return; }

	pGameInitialized = true;
	StartGame();
}

void GameManager::CreateManagers() {
	CreateCustomSceneManager();
}

void GameManager::StartGame() {
	pSceneManager->ChangeScene(0);
}

void GameManager::InitScene() {
	if (GetCurrentScene() != NULL) {
		GetCurrentScene();
	}
}

void GameManager::StartScene() {
	if (GetCurrentScene() != NULL) {
		GetCurrentScene()->BeginPlay();
	}

}

void GameManager::UpdateScene(float deltaTime) {
	if (!pGameInitialized) { return; }
	if (GetCurrentScene() != NULL) {
		GetCurrentScene()->Tick(deltaTime);
	}
}

void GameManager::RenderScene() {
	if (!pGameInitialized) { return; }
	pMainWindow->StartRender();
	if (GetCurrentScene() != NULL) {
		GetCurrentScene()->Draw();
	}
	pMainWindow->EndRender();
}

Scene* GameManager::GetCurrentScene() const{
	if (pSceneManager->GetCurrentScene() != NULL) {
		return pSceneManager->GetCurrentScene();
	}
	else {
		return NULL;
	}


}

void GameManager::DespawnActor(Actor* actor) {
	GetCurrentScene()->DestroyActor(actor);
}