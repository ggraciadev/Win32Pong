#include "Vector2D.h"

Vector2D::Vector2D() {
	px = py = 0;
}
Vector2D::Vector2D(float x, float y) {
	px = x;
	py = y;
}

void Vector2D::SetXY(float x, float y) {
	px = x;
	py = y;
}

float Vector2D::GetSize() const {
	return (float)std::sqrt(px * px + py + py);
}

Vector2D Vector2D::operator=(const Vector2D other) {
	if (&other != this) {
		px = other.px;
		py = other.py;
	}
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
	return Vector2D(px + other.px, py + other.py);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
	return Vector2D(px + other.px, py + other.py);
}

Vector2D Vector2D::operator*(float other) const {
	return Vector2D(px * other, py * other);
}

Vector2D Vector2D::operator/(const float other) const {
	if (other == 0) { return Vector2D(); }
	else { return Vector2D(px / other, py / other); }
}

float Vector2D::Dist(const Vector2D& other) const {
	return ((other - (*this)).GetSize());
}

Vector2D Vector2D::GetNormal() const {
	return ((*this) / GetSize());
}