#include "Actor.h"
#include "../Components/ActorComponent.h"
#include "../Managers/GameManager.h"

Actor::Actor() {
	SetTransform(Transform(Vector2D(0, 0), 0, Vector2D(1, 1)));
}

Actor::~Actor() {
	EndPlay();

	int size = pActorComponents.size();
	for (int i = size - 1; i >= 0; --i) {
		if (pActorComponents[i] != NULL) {
			delete pActorComponents[i];
			pActorComponents[i] = NULL;
		}
	}
}

void Actor::Init() {
	ID2D1HwndRenderTarget* renderTarget = GameManager::GetInstance<GameManager>()->GetRenderTarget();
	if (renderTarget != NULL) {
		pRenderTarget = renderTarget;
		int size = pActorComponents.size();
		for (int i = 0; i < size; ++i) {
			pActorComponents[i]->Init(this);
		}
	}
}

void Actor::SetTransform(const Transform& transform) {
	pTransform.SetPosition(transform.GetPosition());
	pTransform.SetRotation(transform.GetRotation());
	pTransform.SetScale(transform.GetScale());
}

void Actor::AddActorComponent(ActorComponent* actorComponent) {
	pActorComponents.push_back(actorComponent);
}

void Actor::BeginPlay() {
	int size = pActorComponents.size();
	for (int i = 0; i < size; ++i) {
		pActorComponents[i]->BeginPlay();
	}
}

void Actor::EndPlay() {

}

void Actor::Tick(float deltaTime) {
	int size = pActorComponents.size();
	for (int i = 0; i < size; ++i) {
		pActorComponents[i]->Tick(deltaTime);
	}
}

void Actor::Draw() {
	int size = pActorComponents.size();
	for (int i = 0; i < size; ++i) {
		pActorComponents[i]->SafeDraw();
	}
}