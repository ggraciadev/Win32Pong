#include "Vector2D.h"

Vector2D::Vector2D() {
	m_x = m_y = 0;
}
Vector2D::Vector2D(float x, float y) {
	m_x = x;
	m_y = y;
}

void Vector2D::SetXY(float x, float y) {
	m_x = x;
	m_y = y;
}

float Vector2D::GetSize() const {
	return (float)std::sqrt(m_x * m_x + m_y * m_y);
}

Vector2D Vector2D::operator=(const Vector2D other) {
	if (&other != this) {
		m_x = other.m_x;
		m_y = other.m_y;
	}
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
	return Vector2D(m_x + other.m_x, m_y + other.m_y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
	return Vector2D(m_x - other.m_x, m_y - other.m_y);
}

Vector2D Vector2D::operator*(float other) const {
	return Vector2D(m_x * other, m_y * other);
}

Vector2D Vector2D::operator/(const float other) const {
	if (other == 0) { return Vector2D(); }
	else { return Vector2D(m_x / other, m_y / other); }
}

float Vector2D::Dist(const Vector2D& other) const {
	return ((other - (*this)).GetSize());
}

Vector2D Vector2D::GetNormal() const {
	if (GetSize() < 0.01f) return Vector2D(0, 0);
	else return ((*this) / GetSize());
}