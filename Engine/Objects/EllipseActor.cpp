#include "EllipseActor.h"

EllipseActor::EllipseActor() {
	pEllipseComponent = new EllipseComponent();
	AddActorComponent(pEllipseComponent);
}

EllipseActor::~EllipseActor() {

}


void EllipseActor::BeginPlay() {
	Actor::BeginPlay();
	pEllipseComponent->SetColor(D2D1::ColorF(0.8f, 0.8f, 0.8f));
	pEllipseComponent->SetEllipseRadius(Vector2D(50, 50));
}

void EllipseActor::EndPlay() {
	Actor::EndPlay();
}

void EllipseActor::Tick(float deltaTime) {
	Actor::Tick(deltaTime);
}