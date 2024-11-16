#include "Actor.h"
#include "../Components/ActorComponent.h"
#include "../Managers/GameManager.h"

Actor::Actor() {
	SetTransform(Transform(Vector2D(0, 0), 0, Vector2D(1, 1)));
}

Actor::~Actor() {
	EndPlay();

	int size = m_actorComponents.size();
	for (int i = size - 1; i >= 0; --i) {
		if (m_actorComponents[i] != NULL) {
			delete m_actorComponents[i];
			m_actorComponents[i] = NULL;
		}
	}
}

void Actor::Init() {
	ID2D1HwndRenderTarget* renderTarget = GameManager::GetInstance<GameManager>()->GetRenderTarget();
	if (renderTarget != NULL) {
		m_renderTarget = renderTarget;
		int size = m_actorComponents.size();
		for (int i = 0; i < size; ++i) {
			m_actorComponents[i]->Init(this);
		}
	}
}

void Actor::SetTransform(const Transform& transform) {
	m_transform.SetPosition(transform.GetPosition());
	m_transform.SetRotation(transform.GetRotation());
	m_transform.SetScale(transform.GetScale());
}

void Actor::BeginPlay() {
	int size = m_actorComponents.size();
	for (int i = 0; i < size; ++i) {
		m_actorComponents[i]->BeginPlay();
	}
}

void Actor::EndPlay() {

}

void Actor::Tick(float deltaTime) {
	int size = m_actorComponents.size();
	for (int i = 0; i < size; ++i) {
		m_actorComponents[i]->Tick(deltaTime);
	}
}

void Actor::Draw() {
	int size = m_actorComponents.size();
	for (int i = 0; i < size; ++i) {
		m_actorComponents[i]->SafeDraw();
	}
}