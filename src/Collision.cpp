#include "Collision.h"
#include "Body.h"
#include "MathUtils.h"
#include "World.h"
#include <raymath.h>
#include "Contact.h"

void Collision::CreateContacts(const bodies_t& bodies, contacts_t& contacts)
{
	for (int i = 0; i < bodies.size(); i++)
	{
		Body* bodyA = bodies[i];
		for (int j = i + 1; j < bodies.size(); j++)
		{
			Body* bodyB = bodies[j];
			if (bodyA->type != Body::Type::DYNAMIC && bodyB->type != Body::Type::DYNAMIC) continue;

			if (Intersects(bodyA, bodyB))
			{
				Contact contact;
				contact.bodyA = bodyA;
				contact.bodyB = bodyB;

				//Vector2 direction = <direction vector from bodyB to bodyA>;
				//Vector2 direction = Vector2Subtract(bodyB->position, bodyA->position); /////////////////////
				Vector2 direction = Vector2Subtract(bodyA->position, bodyB->position); /////////////////////
				//float distanceSqr = <get Vector2 Length Squared of direction>;
				float distanceSqr = Vector2LengthSqr(direction);
				if (distanceSqr <= EPSILON)
				{
					direction = Vector2{ randomf(-0.05f, 0.05f), randomf(-0.05f, 0.05f) };
					distanceSqr = Vector2LengthSqr(direction);
				}

				//float distance = <get distance from squared distance>;
				float distance = distanceSqr;
				//float radius = <add size of bodyA and bodyB>;
				float radius = bodyA->size + bodyB->size;
				//contact.depth = <calculate penetration depth, see note above>;
				contact.depth = (bodyA->size + bodyB->size) - distance;
				//contact.normal = <normalize direction, can use normalize function or direction / distance>;
				contact.normal = Vector2Normalize(direction);
				//contact.restitution = <get average restitution of both bodies>;
				contact.restitution = (bodyA->restitution + bodyB->restitution) / 2;

				contacts.push_back(contact);
			}
		}
	}
}

void Collision::SeparateContacts(contacts_t& contacts)
{
	for (auto contact : contacts)
	{
		//float totalInverseMass = <add inverse mass of both contact bodies>;
		float totalInverseMass = contact.bodyA->invMass + contact.bodyB->invMass;
		Vector2 separation = contact.normal * (contact.depth / totalInverseMass);
		//contact.bodyA->position = <contact bodyA position + (separation * contact bodyA inverse mass)>;
		contact.bodyA->position = contact.bodyA->position + (separation * contact.bodyA->invMass);
		contact.bodyB->position = contact.bodyB->position - (separation * contact.bodyB->invMass);
	}
}

bool Collision::Intersects(Body* bodyA, Body* bodyB)
{
	//float distance = <get distance between bodyA and bodyB, use Vector2Distance>;
	float distance = Vector2Distance(bodyA->position, bodyB->position);
	//float radius = <add size of bodyA and BodyB>;
	float radius = bodyA->size + bodyB->size;

	return (distance <= radius);
}


