#pragma once

#include "Bitmap.h"
#include "Transform.h"
#include <vector>
#include <d2d1.h>

class ActorComponent;

class Actor
{

public:
    Actor();
    virtual ~Actor();

protected:
    Transform pTransform;
    std::vector<ActorComponent*> pActorComponents;
    ID2D1HwndRenderTarget* pRenderTarget = NULL;

    virtual void EndPlay();
    virtual void AddActorComponent(ActorComponent* actorComponent);

public:
    virtual void BeginPlay();
    virtual void Init();
    virtual void Init(const Transform& transform, ID2D1HwndRenderTarget* renderTarget);
    virtual void Tick(float deltaTime);

    Transform* GetTransform() { return &pTransform; }
    void SetTransform(const Transform& transform);
    virtual void Draw();
};