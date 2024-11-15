#include "EllipseActor.h"
#include "../Components/EllipseComponent.h"

EllipseActor::EllipseActor() {
	pEllipseComponent = new EllipseComponent();
	pEllipseComponent->SetColor(D2D1::ColorF(1.0f, 1.0f, 0));
	AddActorComponent(pEllipseComponent);
}

EllipseActor::~EllipseActor() {

}


void EllipseActor::BeginPlay() {
	pEllipseComponent->SetEllipseRadius(Vector2D(50, 50));
	Actor::BeginPlay();
}

void EllipseActor::EndPlay() {
	Actor::EndPlay();
}

void EllipseActor::Tick(float deltaTime) {
	Actor::Tick(deltaTime);
	pTransform.SetPosition(pTransform.GetPosition() + Vector2D(1, 0));
}