#include "RectangleActor.h"

RectangleActor::RectangleActor() {
	pRectangleComponent = new RectangleComponent();
	AddActorComponent(pRectangleComponent);
}

RectangleActor::~RectangleActor() {

}


void RectangleActor::BeginPlay() {
	Actor::BeginPlay();
	pRectangleComponent->SetColor(D2D1::ColorF(0.8f, 0.8f, 0.8f));
	pRectangleComponent->SetRectangleSize(Vector2D(50, 50));
	pRectangleComponent->SetCornersRadius(Vector2D(5, 5));
}

void RectangleActor::EndPlay() {
	Actor::EndPlay();
}

void RectangleActor::Tick(float deltaTime) {
	Actor::Tick(deltaTime);
}