#include "Transform.h"

Transform::Transform() {
	pPosition = Vector2D(0,0);
	pRotation = 0;
	pScale = Vector2D(1,1);
}

Transform::Transform(const Vector2D& position, const float rotation, const Vector2D& scale) {
	pPosition = position;
	pRotation = rotation;
	pScale = scale;
}

Transform::~Transform() {

}