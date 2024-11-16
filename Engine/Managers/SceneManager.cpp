#include "SceneManager.h"

SceneManager::SceneManager() {

}

SceneManager::~SceneManager() {
	FlushCurrentScene();
}

void SceneManager::ChangeScene(int sceneIndex) {
	Scene* tempScene = GetNewScene(sceneIndex);
	if (tempScene == NULL) { return; }

	m_previousSceneIndex = m_currentSceneIndex;
	m_currentSceneIndex = sceneIndex;

	FlushCurrentScene();
	SetCurrentScene(tempScene);
	InitScene();
	StartScene();
}

void SceneManager::FlushCurrentScene() {
	if (m_currentScene != NULL) {
		delete m_currentScene;
		m_currentScene = NULL;
	}
}

void SceneManager::InitScene() {
	if (m_currentScene != NULL) {
		m_currentScene->Init();
	}
}

void SceneManager::StartScene() {
	if (m_currentScene != NULL) {
		m_currentScene->BeginPlay();
	}
}

void SceneManager::UpdateScene(float deltaTime) {
	if (m_currentScene != NULL) {
		m_currentScene->Tick(deltaTime);
	}
}

void SceneManager::SetCurrentScene(Scene* scene) {
	if (scene != NULL) {
		m_currentScene = scene;
	}
}

void SceneManager::RenderScene() {
	if (m_currentScene != NULL) {
		m_currentScene->Draw();
	}
}