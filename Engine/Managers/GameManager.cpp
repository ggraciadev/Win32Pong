#include "GameManager.h"

GameManager::GameManager() {
	pRunning = true;
}

GameManager::~GameManager() {
	pSceneInitialized = false;
	delete pEllipseActor;
	pEllipseActor = NULL;
}

GameManager* GameManager::pInstance = nullptr;

GameManager* GameManager::GetInstance() {
	if (pInstance == nullptr) {
		pInstance = new GameManager();
	}
	return pInstance;
}

void GameManager::InitGameManager(ID2D1HwndRenderTarget* renderTarget, MainWindow* window) {
	pRenderTarget = renderTarget;
	pMainWindow = window;
}

void GameManager::InitScene() {
	pEllipseActor = new EllipseActor();
	pEllipseActor->Init();

	pSceneInitialized = true;
}

void GameManager::StartScene() {
	pEllipseActor->BeginPlay();

}

void GameManager::UpdateScene(float deltaTime) {
	if (!pSceneInitialized) { return; }
	if (pEllipseActor != NULL) {
		pEllipseActor->Tick(deltaTime);
	}
}

void GameManager::RenderScene() {
	if (!pSceneInitialized) { return; }
	pMainWindow->StartRender();
	if (pEllipseActor != NULL) {
		pEllipseActor->Draw();
	}
	pMainWindow->EndRender();
}