#pragma once
#include "ActorComponent.h"
#include <d2d1.h>

class DrawableShapeComponent : public ActorComponent
{
public:
	DrawableShapeComponent();
	virtual ~DrawableShapeComponent();


protected:
	D2D1_COLOR_F			pColor = D2D1::ColorF(0.8f, 0.8f, 0.8f);	// Color of the DrawableShape
	ID2D1SolidColorBrush*	pBrush = NULL;								// Solid Color Brush of the DrawableShape

public:
/**
 * Initalize the DrawableShapeComponent with the reference of its owner and a inital transform
 *
 * Default Transform is at Position(0,0), Rotation(0) and Scale(1,1)
 *
 * @param actor:  a reference to the owner Actor.
 * @param transform(optional): the position, rotation and scale relative to the relative actor this ActorComponent should start with
 */
	virtual void Init(Actor* actor);

/**
 * Initalize the DrawableShapeComponent with the reference of its owner and a inital transform
 *
 * Default Transform is at Position(0,0), Rotation(0) and Scale(1,1)
 *
 * @param actor:  a reference to the owner Actor.
 * @param transform: the position, rotation and scale relative to the relative actor this ActorComponent should start with
 * @param color: the initial color of the DrawableShape
 */
	virtual void Init(Actor* actor, D2D1_COLOR_F color);

	D2D1_COLOR_F GetColor() const { return pColor; }
	void SetColor(D2D1_COLOR_F color);

/**
This event is called when the game starts or when the owner Actor is spawned
*/
	virtual void BeginPlay();

/**
This event is for the logic of the component, the behaviour that has to be updated frame by frame if needed.
*/
	virtual void EndPlay();
/**
This event is for the rendering of the component if needed. This method should be overrided by every ActorComponent that uses it
*/
	virtual void Draw(ID2D1HwndRenderTarget* renderTarget);

/**
This method is called just before Draw to update every shape positions. This method should be overrided by every DrawableShapeComponent
*/
	virtual void UpdateShape() {}

};