#pragma once
#include"Body.h"
#include<vector>
#include "raylib.h"

struct Body;
class Scene;

using bodies_t = std::vector<Body*>;

class World
{
public:
	~World();

	void Initialize(Vector2 gravity = Vector2{ 0, -9.81f }, size_t poolSize = 30); //size_t prevents negative values for sizes of things

	Body* CreateBody(const Vector2& position, float size, const Color& color);
	Body* CreateBody(Body::Type type, const Vector2& position, float mass, float size, const Color& color);
	//Body* CreateBody2(Body::Type type, const Vector2& position, float size, const Color& color);
	//Body* World::CreateBody(const Vector2& position, float mass, float size, const Color& color);
	void Step(float dt); //step is very much like update //dt can also be called timestep
	void Draw(const Scene& scene);

	void DestroyAll();

	std::vector<Body*>& GetBodies() { return m_bodies; }
	
	//bodies_t& GetBodies() { return m_bodies; }


	// fixed? --> //this is supposed to be static so that it can be called from elsewhere, but it is not allowing this to be static
	inline static Vector2 m_gravity{ 0, -9.81f }; 
	inline static float gravitation = 0;
	inline static float springStiffnessMultiplier = 1.0f;
	inline static bool simulate = true;
public:
	//static Vector2 m_gravity; //this is supposed to be static so that it can be called from elsewhere, but it is not allowing this to be static
	float m_gravityScale{ 1 };
	float m_mass{ 1 };
	float m_damping{ 0 };

private:
	std::vector<Body*> m_bodies;

	//bodies_t m_bodies;
};