#include "Goal.h"
#include "../Managers/MyGameManager.h"

Goal::Goal() {
	m_boxCollisionComponent = AddActorComponent<BoxCollisionComponent>();
}

Goal::~Goal() {

}


void Goal::BeginPlay() {
	RectangleActor::BeginPlay();
	Vector2D size = MyGameManager::GetInstance<MyGameManager>()->GetWindowSize();
	size.SetX(50);
	m_rectangleComponent->SetColor(D2D1::ColorF(0.9f, 0.3f, 0.3f));
	m_rectangleComponent->SetRectangleSize(size);
	m_rectangleComponent->SetCornersRadius(Vector2D(5, 5));

	m_boxCollisionComponent->SetBoxSize(size - Vector2D(25, 0));

}

void Goal::EndPlay() {
	RectangleActor::EndPlay();
}

void Goal::Tick(float deltaTime) {
	RectangleActor::Tick(deltaTime);
}