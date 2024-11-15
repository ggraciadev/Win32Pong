#pragma once
#include "Vector2D.h"

class Transform {
public:
	Transform();
	Transform(const Vector2D& position, const float rotation, const Vector2D& scale);

	~Transform();

protected:
	Vector2D pPosition;	// The Vector2D that represents a position
	float pRotation;	// The scalar that represents a rotation 
	Vector2D pScale;	// The Vector2D that represents a scale

public:
/**
	* Returns the position of the Transform
	* @return The position of the Transform
*/
	inline Vector2D GetPosition() const { return pPosition; }
/**
	* Returns the rotation of the Transform
	* @return The rotation of the Transform
*/
	inline float GetRotation() const { return pRotation;  }
/**
	* Returns the scale of the Transform
	* @return The scale of the Transform
*/
	inline Vector2D GetScale() const { return pScale;  }

/**
	* Sets the position of the Transform
	* @param The new position of the Transform
*/
	inline void SetPosition(const Vector2D& position) { pPosition = position;  }
/**
	* Sets the rotation of the Transform
	* @param The new rotation of the Transform
*/
	inline void SetRotation(const float rotation) { pRotation = rotation;  }
/**
	* Sets the scale of the Transform
	* @param The new scale of the Transform
*/
	inline void SetScale(const Vector2D& scale) { pScale = scale; }



};