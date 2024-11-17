#include "Paddle.h"
#include "../../Engine/Utils/Utils.h"

Paddle::Paddle() {
	m_rectangleComponent = AddActorComponent<RectangleComponent>();
	m_boxCollisionComponent = AddActorComponent<BoxCollisionComponent>();
	m_movementComponent = AddActorComponent<MovementComponent>();
}

Paddle::~Paddle() {

}


void Paddle::BeginPlay() {
	Pawn::BeginPlay();
	m_rectangleComponent->SetColor(D2D1::ColorF(0.8f, 0.8f, 0.8f));
	m_rectangleComponent->SetRectangleSize(Vector2D(24, 150));
	m_rectangleComponent->SetCornersRadius(Vector2D(2, 2));
	SetMaxSpeed(800);
	SetInput(Vector2D(0, 0));
	m_boxCollisionComponent->SetBoxSize(24, 300);
}

void Paddle::EndPlay() {
	Pawn::EndPlay();
}

void Paddle::Tick(float deltaTime) {
	UpdateSpeed(deltaTime);
	Pawn::Tick(deltaTime);
}

void Paddle::UpdateSpeed(float deltaTime) {
	SetCurrentSpeed(m_movementComponent->GetMaxSpeed() * CLAMP(m_input.GetSize(), -1, 1));
	m_movementComponent->SetMovementDirection(m_input.GetNormal());
}

void Paddle::SetInput(Vector2D input) { 
	m_input.SetXY(CLAMP(input.GetX(), -1, 1), CLAMP(input.GetY(), -1, 1));
}