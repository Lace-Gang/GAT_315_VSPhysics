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


void World::Step(float dt)
{
    if (!simulate) return;

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
    for (auto body : m_bodies)
    {
        body->Draw(scene);
    }
}

void World::DestroyAll()
{
    for (auto body : m_bodies)
    {
        delete body;
    }
    //m_bodies.clear(); does not work because it does NOT deallocate/delet the items within. It only sets the size of the array to zero.
    //if we want the elements deleted, and memory freed, we have to do it ourselves.
}



