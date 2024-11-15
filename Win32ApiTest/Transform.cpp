#include "Transform.h"

Transform::Transform() {
	pPosition = Vector2D();
	pRotation = 0;
	pScale = Vector2D();
}

Transform::Transform(const Vector2D& position, const float rotation, const Vector2D& scale) {
	pPosition = position;
	pRotation = rotation;
	pScale = scale;
}

Transform::~Transform() {

}