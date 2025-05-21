#pragma once
#include "scene.h"
#include "raylib.h"

struct Body
//class Body
{
public:
	enum class Type
	{
		DYNAMIC,
		STATIC,
		KINEMATIC
	};

public:
	Body() = default;
	Body(const Vector2& position, const Vector2& velocity, float size, const Color& color) :
		position{ position },
		velocity{ velocity },
		size{ size },
		color{ color }
	{ }

	Body(const Vector2& position, float size, const Color& color) :
		position{ position },
		size{ size },
		color{ color }
	{
	}

	Body(const Vector2& position, float mass, float size, float damping, const Color& color) :
		position{ position },
		mass{ mass },
		size{ size },
		damping{damping},
		color{ color }
	{
		invMass = (mass != 0) ? 1 / mass : 0;
	}

	Body(Type type, const Vector2& position, float mass, float size, const Color& color) :
		type{ type },
		position{ position },
		mass{ mass },
		size{ size },
		color{ color }
	{
		invMass = (type == Type::DYNAMIC && mass !=0) ? 1 / mass : 0;
	}

	Body(Type type, const Vector2& position, float mass, float size, float damping, const Color& color) :
		type{ type },
		position{ position },
		mass{ mass },
		size{ size },
		damping{ damping },
		color{ color }
	{
		invMass = (type == Type::DYNAMIC && mass != 0) ? 1 / mass : 0;
	}

	void Step(float dt, const Vector2& grativy, float grSc);
	void Draw(const Scene&  scene);

	void ApplyForce(const Vector2& force);

	void ClearForce() { force = Vector2{ 0, 0 }; }

public:
	//my professor rarely uses m_ or _ for variables in a struct since they can feel weird to call
	Vector2 position{ 0, 0 };
	Vector2 velocity{ 0, 0 };
	Vector2 acceleration{ 0, 0 };
	Vector2 force{ 0, 0 }; 

	float mass{ 1 };
	float invMass{ 1 };

	float gravitScale{ 1 };
	float restitution{ -0.9f };

	float size = 1;
	float damping = 0.5f;		//0.3f;		//0.1f;
	Color color = WHITE;

	Type type = Type::DYNAMIC;

	Body* next = nullptr;
	Body* prev = nullptr;
};