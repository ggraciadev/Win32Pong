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

void GameManager::InitGameManager(ID2D1HwndRenderTarget* renderTarget) {
	pRenderTarget = renderTarget;
}

void GameManager::InitScene() {
	pEllipseActor = new EllipseActor();
	pEllipseActor->Init(Transform(Vector2D(5, 5), 0, Vector2D(1, 1)), pRenderTarget);

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
	if (pEllipseActor != NULL) {
		pEllipseActor->Draw();
	}
}