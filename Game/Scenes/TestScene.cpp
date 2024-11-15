#include "TestScene.h"
#include "../Actors/MyEllipseActor.h"

TestScene::TestScene() {
	MyEllipseActor* ellipse = new MyEllipseActor();
	ellipse->SetTransform(Transform(Vector2D(0, 0), 0, Vector2D(1, 1)));
	AddActorToScene(ellipse);
}
TestScene::~TestScene() {

}