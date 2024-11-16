#pragma once
#include "../../Engine/Objects/Scene.h"

class TestScene : public Scene{

protected:
/**
This event is called to initialize a Scene. Override this method to add all the Actors to the scene and then call Scene::Init()
*/
    virtual void Init();

};