#pragma once
#include "EllipseActor.h"

class GameManager {
private: 
	static GameManager* pInstance;

	ID2D1HwndRenderTarget* pRenderTarget;
	EllipseActor* pEllipseActor;
	bool pRunning;

	bool pSceneInitialized = false;

	GameManager();
public:
	~GameManager();
	static GameManager* GetInstance();
	void InitGameManager(ID2D1HwndRenderTarget* renderTarget);

	bool IsGameRunning() const { return pRunning; }
	void SetGameRunning(bool running) { pRunning = false; }

	void InitScene();
	void StartScene();
	void UpdateScene(float deltaTime);
	void RenderScene();
};