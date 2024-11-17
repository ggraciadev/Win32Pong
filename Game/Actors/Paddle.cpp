#include "Paddle.h"
#include "../../Engine/Utils/Utils.h"

Paddle::Paddle() {
	m_rectangleComponent = AddActorComponent<RectangleComponent>();
	m_boxCollisionComponent = AddActorComponent<BoxCollisionComponent>();
}

Paddle::~Paddle() {

}


void Paddle::BeginPlay() {
	Pawn::BeginPlay();
	m_rectangleComponent->SetColor(D2D1::ColorF(0.8f, 0.8f, 0.8f));
	m_rectangleComponent->SetRectangleSize(Vector2D(24, 150));
	m_rectangleComponent->SetCornersRadius(Vector2D(2, 2));
	m_maxSpeed = 800;
	SetInput(Vector2D(0, 0));
	m_boxCollisionComponent->SetBoxSize(24, 300);
}

void Paddle::EndPlay() {
	Pawn::EndPlay();
}

void Paddle::Tick(float deltaTime) {
	Pawn::Tick(deltaTime);
	UpdateSpeed(deltaTime);
	if (m_input.GetY() < 0) {
		Vector2D temp = m_input.GetNormal();
	}
	AddActorWorldOffset(m_input.GetNormal() * m_currentSpeed * deltaTime);
}

void Paddle::UpdateSpeed(float deltaTime) {
	SetCurrentSpeed(m_maxSpeed * m_input.GetSize());

}

void Paddle::SetMaxSpeed(float speed) { 
	m_maxSpeed = speed; 
}

void Paddle::SetCurrentSpeed(float speed) { 
	m_currentSpeed = CLAMP(speed, -m_maxSpeed, m_maxSpeed);
}

void Paddle::SetInput(Vector2D input) { 
	m_input.SetXY(CLAMP(input.GetX(), -1, 1), CLAMP(input.GetY(), -1, 1));
}

void Paddle::SetInputX(float input) {
	m_input.SetX(CLAMP(input, -1, 1));
}

void Paddle::SetInputY(float input) {
	m_input.SetY(CLAMP(input, -1, 1));
}