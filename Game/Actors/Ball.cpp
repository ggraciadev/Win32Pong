#include "Ball.h"
#include "../Managers/MyGameManager.h"
#include "Paddle.h"

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
	m_boxCollisionComponent->SetBoxSize(40, 40);
	m_movementComponent->SetMaxSpeed(400);
	m_movementComponent->SetCurrentSpeed(400);
	m_movementComponent->SetMovementDirection(Vector2D(-1, 0));
}

void Ball::EndPlay() {
	EllipseActor::EndPlay();
}

void Ball::Tick(float deltaTime) {
	EllipseActor::Tick(deltaTime);
}

void Ball::OnActorBeginOverlap(Actor* other, CollisionComponent* otherComponent) {
	Paddle* paddle = (Paddle*)other;
	if (paddle != NULL) { //if the ball impacts with a paddle
		m_movementComponent->SetMovementDirectionX(m_movementComponent->GetMovementDirection().GetX() * -1);
	}
	else { // if the ball impacts with a wall
		m_movementComponent->SetMovementDirectionY(m_movementComponent->GetMovementDirection().GetY() * -1);
	}
}