#include "Transform.h"

Transform::Transform() {
	m_position = Vector2D(0,0);
	m_rotation = 0;
	m_scale = Vector2D(1,1);
}

Transform::Transform(const Vector2D& position, const float rotation, const Vector2D& scale) {
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
}

Transform::~Transform() {

}