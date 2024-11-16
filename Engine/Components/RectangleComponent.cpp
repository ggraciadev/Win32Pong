#include "RectangleComponent.h"
#include "../Objects/Actor.h"

RectangleComponent::RectangleComponent() {
	
}

void RectangleComponent::UpdateShape() {
	Vector2D sizeMulti = Vector2D(
		m_actor->GetTransform()->GetScale().GetX() * m_transform.GetScale().GetX(),
		m_actor->GetTransform()->GetScale().GetY() * m_transform.GetScale().GetY());

	m_rectangle.rect = D2D1::RectF(
		m_actor->GetTransform()->GetPosition().GetX() + m_transform.GetPosition().GetX() - (m_rectangleSize.GetX() * sizeMulti.GetX()) / 2.0f,
		m_actor->GetTransform()->GetPosition().GetY() + m_transform.GetPosition().GetY() - (m_rectangleSize.GetY() * sizeMulti.GetY()) / 2.0f,
		m_actor->GetTransform()->GetPosition().GetX() + m_transform.GetPosition().GetX() + (m_rectangleSize.GetX() * sizeMulti.GetX()) / 2.0f,
		m_actor->GetTransform()->GetPosition().GetY() + m_transform.GetPosition().GetY() + (m_rectangleSize.GetY() * sizeMulti.GetY()) / 2.0f
	);

	m_rectangle.radiusX = m_cornerRadius.GetX() * sizeMulti.GetX();
	m_rectangle.radiusY = m_cornerRadius.GetY() * sizeMulti.GetY();
}

void RectangleComponent::Draw() {
	ID2D1HwndRenderTarget* renderTarget = m_actor->GetRenderTarget();
	if (renderTarget != NULL) {
		DrawableShapeComponent::Draw(renderTarget);
		renderTarget->FillRoundedRectangle(m_rectangle, m_brush);
	}
}

void RectangleComponent::BeginPlay() {
	DrawableShapeComponent::BeginPlay();
	UpdateShape();
}

void RectangleComponent::EndPlay() {
	DrawableShapeComponent::EndPlay();
}