#pragma once
#include "../../Engine/Managers/GameManager.h"

class MyGameManager : public GameManager {

protected:
	int m_scorePlayerA = 0;
	int m_scorePlayerB = 0;

public:
	friend class GameManager; // This has to be done in order to allow acces to the GameManager to the Constructor method

/**
Creates the instance of the Custom Scene Manager. Should be overrided in order to create a User Custom Scene Manager
*/
	virtual void CreateCustomSceneManager();

/**
Creates the instance of the Custom Input Manager. Should be overrided in order to create a User Custom Input Manager
*/
	virtual void CreateCustomInputManager();

	void AddScorePlayerA() { m_scorePlayerA++; }
	int GetScorePlayerA() { return m_scorePlayerA; }
	void AddScorePlayerB() { m_scorePlayerB++; }
	int GetScorePlayerB() { return m_scorePlayerB; }
};