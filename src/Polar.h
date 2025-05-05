#pragma once

//#include "raylib.h"
//#include "scene.h"
//#include "TrigonometryScene.cpp"


struct Polar
{
public:
	Polar() = default;
	Polar(float angle, float radius) :
		angle{ angle },
		radius{ radius }
	{}

	Polar(const Vector2& v) :
		//angle{ !!get angle from Vector2 !!},
		//angle{ Vector2Angle(v)},
		angle{ (float) atan2(v.y, v.x) },
		//radius{ !!get vector length !!}
		//radius{ Vector2Length(v)}
		radius{ (float) sqrt((v.x * v.x) + (v.y * v.y)) }
	{}

	Polar& operator = (const Vector2& v)
	{
		//angle = !!get angle from Vector2 !!;
		//angle = Vector2Angle(v);
		angle = atan2(v.y, v.x);
		//radius = !!get vector length !!;
		//radius = Vector2Length(v);
		radius = sqrt((v.x * v.x) + (v.y * v.y));

		return *this;
	}

	operator Vector2() const
	{
		Vector2 v;
		//v.x = !!get x position using cos(angle)* radius !!;
		v.x = cos(angle) * radius;
		//v.y = !!get y position using sin(angle)* radius !!;
		v.y = sin(angle) * radius;

		return v;
	}

public:
	float angle{ 0 };
	float radius{ 0 };
};