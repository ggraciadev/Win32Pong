#pragma once
#include "../Objects/EllipseActor.h"
#include "../Windows/MainWindow.h"
#include "SceneManager.h"

// The GameManager is the class responsible of managin all the game. Is a Singleton to ensure that only exists one copy of it

class GameManager {
private: 
	static GameManager*		s_instance;					// Current instance of the Singleton

	ID2D1HwndRenderTarget*	m_renderTarget = NULL;		// Render target that will be used to render the game		
	MainWindow*				m_mainWindow = NULL;			// A reference to the Main Window 

	bool					m_running = false;			// If the game is still running or not
	bool					m_gameInitialized = false;	// If the scene is initialized

protected:
	GameManager();

	SceneManager*			m_sceneManager = NULL;		// A reference to the SceneManager

public:
	~GameManager();

/**
* Creates an instance of the current GameManager, if not existis, and returns it
* @return A reference of the current GameManager instance
*/
	template< class T> 
	static T* GetInstance();

/**
* Creates an instance of an actor of the type specified and adds it to the current scene actor list
* @return The actor spawned
*/
	template< class T>
	T* SpawnActor();

/**
* Destroys an instance of an actor if is not NULL and removes it from the current scene actor list
* @param actor: the actor to despawn
*/
	void DespawnActor(Actor* actor);


	void InitGameManager(ID2D1HwndRenderTarget* renderTarget, MainWindow* window);
	void StartGame();

	void CreateManagers();

/**
Creates the instance of the Custom Scene Manager. Should be overrided in order to create a User Custom Scene Manager
*/
	virtual void CreateCustomSceneManager() {};

	Scene* GetCurrentScene() const;

/**
* Returns the render target
* @return The render target
*/
	ID2D1HwndRenderTarget* GetRenderTarget() const { return m_renderTarget; }
/**
* Returns if the Game is still running or not
* @return Returns if the Game is still running or not
*/
	bool IsGameRunning() const { return m_running; }

/**
* Set if the Game is running or not
* @param running: The new running value
*/
	void SetGameRunning(bool running) { m_running = false; }

/**
This method is called to create and initialize the current scene
*/
	void InitScene();

/**
This method is called when the current Scene starts
*/
	void StartScene();

/**
* This methos is called to update the current Scene
* @param deltaTime: Time ellapsed from the previous frame
*/
	void UpdateScene(float deltaTime);

/**
This method is called to render the current Scene
*/
	void RenderScene();
};



template<class T>
T* GameManager::GetInstance() {
	if (s_instance == nullptr) {
		s_instance = new T();
	}
	return (T*)(s_instance);
}

template< class T>
T* GameManager::SpawnActor() {
	T* actor = new T();
	bool result = GetCurrentScene()->AddActorToScene(actor);
	if (!result) {
		delete actor;
		return NULL;
	}
	return actor;
}