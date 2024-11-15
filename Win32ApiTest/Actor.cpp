#include "Actor.h"
#include "ActorComponent.h"

Actor::Actor() {
	//Init();
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
	
}

void Actor::Init(const Transform& transform, ID2D1HwndRenderTarget* renderTarget) {
	SetTransform(transform);
	pRenderTarget = renderTarget;
	int size = pActorComponents.size();
	for (int i = 0; i < size; ++i) {
		pActorComponents[i]->Init(this, transform, renderTarget);
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
		pActorComponents[i]->SafeDraw(pRenderTarget);
	}
}