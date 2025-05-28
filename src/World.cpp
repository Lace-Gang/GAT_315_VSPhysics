#include "World.h"
#include "Body.h"
#include "Gravitation.h"
#include "Gui.h"


//Vector2 World::m_gravity{ 0, -9.81 };

void World::Initialize(Vector2 gravity, size_t poolSize)
{
    m_gravity = gravity;
    m_bodies.reserve(poolSize);
}


Body* World::CreateBody(const Vector2& position, float size, const Color& color)
{
    //Body* body = new Body(position, size, color);
    Body* body = new Body(position, m_mass, size, m_damping, color);
    //Body* body = new Body(position, m_mass, size, color);
    m_bodies.push_back(body);


    return body;
}

Body* World::CreateBody(Body::Type type, const Vector2& position, float mass, float size, const Color& color)
{
    //Body* body = new Body(type, position, m_mass, size, m_damping, color);
    Body* body = new Body(type, position, mass, size, color);
    m_bodies.push_back(body);


    return body;
}

//Body* World::CreateBody(const Vector2& position, float size, const Color& color)
//{
//    Body* body = new Body(position, m_mass, size, m_dampingcolor);
//    m_bodies.push_back(body);
//
//    return body;
//}


Spring* World::CreateSpring(Body* bodyA, Body* bodyB, float restLength, float stiffness)
{
    Spring* spring = new Spring(bodyA, bodyB, restLength, stiffness);
    m_springs.push_back(spring);

    return spring;
}

Spring* World::CreateSpring(Body* bodyA, Body* bodyB, float restLength, float stiffness, float damping)
{
    Spring* spring = new Spring(bodyA, bodyB, restLength, stiffness, damping);
    m_springs.push_back(spring);

    return spring;
}

void World::Step(float dt)
{
    if (!simulate) return;

    for (auto spring : m_springs)
    {
        //consider making the damping an interactable variable as well. But for now it's staying hardcoded.
        spring->ApplyForce(0.8f, springStiffnessMultiplier);
    }

    //is this supposed to be here? or somewhere else?
    if(gravitation != 0) ApplyGravitation(m_bodies, 0.15f); //we did "> 0" in class, but I like things pushing away :)


    for (auto body : m_bodies)
    {
        //body->velocity.y += (m_gravity.y * 0.003);
        //body->Step(dt, m_gravity, m_gravityScale);
        body->Step(dt, {0, GUI::GravitySliderValue}, GUI::GravityScaleSliderValue);


        //remove forces to start over on next frame
        body->ClearForce();
    }
}

void World::Draw(const Scene& scene)
{
    for (auto spring : m_springs)
    {
        spring->Draw(scene);
    }

    for (auto body : m_bodies)
    {
        body->Draw(scene);
    }
}

void World::DestroyAll()
{
    for (auto spring : m_springs)
    {
        delete spring;
    }
    for (auto body : m_bodies)
    {
        delete body;
    }
    //m_bodies.clear(); does not work because it does NOT deallocate/delet the items within. It only sets the size of the array to zero.
    //if we want the elements deleted, and memory freed, we have to do it ourselves.
}



