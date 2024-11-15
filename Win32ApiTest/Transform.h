#pragma once
#include "Vector2D.h"

class Transform {
public:
	Transform();
	Transform(const Vector2D& position, const float rotation, const Vector2D& scale);

	~Transform();

protected:
	Vector2D pPosition;
	float pRotation;
	Vector2D pScale;

public:
	inline Vector2D GetPosition() const { return pPosition; }
	inline float GetRotation() const { return pRotation;  }
	inline Vector2D GetScale() const { return pScale;  }

	inline void SetPosition(const Vector2D& position) { pPosition = position;  }
	inline void SetRotation(const float rotation) { pRotation = rotation;  }
	inline void SetScale(const Vector2D& scale) { pScale = scale; }



};