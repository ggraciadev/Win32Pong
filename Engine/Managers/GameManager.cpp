#include "GameManager.h"
#include "../Objects/Actor.h"

GameManager::GameManager() {
	m_running = true;
}

GameManager::~GameManager() {
	m_gameInitialized = false;
	if (m_sceneManager != NULL) {
		delete m_sceneManager;
	}
}

GameManager* GameManager::s_instance = nullptr;

void GameManager::InitGameManager(ID2D1HwndRenderTarget* renderTarget, MainWindow* window) {
	m_renderTarget = renderTarget;
	m_mainWindow = window;
	if (m_gameInitialized) { return; }

	CreateManagers();
	if (m_sceneManager == NULL) { return; }

	m_gameInitialized = true;
	StartGame();
}

void GameManager::CreateManagers() {
	CreateCustomSceneManager();
}

void GameManager::StartGame() {
	m_sceneManager->ChangeScene(0);
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
	if (!m_gameInitialized) { return; }
	if (GetCurrentScene() != NULL) {
		GetCurrentScene()->Tick(deltaTime);
	}
}

void GameManager::RenderScene() {
	if (!m_gameInitialized) { return; }
	m_mainWindow->StartRender();
	if (GetCurrentScene() != NULL) {
		GetCurrentScene()->Draw();
	}
	m_mainWindow->EndRender();
}

Scene* GameManager::GetCurrentScene() const{
	if (m_sceneManager->GetCurrentScene() != NULL) {
		return m_sceneManager->GetCurrentScene();
	}
	else {
		return NULL;
	}


}

void GameManager::DespawnActor(Actor* actor) {
	GetCurrentScene()->DestroyActor(actor);
}

Vector2D GameManager::GetWindowSize() { 
	Vector2D result;
	if (m_renderTarget != NULL) {
		D2D1_SIZE_F size = m_renderTarget->GetSize();
		result.SetX(size.width);
		result.SetY(size.height);
	}
	return result;
}