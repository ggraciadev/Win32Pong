#include "Paddle.h"
#include "../../Engine/Utils/Utils.h"

Paddle::Paddle() {
	m_rectangleComponent = AddActorComponent<RectangleComponent>();
}

Paddle::~Paddle() {

}


void Paddle::BeginPlay() {
	Pawn::BeginPlay();
	m_rectangleComponent->SetColor(D2D1::ColorF(0.8f, 0.8f, 0.8f));
	m_rectangleComponent->SetRectangleSize(Vector2D(24, 300));
	m_rectangleComponent->SetCornersRadius(Vector2D(2, 2));
	m_maxSpeed = 800;
}

void Paddle::EndPlay() {
	Pawn::EndPlay();
}

void Paddle::Tick(float deltaTime) {
	Pawn::Tick(deltaTime);
	UpdateSpeed(deltaTime);
	AddActorWorldOffset(Vector2D(0, m_currentSpeed));
}

void Paddle::UpdateSpeed(float deltaTime) {
	SetCurrentSpeed(m_maxSpeed * m_input * deltaTime);
}

void Paddle::SetMaxSpeed(float speed) { 
	m_maxSpeed = speed; 
}

void Paddle::SetCurrentSpeed(float speed) { 
	m_currentSpeed = CLAMP(speed, -m_maxSpeed, m_maxSpeed); 

	m_currentSpeed = speed;
}

void Paddle::SetInput(float input) { 
	m_input = CLAMP(input, -1, 1); 
}