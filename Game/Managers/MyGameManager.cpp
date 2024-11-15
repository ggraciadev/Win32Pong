#include "MyGameManager.h"
#include "../Scenes/TestScene.h"

MyGameManager::MyGameManager() {

}

void MyGameManager::InitScene() {
	SetCurrentScene(new TestScene());
	GameManager::InitScene();
}