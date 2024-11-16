#include "DrawableShapeComponent.h"
#include <d2d1.h>
#include "../Objects/Actor.h"
#include "../Utils/Utils.h"

DrawableShapeComponent::DrawableShapeComponent() {
	pIsDrawable = true;
}

DrawableShapeComponent::~DrawableShapeComponent() {
	if (pBrush != NULL) {
		pBrush->Release();
		pBrush = NULL;
	}
}

void DrawableShapeComponent::Init(Actor* actor) {
	DrawableShapeComponent::Init(actor, D2D1::ColorF(0.8f, 0.8f, 0.8f));
}

void DrawableShapeComponent::Init(Actor* actor, D2D1_COLOR_F color) {
	ActorComponent::Init(actor);
	pColor = color;
	ID2D1HwndRenderTarget* renderTarget = pActor->GetRenderTarget();
	if (renderTarget != NULL) {
		renderTarget->CreateSolidColorBrush(pColor, &pBrush);
	}
}

void DrawableShapeComponent::SetColor(D2D1_COLOR_F color) {
	pColor = color;
	pBrush->SetColor(pColor);
}

void DrawableShapeComponent::BeginPlay() {

}

void DrawableShapeComponent::Draw(ID2D1HwndRenderTarget* renderTarget) {
	UpdateShape();
}

void DrawableShapeComponent::EndPlay() {
	SafeRelease(&pBrush);
}