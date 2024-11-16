#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {
	int size = pActors.size();
	for (int i = size - 1; i >= 0; --i) {
		if (pActors[i] != NULL) {
			delete pActors[i];
		}
	}
}

/**
This event is called to initialize a Scene
*/
void Scene::Init() {
	int size = pActors.size();
	for (int i = 0; i < size; ++i) {
		if (pActors[i] != NULL) {
			pActors[i]->Init();
		}
	}
}

void Scene::BeginPlay() {
	int size = pActors.size();
	for (int i = 0; i < size; ++i) {
		if (pActors[i] != NULL) {
			pActors[i]->BeginPlay();
		}
	}
	sceneStarted = true;
}


/**
This event is for the logic of the component, the behaviour that has to be updated frame by frame if needed.
*/
void Scene::Tick(float deltaTime) {
	int size = pActors.size();
	for (int i = size-1; i >= 0; --i) {
		if (pActors[i] != NULL) {
			pActors[i]->Tick(deltaTime);
		}
	}
}

/**
This event is for the rendering of the Actor. This method automaticaly calls the SafeDraw of all its ActorComponents
*/
void Scene::Draw() {
	int size = pActors.size();
	for (int i = 0; i < size; ++i) {
		if (pActors[i] != NULL) {
			pActors[i]->Draw();
		}
	}
}

int Scene::GetActorIndexInScene(const Actor* actor) const {
	int size = pActors.size();
	int index = -1;
	int i = -1;

	while (++i < size && index == -1) {
		if (actor == pActors[i]) {
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
		pActors.push_back(actor);
		if (sceneStarted) {
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
		pActors.erase(pActors.begin() + index);
		return true;
	}
	return false;
}

void Scene::DestroyActor(Actor* actor) {
	int index = GetActorIndexInScene(actor);
	delete actor;
	if (index != -1) {
		pActors.erase(pActors.begin() + index);
	}
}