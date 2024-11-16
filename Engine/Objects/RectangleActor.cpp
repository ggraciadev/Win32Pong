#include "RectangleActor.h"

RectangleActor::RectangleActor() {
	m_rectangleComponent = AddActorComponent<RectangleComponent>();
}

RectangleActor::~RectangleActor() {

}


void RectangleActor::BeginPlay() {
	Actor::BeginPlay();
	m_rectangleComponent->SetColor(D2D1::ColorF(0.8f, 0.8f, 0.8f));
	m_rectangleComponent->SetRectangleSize(Vector2D(50, 50));
	m_rectangleComponent->SetCornersRadius(Vector2D(5, 5));
}

void RectangleActor::EndPlay() {
	Actor::EndPlay();
}

void RectangleActor::Tick(float deltaTime) {
	Actor::Tick(deltaTime);
}