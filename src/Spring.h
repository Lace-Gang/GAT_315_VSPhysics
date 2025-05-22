#pragma once
#include "scene.h"
#include "raylib.h"

struct Spring
{
public:
	struct Body* bodyA;
	struct Body* bodyB;
	float restLength;
	float k; //stiffness of the spring (aka spring constant)

public:
	Spring() = default;
	Spring(Body* bodyA, Body* bodyB, float restLength, float k) :
		restLength{ restLength },
		bodyA{ bodyA },
		bodyB{ bodyB },
		k{ k }
	{}
	void ApplyForce(float damping = 0.5f, float kMultiplier = 1);
	static void ApplyForce(const Vector2& position, struct Body& body, float restlength, float k, float damping);

	void Draw(const Scene& scene);
};