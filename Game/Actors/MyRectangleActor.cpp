#include "MyRectangleActor.h"

MyRectangleActor::MyRectangleActor() {
	
}

MyRectangleActor::~MyRectangleActor() {

}


void MyRectangleActor::BeginPlay() {
	RectangleActor::BeginPlay();
	m_rectangleComponent->SetColor(D2D1::ColorF(1.0f, 1.0f, 0));
	m_rectangleComponent->SetRectangleSize(Vector2D(50, 50));
	m_rectangleComponent->SetCornersRadius(Vector2D(5, 5));

}

void MyRectangleActor::EndPlay() {
	RectangleActor::EndPlay();
}

void MyRectangleActor::Tick(float deltaTime) {
	RectangleActor::Tick(deltaTime);
	m_transform.SetPosition(m_transform.GetPosition() + Vector2D(1, 1));
}