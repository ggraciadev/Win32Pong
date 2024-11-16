#include "RectangleComponent.h"
#include "../Objects/Actor.h"

RectangleComponent::RectangleComponent() {
	
}

void RectangleComponent::UpdateShape() {
	Vector2D sizeMulti = Vector2D(
		pActor->GetTransform()->GetScale().GetX() * pTransform.GetScale().GetX(),
		pActor->GetTransform()->GetScale().GetY() * pTransform.GetScale().GetY());

	pRectangle.rect = D2D1::RectF(
		pActor->GetTransform()->GetPosition().GetX() + pTransform.GetPosition().GetX() - (pRectangleSize.GetX() * sizeMulti.GetX()) / 2.0f,
		pActor->GetTransform()->GetPosition().GetY() + pTransform.GetPosition().GetY() - (pRectangleSize.GetY() * sizeMulti.GetY()) / 2.0f,
		pActor->GetTransform()->GetPosition().GetX() + pTransform.GetPosition().GetX() + (pRectangleSize.GetX() * sizeMulti.GetX()) / 2.0f,
		pActor->GetTransform()->GetPosition().GetY() + pTransform.GetPosition().GetY() + (pRectangleSize.GetY() * sizeMulti.GetY()) / 2.0f
	);

	pRectangle.radiusX = pCornerRadius.GetX() * sizeMulti.GetX();
	pRectangle.radiusY = pCornerRadius.GetY() * sizeMulti.GetY();
}

void RectangleComponent::Draw() {
	ID2D1HwndRenderTarget* renderTarget = pActor->GetRenderTarget();
	if (renderTarget != NULL) {
		DrawableShapeComponent::Draw(renderTarget);
		renderTarget->FillRoundedRectangle(pRectangle, pBrush);
	}
}

void RectangleComponent::BeginPlay() {
	DrawableShapeComponent::BeginPlay();
	UpdateShape();
}

void RectangleComponent::EndPlay() {
	DrawableShapeComponent::EndPlay();
}