#include "ActorComponent.h"


ActorComponent::ActorComponent() {
	pTransform.SetPosition(Vector2D(0, 0));
	pTransform.SetRotation(0);
	pTransform.SetScale(Vector2D(1, 1));
}


ActorComponent::~ActorComponent() {

}

void ActorComponent::Init(Actor* actor) {
	pActor = actor;
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

void ActorComponent::SafeDraw() {
	if (pIsDrawable) {
		Draw();
	}
}