#include "DrawableShapeComponent.h"
#include <d2d1.h>
#include "Actor.h"
#include "Utils.h"

DrawableShapeComponent::DrawableShapeComponent() {
	pIsDrawable = true;
}

DrawableShapeComponent::~DrawableShapeComponent() {
	
}

void DrawableShapeComponent::Init(Actor* actor, const Transform& transform) {
	DrawableShapeComponent::Init(actor, transform, D2D1::ColorF(0.8f, 0.8f, 0.8f));
}

void DrawableShapeComponent::Init(Actor* actor, const Transform& transform, D2D1_COLOR_F color) {
	ActorComponent::Init(actor, transform);
	pColor = color;
	ID2D1HwndRenderTarget* renderTarget = pActor->GetRenderTarget();
	if (renderTarget != NULL) {
		renderTarget->CreateSolidColorBrush(pColor, &pBrush);
	}
}

void DrawableShapeComponent::BeginPlay() {

}

void DrawableShapeComponent::Draw(ID2D1HwndRenderTarget* renderTarget) {
	UpdateShape();
}

void DrawableShapeComponent::EndPlay() {
	SafeRelease(&pBrush);
}