#include "ActorComponent.h"


ActorComponent::ActorComponent() {

}


ActorComponent::~ActorComponent() {

}


void ActorComponent::Init(Actor* actor) {
	pActor = actor;
}

void ActorComponent::Init(Actor* actor, const Transform& transform, ID2D1HwndRenderTarget* renderTarget) {
	pActor = actor;
	pTransform.SetPosition(transform.GetPosition());
	pTransform.SetRotation(transform.GetRotation());
	pTransform.SetScale(transform.GetScale());
}

void ActorComponent::SetComponentPosition(Vector2D position) {
	pTransform.SetPosition(position);
}

void ActorComponent::SetComponentRotation(float rotation) {
	pTransform.SetRotation(rotation);
}

void ActorComponent::SetComponentScale(Vector2D scale) {
	pTransform.SetScale(scale);
}

void ActorComponent::SafeTick(float deltaTime) {
	if(pCanEverTick) {
		Tick(deltaTime);
	}
}

void ActorComponent::SafeDraw(ID2D1HwndRenderTarget* renderTarget) {
	if (pIsDrawable) {
		Draw(renderTarget);
	}
}