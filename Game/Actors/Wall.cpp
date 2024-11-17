#include "Wall.h"
#include "../Managers/MyGameManager.h"

Wall::Wall() {
	m_boxCollisionComponent = AddActorComponent<BoxCollisionComponent>();
}

Wall::~Wall() {

}


void Wall::BeginPlay() {
	RectangleActor::BeginPlay();
	Vector2D size = MyGameManager::GetInstance<MyGameManager>()->GetWindowSize();
	size.SetY(50);
	m_rectangleComponent->SetColor(D2D1::ColorF(0.3f, 0.3f, 0.3f));
	m_rectangleComponent->SetRectangleSize(size);
	m_rectangleComponent->SetCornersRadius(Vector2D(5, 5));

	m_boxCollisionComponent->SetBoxSize(size);

}

void Wall::EndPlay() {
	RectangleActor::EndPlay();
}

void Wall::Tick(float deltaTime) {
	RectangleActor::Tick(deltaTime);
}