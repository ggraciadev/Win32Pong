#pragma once
#include "../Objects/EllipseActor.h"
#include "../Windows/MainWindow.h"
#include "../Objects/Scene.h"

// The GameManager is the class responsible of managin all the game. Is a Singleton to ensure that only exists one copy of it

class GameManager {
private: 
	static GameManager*		pInstance;					// Current instance of the Singleton

	ID2D1HwndRenderTarget*	pRenderTarget;				// Render target that will be used to render the game		
	MainWindow*				pMainWindow;				// A reference to the Main Window 

	Scene*					pCurrentScene;				// A reference to the current scene

	bool					pRunning = false;			// If the game is still running or not
	bool					pSceneInitialized = false;	// If the scene is initialized

protected:
	GameManager();

public:
	~GameManager();

/**
* Creates an instance of the current GameManager, if not existis, and returns it
* @return A reference of the current GameManager instance
*/
	template< class T> 
	static T* GetInstance();


	void InitGameManager(ID2D1HwndRenderTarget* renderTarget, MainWindow* window);


/**
* Returns the render target
* @return The render target
*/
	ID2D1HwndRenderTarget* GetRenderTarget() const { return pRenderTarget; }
/**
* Returns if the Game is still running or not
* @return Returns if the Game is still running or not
*/
	bool IsGameRunning() const { return pRunning; }

/**
* Set if the Game is running or not
* @param running: The new running value
*/
	void SetGameRunning(bool running) { pRunning = false; }

/**
This method is called to create and initialize the current scene
*/
	virtual void InitScene();

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
* This methos is called to set the current scene
* @param scene: The new current scene
*/
	void SetCurrentScene(Scene* scene);

/**
This method is called to render the current Scene
*/
	void RenderScene();
};


template<class T>
T* GameManager::GetInstance() {
	if (pInstance == nullptr) {
		pInstance = new T();
	}
	return (T*)(pInstance);
}