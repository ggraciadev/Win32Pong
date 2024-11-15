#include "../../Engine/Managers/GameManager.h"

class MyGameManager : public GameManager {

protected:
	MyGameManager();

public:
	friend class GameManager;
	virtual void InitScene();
};