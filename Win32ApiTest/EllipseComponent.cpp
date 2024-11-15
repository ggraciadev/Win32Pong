#include "EllipseComponent.h"
#include "Actor.h"

EllipseComponent::EllipseComponent() {
	
}

void EllipseComponent::UpdateShape() {
	pEllipse.point = D2D1::Point2F(
		pActor->GetTransform()->GetPosition().GetX() + pTransform.GetPosition().GetX(),
		pActor->GetTransform()->GetPosition().GetY() + pTransform.GetPosition().GetY());
	pEllipse.radiusX = pEllipseRadius.GetX() * pActor->GetTransform()->GetScale().GetX() * pTransform.GetScale().GetX();
	pEllipse.radiusY = pEllipseRadius.GetY() * pActor->GetTransform()->GetScale().GetY() * pTransform.GetScale().GetY();
}

void EllipseComponent::Draw() {
	ID2D1HwndRenderTarget* renderTarget = pActor->GetRenderTarget();
	if (renderTarget != NULL) {
		DrawableShapeComponent::Draw(renderTarget);
		renderTarget->FillEllipse(pEllipse, pBrush);
	}
}

void EllipseComponent::BeginPlay() {
	DrawableShapeComponent::BeginPlay();
	UpdateShape();
}

void EllipseComponent::EndPlay() {
	DrawableShapeComponent::EndPlay();
}