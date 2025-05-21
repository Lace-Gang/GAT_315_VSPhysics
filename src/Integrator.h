#pragma once
#include "Body.h"
#include<raymath.h>

//derivative of position is velocity. The derivative of velocity is acceleration
//So we need a deifferential equation to compute this with time
//Delta time can present a problem. this is why we use integrals. 
//We are trying to minimize how off track we get because of non-continuous time.


//Explicit Euler
inline void ExplicityIntegrator(Body& body, float timestep)
{
	body.position += (body.velocity) * timestep;
	body.velocity += (body.acceleration) * timestep;
	body.velocity *= 1.0f / (1.0f + (body.damping * timestep));
}


//Semi-Implicit Euler
inline void SemiImplicitIntegrator(Body& body, float timestep)
{
	body.velocity += (body.acceleration) * timestep;
	body.position += (body.velocity) * timestep;
} 