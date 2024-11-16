#pragma once
#include "../../Engine/Managers/GameManager.h"

class MyGameManager : public GameManager {

public:
	friend class GameManager; // This has to be done in order to allow acces to the GameManager to the Constructor method

/**
Creates the instance of the Custom Scene Manager. Should be overrided in order to create a User Custom Scene Manager
*/
	virtual void CreateCustomSceneManager();
};