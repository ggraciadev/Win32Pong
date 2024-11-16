#include "DrawableShapeComponent.h"
#include <d2d1.h>
#include "../Objects/Actor.h"
#include "../Utils/Utils.h"

DrawableShapeComponent::DrawableShapeComponent() {
	m_isDrawable = true;
}

DrawableShapeComponent::~DrawableShapeComponent() {
	if (m_brush != NULL) {
		m_brush->Release();
		m_brush = NULL;
	}
}

void DrawableShapeComponent::Init(Actor* actor) {
	DrawableShapeComponent::Init(actor, D2D1::ColorF(0.8f, 0.8f, 0.8f));
}

void DrawableShapeComponent::Init(Actor* actor, D2D1_COLOR_F color) {
	ActorComponent::Init(actor);
	m_color = color;
	ID2D1HwndRenderTarget* renderTarget = m_actor->GetRenderTarget();
	if (renderTarget != NULL) {
		renderTarget->CreateSolidColorBrush(m_color, &m_brush);
	}
}

void DrawableShapeComponent::SetColor(D2D1_COLOR_F color) {
	m_color = color;
	m_brush->SetColor(m_color);
}

void DrawableShapeComponent::BeginPlay() {

}

void DrawableShapeComponent::Draw(ID2D1HwndRenderTarget* renderTarget) {
	UpdateShape();
}

void DrawableShapeComponent::EndPlay() {
	SafeRelease(&m_brush);
}