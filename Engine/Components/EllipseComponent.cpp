#include "EllipseComponent.h"
#include "../Objects/Actor.h"

EllipseComponent::EllipseComponent() {
	
}

void EllipseComponent::UpdateShape() {
	m_ellipse.point = D2D1::Point2F(
		m_actor->GetTransform()->GetPosition().GetX() + m_transform.GetPosition().GetX(),
		m_actor->GetTransform()->GetPosition().GetY() + m_transform.GetPosition().GetY());
	m_ellipse.radiusX = m_ellipseRadius.GetX() * m_actor->GetTransform()->GetScale().GetX() * m_transform.GetScale().GetX();
	m_ellipse.radiusY = m_ellipseRadius.GetY() * m_actor->GetTransform()->GetScale().GetY() * m_transform.GetScale().GetY();
}

void EllipseComponent::Draw() {
	ID2D1HwndRenderTarget* renderTarget = m_actor->GetRenderTarget();
	if (renderTarget != NULL) {
		DrawableShapeComponent::Draw(renderTarget);
		renderTarget->FillEllipse(m_ellipse, m_brush);
	}
}

void EllipseComponent::BeginPlay() {
	DrawableShapeComponent::BeginPlay();
	UpdateShape();
}

void EllipseComponent::EndPlay() {
	DrawableShapeComponent::EndPlay();
}