#include "TestScene.h"
#include "../Actors/MyEllipseActor.h"
#include "../Actors/MyRectangleActor.h"
#include "../Managers/MyGameManager.h"


void TestScene::Init() {
	MyEllipseActor* ellipse = (MyEllipseActor*)MyGameManager::GetInstance<MyGameManager>()->SpawnActor<MyEllipseActor>();
	ellipse->SetTransform(Transform(Vector2D(0, 0), 0, Vector2D(1, 1)));

	MyRectangleActor* rectangle = (MyRectangleActor*)MyGameManager::GetInstance<MyGameManager>()->SpawnActor<MyRectangleActor>();
	rectangle->SetTransform(Transform(Vector2D(50, 50), 0, Vector2D(1, 1)));
	
	Scene::Init();
}