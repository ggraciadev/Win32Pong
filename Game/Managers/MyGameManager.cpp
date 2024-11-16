#include "MyGameManager.h"
#include "MySceneManager.h"

void MyGameManager::CreateCustomSceneManager() {
	m_sceneManager = new MySceneManager();
	m_inputManager = new InputManager();
}