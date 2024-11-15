#include "DrawableShapeComponent.h"
#include <d2d1.h>
#include "Utils.h"

DrawableShapeComponent::DrawableShapeComponent() {
	pIsDrawable = true;
}

DrawableShapeComponent::~DrawableShapeComponent() {

}

void DrawableShapeComponent::Init(Actor* actor) {
	pActor = actor;
}

void DrawableShapeComponent::Init(Actor* actor, const Transform& transform, ID2D1HwndRenderTarget* renderTarget) {
	pActor = actor;
	renderTarget->CreateSolidColorBrush(pColor, &pBrush);
	ActorComponent::Init(actor, transform, renderTarget);
}

void DrawableShapeComponent::Init(Actor* actor, const Transform& transform, ID2D1HwndRenderTarget* renderTarget, D2D1_COLOR_F color) {
	pActor = actor;
	pColor = color;
	renderTarget->CreateSolidColorBrush(pColor, &pBrush);
	ActorComponent::Init(actor, transform, renderTarget);
}

void DrawableShapeComponent::BeginPlay() {

}

void DrawableShapeComponent::EndPlay() {
	SafeDestroy(&pBrush);
}