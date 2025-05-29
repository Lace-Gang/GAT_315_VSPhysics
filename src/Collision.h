#pragma once
#include "World.h"


class Collision
{
public:
	static void CreateContacts(const bodies_t& bodies, contacts_t& contacts);
	static void SeparateContacts(contacts_t& contacts);

	static bool Intersects(Body* bodyA, Body* bodyB);
};