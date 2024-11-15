#pragma once
#include "Transform.h"
#include <d2d1.h>

class Actor;

class ActorComponent
{

public:
	ActorComponent();
	virtual ~ActorComponent();

protected:
	Actor*			pActor = NULL;
	Transform		pTransform; 
	bool			pIsDrawable = false;
	bool			pCanEverTick = false;

	virtual void EndPlay() {};

public:
	virtual void Init(Actor* actor);
	virtual void Init(Actor* actor, const Transform& transform, ID2D1HwndRenderTarget* renderTarget);

	virtual void SafeDraw(ID2D1HwndRenderTarget* renderTarget);

	virtual void BeginPlay() {};
	virtual void SafeTick(float deltaTime);
	virtual void Tick(float deltaTime) {};
	virtual void Draw(ID2D1HwndRenderTarget* renderTarget) {};

	Transform GetTransform() const { return pTransform; }
	void SetComponentPosition(Vector2D position);
	void SetComponentRotation(float rotation);
	void SetComponentScale(Vector2D scale);
};