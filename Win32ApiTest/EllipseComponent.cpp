#include "EllipseComponent.h"
#include "Actor.h"

EllipseComponent::EllipseComponent() {
	
}

void EllipseComponent::Draw(ID2D1HwndRenderTarget* renderTarget) {
	pEllipse.point = D2D1::Point2F(
		pActor->GetTransform()->GetPosition().GetX() + pTransform.GetPosition().GetX(),
		pActor->GetTransform()->GetPosition().GetY() + pTransform.GetPosition().GetY());
	renderTarget->FillEllipse(pEllipse, pBrush);
}

void EllipseComponent::BeginPlay() {
	DrawableShapeComponent::BeginPlay();
	pEllipse = D2D1::Ellipse(D2D1::Point2F(
		pActor->GetTransform()->GetPosition().GetX() + pTransform.GetPosition().GetX(), 
		pActor->GetTransform()->GetPosition().GetY() + pTransform.GetPosition().GetY()), 
		pEllipseRadius.GetX(), pEllipseRadius.GetY());
}

void EllipseComponent::EndPlay() {
	DrawableShapeComponent::EndPlay();
}