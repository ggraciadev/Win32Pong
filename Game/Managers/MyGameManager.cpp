#include "MyGameManager.h"
#include "MySceneManager.h"

void MyGameManager::CreateCustomSceneManager() {
	m_sceneManager = new MySceneManager();
}

void MyGameManager::CreateCustomInputManager() {
	m_inputManager = new InputManager();
}