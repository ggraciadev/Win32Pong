#include "TestScene.h"
#include "../Actors/Ball.h"
#include "../Actors/Paddle.h"
#include "../Actors/MyPlayerController.h"
#include "../Actors/MyAIController.h"
#include "../Actors/ScoreBoard.h"
#include "../Actors/Wall.h"
#include "../Actors/Goal.h"
#include "../Managers/MyGameManager.h"


void TestScene::Init() {
	MyGameManager* gameManager = MyGameManager::GetInstance<MyGameManager>();
	Vector2D windowSize = gameManager->GetWindowSize();

	Ball* ball = (Ball*)gameManager->SpawnActor<Ball>();
	ball->SetTransform(Transform(Vector2D(windowSize.GetX() / 2, windowSize.GetY() / 2), 0, Vector2D(1, 1)));

	Paddle* playerPaddle = (Paddle*)gameManager->SpawnActor<Paddle>();
	playerPaddle->SetTransform(Transform(Vector2D(50, windowSize.GetY() / 2), 0, Vector2D(1, 1)));

	MyPlayerController* playerController = (MyPlayerController*)gameManager->SpawnActor<MyPlayerController>();
	playerController->Possess(playerPaddle);

	Paddle* aiPaddle = (Paddle*)gameManager->SpawnActor<Paddle>();
	aiPaddle->SetTransform(Transform(Vector2D(windowSize.GetX() - 50, windowSize.GetY() / 2), 0, Vector2D(1, 1)));

	MyAIController* aiController = (MyAIController*)gameManager->SpawnActor<MyAIController>();
	aiController->SetBall(ball);
	aiController->Possess(aiPaddle);

	Wall* wallTop = (Wall*)gameManager->SpawnActor<Wall>();
	wallTop->SetTransform(Transform(Vector2D(windowSize.GetX() / 2, 0), 0, Vector2D(1, 1)));

	Wall* wallBot = (Wall*)gameManager->SpawnActor<Wall>();
	wallBot->SetTransform(Transform(Vector2D(windowSize.GetX() / 2, windowSize.GetY()), 0, Vector2D(1, 1)));

	Goal* goalL = (Goal*)gameManager->SpawnActor<Goal>();
	goalL->SetTransform(Transform(Vector2D(0, windowSize.GetY() / 2), 0, Vector2D(1, 1)));

	Goal* goalR = (Goal*)gameManager->SpawnActor<Goal>();
	goalR->SetTransform(Transform(Vector2D(windowSize.GetX(), windowSize.GetY() / 2), 0, Vector2D(1, 1)));

	
	ScoreBoard* scoreBoard = (ScoreBoard*)gameManager->SpawnActor<ScoreBoard>();
	Scene::Init();
}