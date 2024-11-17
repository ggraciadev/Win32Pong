#include "TestScene.h"
#include "../Actors/Ball.h"
#include "../Actors/Paddle.h"
#include "../Actors/MyPlayerController.h"
#include "../Actors/ScoreBoard.h"
#include "../Managers/MyGameManager.h"


void TestScene::Init() {
	MyGameManager* gameManager = MyGameManager::GetInstance<MyGameManager>();
	Vector2D windowSize = gameManager->GetWindowSize();

	Ball* ball = (Ball*)gameManager->SpawnActor<Ball>();
	ball->SetTransform(Transform(Vector2D(windowSize.GetX()/2, windowSize.GetY() / 2), 0, Vector2D(1, 1)));

	Paddle* playerPaddle = (Paddle*)gameManager->SpawnActor<Paddle>();
	playerPaddle->SetTransform(Transform(Vector2D(50, windowSize.GetY() / 2), 0, Vector2D(1, 1)));

	MyPlayerController* playerController = (MyPlayerController*)gameManager->SpawnActor<MyPlayerController>();
	playerController->Possess(playerPaddle);

	Paddle* playerPaddle2 = (Paddle*)gameManager->SpawnActor<Paddle>();
	playerPaddle2->SetTransform(Transform(Vector2D(windowSize.GetX() - 50, windowSize.GetY() / 2), 0, Vector2D(1, 1)));
	
	ScoreBoard* scoreBoard = (ScoreBoard*)gameManager->SpawnActor<ScoreBoard>();
	Scene::Init();
}