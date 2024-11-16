#include "MyRectangleActor.h"

MyRectangleActor::MyRectangleActor() {

}

MyRectangleActor::~MyRectangleActor() {

}


void MyRectangleActor::BeginPlay() {
	RectangleActor::BeginPlay();
	pRectangleComponent->SetColor(D2D1::ColorF(1.0f, 1.0f, 0));
	pRectangleComponent->SetRectangleSize(Vector2D(50, 50));
	pRectangleComponent->SetCornersRadius(Vector2D(5, 5));
}

void MyRectangleActor::EndPlay() {
	RectangleActor::EndPlay();
}

void MyRectangleActor::Tick(float deltaTime) {
	RectangleActor::Tick(deltaTime);
	pTransform.SetPosition(pTransform.GetPosition() + Vector2D(0, 1));
}