#include "EllipseActor.h"

EllipseActor::EllipseActor() {
	pEllipseComponent = new EllipseComponent();
	pEllipseComponent->SetColor(D2D1::ColorF(1.0f, 1.0f, 0));
	pEllipseComponent->SetEllipseRadius(Vector2D(50, 50));
	AddActorComponent(pEllipseComponent);
}

EllipseActor::~EllipseActor() {

}


void EllipseActor::BeginPlay() {
	Actor::BeginPlay();
}

void EllipseActor::EndPlay() {
	Actor::EndPlay();
}

void EllipseActor::Tick(float deltaTime) {
	Actor::Tick(deltaTime);
}