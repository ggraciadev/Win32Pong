#include "MyEllipseActor.h"

MyEllipseActor::MyEllipseActor() {
	pEllipseComponent->SetColor(D2D1::ColorF(1.0f, 1.0f, 0));
	pEllipseComponent->SetEllipseRadius(Vector2D(50, 50));
}

MyEllipseActor::~MyEllipseActor() {

}


void MyEllipseActor::BeginPlay() {
	EllipseActor::BeginPlay();
}

void MyEllipseActor::EndPlay() {
	EllipseActor::EndPlay();
}

void MyEllipseActor::Tick(float deltaTime) {
	EllipseActor::Tick(deltaTime);
	pTransform.SetPosition(pTransform.GetPosition() + Vector2D(1, 0));
}