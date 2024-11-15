#pragma once

#include <cmath>

class Vector2D {
protected:
	float px = 0;	// X component of the Vector
	float py = 0;	// Y component of the Vector

public:
	Vector2D();
	Vector2D(float x, float y);

/**
 * Returns the value of X of the Vector2D
 * @return px: the X value of the Vector2D
*/
	inline float GetX() const { return px; }

/**
 * Returns the value of Y of the Vector2D
 * @return The Y value of the Vector2D
*/
	inline float GetY() const { return py; }

/**
	* Sets the value of X of the Vector2D
	* @param x: The new X value of the Vector2D
*/
	inline void SetX(float x) { px = x; }

/**
	* Sets the value of Y of the Vector2D
	* @param y: The new Y value of the Vector2D
*/
	inline void SetY(float y) { py = y; }
	void SetXY(float x, float y);

/**
	* Returns the size (module) of the vector
	* @return The size (module) of the vector
*/
	inline float GetSize() const;

/**
	* Override of the Add operator with other Vector2D
	* @param other: The Vector2D to add
	* @return A Vector2D that represents the sum of two Vector2D like (a.x + b.x, a.y + b.y)
*/
	Vector2D operator+(const Vector2D& other) const;

/**
	* Override of the Substract operator with other Vector2D
	* @param other: The Vector2D to substract
	* @return A Vector2D that represents the rest of two Vector2D like (a.x - b.x, a.y - b.y)
*/
	Vector2D operator-(const Vector2D& other) const;

/**
	* Override of the Multiplication operator with an scalar (float)
	* @param other: The scalar to multiply
	* @return A Vector2D that represents the mult of a Vector2D and a Scalar like (a.x * b, a.y * b)
*/
	Vector2D operator*(float other) const;

/**
	* Override of the Division operator with an scalar (float)
	* @param: The scalar to divide
	* @return A Vector2D that represents the division of a Vector2D and a Scalar like (a.x / b, a.y / b)
*/
	Vector2D operator/(const float other) const;

/**
	* Override of the Equal operator with another Vector2D
	* @param: The scalar to equal
	* @return Modifies the values of this vector and returns it's value
*/
	Vector2D operator=(const Vector2D other);

/**
	* Returns the distance between two points
	* @param: The other point to check distance with
	* @return The distance between two points (Vector2D)
*/
	float Dist(const Vector2D& other) const;

/**
	* Returns the Unitary Vector2D with the same direction of this Vector2D
	* @return The Unitary Vector2D with the same direction of this Vector2D
*/
	Vector2D GetNormal() const;
};