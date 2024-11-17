#include "BoxCollisionComponent.h"
#include "../Objects/Actor.h"

BoxCollisionComponent::BoxCollisionComponent() {
	
}

void BoxCollisionComponent::BeginPlay() {
	CollisionComponent::BeginPlay();
}

void BoxCollisionComponent::EndPlay() {
	CollisionComponent::EndPlay();
}

bool BoxCollisionComponent::CheckCollision(BoxCollisionComponent* other) const {

	bool result = false;
	// Calc the total size of my box collision
	Vector2D mySize = Vector2D(m_transform.GetScale().GetX() * m_actor->GetTransform()->GetScale().GetX() * m_BoxSize.GetX(),
		m_transform.GetScale().GetY() * m_actor->GetTransform()->GetScale().GetY() * m_BoxSize.GetY());
	// Calc the absolute position of my box collision
	Vector2D myPos = m_transform.GetPosition() + m_actor->GetTransform()->GetPosition() - (mySize / 2);

	// Calc the total size of the other box collision
	Vector2D otherSize = Vector2D(other->m_transform.GetScale().GetX() * other->m_actor->GetTransform()->GetScale().GetX() * other->m_BoxSize.GetX(),
		other->m_transform.GetScale().GetY() * other->m_actor->GetTransform()->GetScale().GetY() * other->m_BoxSize.GetY());
	// Calc the absolute position of the other box collision
	Vector2D otherPos = other->m_transform.GetPosition() + other->m_actor->GetTransform()->GetPosition() - (otherSize / 2);

	// Basic check if my box collision is inside the other one
	result = (myPos.GetX() <= otherPos.GetX() + otherSize.GetX() && myPos.GetX() + mySize.GetX() >= otherPos.GetX() &&
		myPos.GetY() <= otherPos.GetY() + otherSize.GetY() && myPos.GetY() + mySize.GetY() >= otherPos.GetY());


	return result;
}