#include "Body.h"
#include "World.h"
#include "Integrator.h"
#include "raymath.h" //allows things such as += on vectors

void Body::Step(float dt, const Vector2& grativy, float grSc)
{
	if (type != Type::DYNAMIC) return;

	//apply gravity
	//force += (World::m_gravity * gravitScale) * mass;
	force += (grativy * grSc) * mass;
	//velocity += World::m_gravity * dt;

	//compute acceleration
	acceleration = force * invMass; //to prevent potential division by 0

	//if f = ma, then a = f/m :)
	//acceleration = (force / mass);

	SemiImplicitIntegrator(*this, dt);
	
	//"naive way" of implementing dampening (according to professor):
	//velocity *= 0.99f;

	//better way :)
	velocity *= 1.0f/(1.0f + (damping * dt)); 

}

void Body::Draw(const Scene& scene)
{
	scene.DrawCircle(position, size, color);
}

void Body::ApplyForce(const Vector2& force)
{
	this->force += force; 
}
