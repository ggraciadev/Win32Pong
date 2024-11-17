#include "TestScene.h"
#include "../Actors/Ball.h"
#include "../Actors/Paddle.h"
#include "../Actors/MyPlayerController.h"
#include "../Actors/ScoreBoard.h"
#include "../Actors/Wall.h"
#include "../Managers/MyGameManager.h"


void TestScene::Init() {
	MyGameManager* gameManager = MyGameManager::GetInstance<MyGameManager>();
	Vector2D windowSize = gameManager->GetWindowSize();


	Paddle* playerPaddle = (Paddle*)gameManager->SpawnActor<Paddle>();
	playerPaddle->SetTransform(Transform(Vector2D(50, windowSize.GetY() / 2), 0, Vector2D(1, 1)));

	MyPlayerController* playerController = (MyPlayerController*)gameManager->SpawnActor<MyPlayerController>();
	playerController->Possess(playerPaddle);

	Paddle* playerPaddle2 = (Paddle*)gameManager->SpawnActor<Paddle>();
	playerPaddle2->SetTransform(Transform(Vector2D(windowSize.GetX() - 50, windowSize.GetY() / 2), 0, Vector2D(1, 1)));

	Wall* wallTop = (Wall*)gameManager->SpawnActor<Wall>();
	wallTop->SetTransform(Transform(Vector2D(windowSize.GetX() / 2, 0), 0, Vector2D(1, 1)));

	Wall* wallBot = (Wall*)gameManager->SpawnActor<Wall>();
	wallBot->SetTransform(Transform(Vector2D(windowSize.GetX() / 2, windowSize.GetY()), 0, Vector2D(1, 1)));

	Ball* ball = (Ball*)gameManager->SpawnActor<Ball>();
	ball->SetTransform(Transform(Vector2D(windowSize.GetX() / 2, windowSize.GetY() / 2), 0, Vector2D(1, 1)));
	
	ScoreBoard* scoreBoard = (ScoreBoard*)gameManager->SpawnActor<ScoreBoard>();
	Scene::Init();
}