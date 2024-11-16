#include "MyEllipseActor.h"
#include "../Managers/MyGameManager.h"

MyEllipseActor::MyEllipseActor() {
	
}

MyEllipseActor::~MyEllipseActor() {

}


void MyEllipseActor::BeginPlay() {
	EllipseActor::BeginPlay();
	m_ellipseComponent->SetColor(D2D1::ColorF(1.0f, 1.0f, 0));
	m_ellipseComponent->SetEllipseRadius(Vector2D(50, 50));
}

void MyEllipseActor::EndPlay() {
	EllipseActor::EndPlay();
}

void MyEllipseActor::Tick(float deltaTime) {
	EllipseActor::Tick(deltaTime);
	m_transform.SetPosition(m_transform.GetPosition() + Vector2D(1, 0));
}