#include "EllipseActor.h"

EllipseActor::EllipseActor() {
	m_ellipseComponent = AddActorComponent<EllipseComponent>();
	
}

EllipseActor::~EllipseActor() {

}


void EllipseActor::BeginPlay() {
	Actor::BeginPlay();
	m_ellipseComponent->SetColor(D2D1::ColorF(0.8f, 0.8f, 0.8f));
	m_ellipseComponent->SetEllipseRadius(Vector2D(50, 50));
}

void EllipseActor::EndPlay() {
	Actor::EndPlay();
}

void EllipseActor::Tick(float deltaTime) {
	Actor::Tick(deltaTime);
}