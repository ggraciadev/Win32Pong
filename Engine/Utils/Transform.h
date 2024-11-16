#pragma once
#include "Vector2D.h"

class Transform {
public:
	Transform();
	Transform(const Vector2D& position, const float rotation, const Vector2D& scale);

	~Transform();

protected:
	Vector2D m_position;	// The Vector2D that represents a position
	float m_rotation;	// The scalar that represents a rotation 
	Vector2D m_scale;	// The Vector2D that represents a scale

public:
/**
	* Returns the position of the Transform
	* @return The position of the Transform
*/
	inline Vector2D GetPosition() const { return m_position; }
/**
	* Returns the rotation of the Transform
	* @return The rotation of the Transform
*/
	inline float GetRotation() const { return m_rotation;  }
/**
	* Returns the scale of the Transform
	* @return The scale of the Transform
*/
	inline Vector2D GetScale() const { return m_scale;  }

/**
	* Sets the position of the Transform
	* @param The new position of the Transform
*/
	inline void SetPosition(const Vector2D& position) { m_position = position;  }
/**
	* Sets the rotation of the Transform
	* @param The new rotation of the Transform
*/
	inline void SetRotation(const float rotation) { m_rotation = rotation;  }
/**
	* Sets the scale of the Transform
	* @param The new scale of the Transform
*/
	inline void SetScale(const Vector2D& scale) { m_scale = scale; }



};