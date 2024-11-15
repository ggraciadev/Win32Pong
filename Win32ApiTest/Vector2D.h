#pragma once

#include <cmath>

class Vector2D {
protected:
	float px = 0;
	float py = 0;

public:
	Vector2D();
	Vector2D(float x, float y);

	inline float GetX() const { return px; }
	inline float GetY() const { return py; }

	inline void SetX(float x) { px = x; }
	inline void SetY(float y) { py = y; }
	void SetXY(float x, float y);

	inline float GetSize() const;

	Vector2D operator+(const Vector2D& other) const;

	Vector2D operator-(const Vector2D& other) const;

	Vector2D operator*(float other) const;

	Vector2D operator/(const float other) const;

	Vector2D operator=(const Vector2D other);

	float Dist(const Vector2D& other) const;

	Vector2D GetNormal() const;
};