#include "Ball.h"
#include "../Managers/MyGameManager.h"
#include "Paddle.h"
#include "Goal.h"

Ball::Ball() {
	m_boxCollisionComponent = AddActorComponent<BoxCollisionComponent>();
	m_movementComponent = AddActorComponent<MovementComponent>();
}

Ball::~Ball() {

}


void Ball::BeginPlay() {
	EllipseActor::BeginPlay();
	m_ellipseComponent->SetColor(D2D1::ColorF(1.0f, 1.0f, 0));
	m_ellipseComponent->SetEllipseRadius(Vector2D(20, 20));
	m_boxCollisionComponent->SetBoxSize(20, 20);
	m_movementComponent->SetMaxSpeed(6000);
	m_gameManager = MyGameManager::GetInstance<MyGameManager>();
	ResetBallPosition();
}

void Ball::EndPlay() {
	EllipseActor::EndPlay();
}

void Ball::Tick(float deltaTime) {
	EllipseActor::Tick(deltaTime);
	Vector2D pos = m_transform.GetPosition();
	Vector2D maxPos = m_gameManager->GetWindowSize();
	if (pos.GetX() < -20 || pos.GetY() < -2 || pos.GetX() > maxPos.GetX() + 20 || pos.GetY() > maxPos.GetY() + 20) {
		ResetBallPosition(); // just in case the collision system fails
	}
}

void Ball::ScoreGoal() {
	if (m_transform.GetPosition().GetX() < m_gameManager->GetWindowSize().GetX() / 2) {
		m_gameManager->AddScorePlayerB();
	}
	else {
		m_gameManager->AddScorePlayerA();
	}

	ResetBallPosition();
}

void Ball::ResetBallPosition() {
	m_movementComponent->SetCurrentSpeed(400);
	m_movementComponent->SetMovementDirection(Vector2D(-1, -1));
	m_transform.SetPosition(m_gameManager->GetWindowSize() / 2);
}

void Ball::ReboundOnWall() {
	m_movementComponent->SetMovementDirectionY(m_movementComponent->GetMovementDirection().GetY() * -1);
}

void Ball::ReboundOnPaddle(Paddle* paddle) {
	Vector2D dir = (m_transform.GetPosition() - paddle->GetTransform()->GetPosition()).GetNormal();
	dir.SetY(dir.GetY() / 2);
	m_movementComponent->SetMovementDirection(dir.GetNormal());
	m_movementComponent->SetCurrentSpeed(m_movementComponent->GetCurrentSpeed() + 50);
}

void Ball::OnActorBeginOverlap(Actor* other, CollisionComponent* otherComponent) {
	if (dynamic_cast<Paddle*>(other) != NULL) { //if the ball impacts with a paddle
		ReboundOnPaddle((Paddle*)other);
	} 
	else if (dynamic_cast<Goal*>(other) != NULL) {
		ScoreGoal();
	}
	else { // if the ball impacts with a wall
		ReboundOnWall();
	}

}