#include "TestScene.h"
#include "../Actors/MyEllipseActor.h"
#include "../Actors/Paddle.h"
#include "../Actors/MyPlayerController.h"
#include "../Actors/ScoreBoard.h"
#include "../Managers/MyGameManager.h"


void TestScene::Init() {
	MyGameManager* gameManager = MyGameManager::GetInstance<MyGameManager>();

	MyEllipseActor* ellipse = (MyEllipseActor*)gameManager->SpawnActor<MyEllipseActor>();
	ellipse->SetTransform(Transform(Vector2D(0, 0), 0, Vector2D(1, 1)));

	Paddle* playerPaddle = (Paddle*)gameManager->SpawnActor<Paddle>();
	playerPaddle->SetTransform(Transform(Vector2D(50, 50), 0, Vector2D(1, 1)));

	MyPlayerController* playerController = (MyPlayerController*)gameManager->SpawnActor<MyPlayerController>();
	playerController->Possess(playerPaddle);
	
	ScoreBoard* scoreBoard = (ScoreBoard*)gameManager->SpawnActor<ScoreBoard>();
	Scene::Init();
}