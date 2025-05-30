#include "Spring.h"
#include "Body.h"
#include "raymath.h"
#include "Gui.h"

//kMultiplier is a value we can use to increase or decrease stiffness for the entire world as a whole without having to adjust each individual spring
void Spring::ApplyForce(float kMultiplier) 
{
	//direction = bodyA <-- bodyB 
	//Vector2 direction = bodyA->position = bodyB->position;
	Vector2 direction = bodyA->position - bodyB->position;
	float lengthSqr = Vector2LengthSqr(direction);
	if (lengthSqr <= EPSILON) return; //Because dividing by zero just might give us an error lol. So let's not do that.

	//calculare spring force
	float length = sqrtf(lengthSqr);
	float displacement = length - restLength;
	float forceMagnitude = -(k * kMultiplier) * displacement;

	Vector2 ndirection = direction / length; //normalized direction
	Vector2 force = ndirection * forceMagnitude;

	//damp spring force to prevent oscillation
	Vector2 dv = bodyA->velocity - bodyB->velocity;
	//float dampFactor = Vector2DotProduct(dv, ndirection) * m_damping; 
	float dampFactor = Vector2DotProduct(dv, ndirection) * GUI::SpringDampingSliderValue; 
	//movement perpendicular to direction of spring will be completely dampened
	//movement parallel to string will not be dampened at all (by this)
	//Other movement depends in exactly the way you would expect given the two lines above this one
	Vector2 dampingForce = ndirection * dampFactor;

	force -= dampingForce;

	//apply spring force
	bodyA->ApplyForce(force);
	bodyB->ApplyForce(Vector2Negate(force));
}

void Spring::ApplyForce(const Vector2& position, Body& body, float restLength, float k)
{
	//direction = bodyA <-- bodyB 
	//Vector2 direction = bodyA->position = bodyB->position;
	Vector2 direction = position - body.position;
	float lengthSqr = Vector2LengthSqr(direction);
	if (lengthSqr <= EPSILON) return; //Because dividing by zero just might give us an error lol. So let's not do that.

	//calculare spring force
	float length = sqrtf(lengthSqr);
	float displacement = length - restLength;
	float forceMagnitude = -(k) * displacement;

	Vector2 ndirection = direction / length; //normalized direction
	Vector2 force = ndirection * forceMagnitude;

	//apply spring force
	body.ApplyForce(Vector2Negate(force));
}

void Spring::ApplyForce(const Vector2& position, Body& body, float restlength, float k, float damping)
{
	//direction = position <-- bodyB
	//(position meaning the desired/ideal position that bodyB wants to be at)
	Vector2 direction = position - body.position;
	float lengthSqr = Vector2LengthSqr(direction);
	if (lengthSqr <= EPSILON) return;

	//Calculate spring force
	float length = sqrtf(lengthSqr);
	float displacement = length - restlength; //current length - resting length. >0 means stretched, < 0 means compressed
	float forceMagnitude = -k * displacement; //Hooke's Law (force = -spring constant * displacement)

	//damp spring force to prevent oscillation (also I think so that it doesn't just bounce forever)
	//damping is sort of like air resistance, but I think it includes other factors as well.
	Vector2 ndirection = direction / length;
	Vector2 force = ndirection * forceMagnitude;

	body.ApplyForce(force);
}


void Spring::ApplyForce(float damping, float kMultiplier)
{
	//direction = bodyA <-- bodyB 
	//Vector2 direction = bodyA->position = bodyB->position;
	Vector2 direction = bodyA->position - bodyB->position;
	float lengthSqr = Vector2LengthSqr(direction);
	if (lengthSqr <= EPSILON) return; //Because dividing by zero just might give us an error lol. So let's not do that.

	//calculare spring force
	float length = sqrtf(lengthSqr);
	float displacement = length - restLength;
	float forceMagnitude = -(k * kMultiplier) * displacement;

	Vector2 ndirection = direction / length; //normalized direction
	Vector2 force = ndirection * forceMagnitude;

	//damp spring force to prevent oscillation
	Vector2 dv = bodyA->velocity - bodyB->velocity;
	//float dampFactor = Vector2DotProduct(dv, ndirection) * damping;
	float dampFactor = Vector2DotProduct(dv, ndirection) * GUI::SpringDampingSliderValue;
	//movement perpendicular to direction of spring will be completely dampened
	//movement parallel to string will not be dampened at all (by this)
	//Other movement depends in exactly the way you would expect given the two lines above this one
	Vector2 dampingForce = ndirection * dampFactor;

	force -= dampingForce;

	//apply spring force
	bodyA->ApplyForce(force);
	bodyB->ApplyForce(Vector2Negate(force));
}

//void Spring::ApplyForce(const Vector2& position, Body& body, float restlength, float k, float damping)
//{
//	//direction = position <-- bodyB
//	//(position meaning the desired/ideal position that bodyB wants to be at)
//	Vector2 direction = position - body.position;
//	float lengthSqr = Vector2LengthSqr(direction);
//	if (lengthSqr <= EPSILON) return;
//
//	//Calculate spring force
//	float length = sqrtf(lengthSqr);
//	float displacement = length - restlength; //current length - resting length. >0 means stretched, < 0 means compressed
//	float forceMagnitude = -k * displacement; //Hooke's Law (force = -spring constant * displacement)
//
//	//damp spring force to prevent oscillation (also I think so that it doesn't just bounce forever)
//	//damping is sort of like air resistance, but I think it includes other factors as well.
//	Vector2 ndirection = direction / length;
//	Vector2 force = ndirection * forceMagnitude;
//
//	body.ApplyForce(force);
//}

//So that we can more or less vizualize the spring
void Spring::Draw(const Scene& scene)
{
	scene.DrawLine(bodyA->position, bodyB->position, 3, WHITE);
}
