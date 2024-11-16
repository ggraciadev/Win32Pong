#include "Scene.h"
#include <d2d1.h>
#include <Windows.h>

Scene::Scene() {

}

Scene::~Scene() {
	int size = m_actors.size();
	for (int i = size - 1; i >= 0; --i) {
		if (m_actors[i] != NULL) {
			delete m_actors[i];
		}
	}
}

/**
This event is called to initialize a Scene
*/
void Scene::Init() {
	int size = m_actors.size();
	for (int i = 0; i < size; ++i) {
		if (m_actors[i] != NULL) {
			m_actors[i]->Init();
		}
	}
}

void Scene::BeginPlay() {
	int size = m_actors.size();
	for (int i = 0; i < size; ++i) {
		if (m_actors[i] != NULL) {
			m_actors[i]->BeginPlay();
		}
	}
	m_sceneStarted = true;
}


/**
This event is for the logic of the component, the behaviour that has to be updated frame by frame if needed.
*/
void Scene::Tick(float deltaTime) {
	int size = m_actors.size();
	for (int i = size-1; i >= 0; --i) {
		if (m_actors[i] != NULL) {
			m_actors[i]->Tick(deltaTime);
		}
	}
}

/**
This event is for the rendering of the Actor. This method automaticaly calls the SafeDraw of all its ActorComponents
*/
void Scene::Draw() {
	int size = m_actors.size();
	for (int i = 0; i < size; ++i) {
		if (m_actors[i] != NULL) {
			m_actors[i]->Draw();
		}
	}
}

int Scene::GetActorIndexInScene(const Actor* actor) const {
	int size = m_actors.size();
	int index = -1;
	int i = -1;

	while (++i < size && index == -1) {
		if (actor == m_actors[i]) {
			index = i;
		}
	}
	return index;
}

bool Scene::IsActorInScene(const Actor* actor) const {
	return GetActorIndexInScene(actor) != -1;
}

bool Scene::AddActorToScene(Actor* actor) {
	bool result = false;
	if (actor != NULL && !IsActorInScene(actor)) {
		m_actors.push_back(actor);
		if (m_sceneStarted) {
			actor->Init();
			actor->BeginPlay();
		}
		result = true;
	}
	return result;
}

bool Scene::RemoveActorFromScene(Actor* actor) {
	int index = GetActorIndexInScene(actor);
	if (index != -1) {
		m_actors.erase(m_actors.begin() + index);
		return true;
	}
	return false;
}

void Scene::DestroyActor(Actor* actor) {
	int index = GetActorIndexInScene(actor);
	delete actor;
	if (index != -1) {
		m_actors.erase(m_actors.begin() + index);
	}
}