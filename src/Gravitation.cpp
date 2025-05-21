#include "Gravitation.h"
#include "Body.h"
#include "raymath.h"
#include<math.h>
#include<algorithm>

void ApplyGravitation(bodies_t& bodies, float strength)
{
	for (int i = 0; i < bodies.size(); i++)
	{
		Body* bodyA = bodies[i];
		for (int j = i + 1; j < bodies.size(); j++)
		{
			Body* bodyB = bodies[j];

            // STEP 1: Find the direction vector from bodyB to bodyA
            // Vector2 direction = bodyA position - bodyB position;
            //Vector2 direction = Vector2Add(bodyA->position, Vector2Negate(bodyB->position));
            Vector2 direction;
            direction.x = bodyA->position.x - bodyB->position.x;
            direction.y = bodyA->position.y - bodyB->position.y;

            // STEP 2: Get the distance between the two bodies
            // float distance = length of direction vector;
            float distance = Vector2Length(direction);
                //sqrtf((distance.x * distance.x) + (distance.y * distance.y));

            // STEP 3: Clamp the distance to a minimum value to avoid extreme forces
            // distance = max(distance, 1);
            //distance = fmaxf(distance, 1);
            //distance = std::clamp(distance, 1);
            distance = (distance >= 1) ? distance : 1;

            // STEP 4: Calculate gravitational force magnitude using:
            // forceMagnitude = (bodyA mass * bodyB mass / (distance * distance)) * strength;
            float forceMagnitude = ((bodyA->mass * bodyB->mass) / (distance * distance)) * strength;

            // STEP 5: Normalize the direction vector and scale it by the force magnitude
            // Vector2 forceVector = normalized direction * forceMagnitude;
            //Vector2 forceVector;// = new Vector2((direction.x / distance), (direction.y / distance))
            //forceVector.x = (direction.x / distance);
            Vector2 forceVector = Vector2Normalize(direction) * forceMagnitude;
            //forceVector.y = (direction.y / distance);
            //forceVector *= forceMagnitude;

            // STEP 6: Apply the force to both bodies (equal and opposite)
            // bodyA.ApplyForce(-forceVector);
            //bodyB->ApplyForce(forceVector);
            //bodyA->ApplyForce((forceVector));
            bodyA->ApplyForce(Vector2Negate(forceVector));
            //bodyB->ApplyForce(Vector2Invert(forceVector));
            //bodyB->ApplyForce((forceVector));
		}
	}
}
