#include "VectorScene.h"
#include "raymath.h"
#include "Body.h" //cpp files do not have cyclic reference issues
#include "MathUtils.h"
#include "raygui.h"
#include <iostream>
#include "World.h"
#include "Gravitation.h"
#include "Gui.h"

#define GUI_DATA(data) TextFormat("%0.2f", data), &data

void VectorScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
	m_world = new World();
	m_world->Initialize();

	
}

void VectorScene::Update()
{
	float dt = GetFrameTime();
	GUI::Update();

	float theta = randomf(0, 360);



	//if (IsMouseButtonPressed(0) && !mouseOverGUI)
	if (!GUI::mouseOverGUI && IsMouseButtonPressed(0))
	{
		Vector2 position = m_camera->ScreenToWorld(GetMousePosition());
		Color color = ColorFromHSV(randomf(360), 0.6, 1);
		Body::Type type = (Body::Type)GUI::BodyTypeDropdownBoxActive;

		float random = randomf();

		
			for (int i = 0; i < 100; i++)
			{
				float offset = randomf(0, 360);
				float x = cos(theta * offset);
				float y = sin(theta * offset);
				
				Body* body = m_world->CreateBody(position, GUI::m_bodySize, color);
				//Body* body = m_world->CreateBody(position, m_bodyMass, m_bodySize, color);
				body->velocity = Vector2{ x, y } * randomf(1, 6);
				//body->gravitScale = GravityScaleSliderValue;
				//body->damping = BodyDampintSliderValue;
				body->type = type;
			};
			//for (int i = 0; i < 200; i++)
			//{
			//	Color color2 = ColorFromHSV(randomf(50, 55), 0.4, 1);
			//	float offset = randomf(0, 360);
			//	float x = cos(theta * offset);
			//	float y = sin(theta * offset);
			//
			//	Body* body = m_world->CreateBody(position, m_bodySize, color2);
			//	body->velocity = Vector2{ x, y } *randomf(0.1, 5.5);
			//};
	}



	//apply collision
	for (auto body : m_world->GetBodies())
	{
		if (body->position.y < -5)
		{
			body->position.y = -5;
			//body->velocity.y *= -1;
			body->velocity.y *= body->restitution; //for restitution
		}
		if (body->position.x < -9)
		{
			body->position.x = -9;
			body->velocity.x *= -1;
		}
		if (body->position.x > 9)
		{
			body->position.x = 9;
			body->velocity.x *= -1;
		}
	}
}

void VectorScene::FixedUpdate()
{
	//Apply gravitation was moved to world.cpp
	//ApplyGravitation(m_world->GetBodies(), 0.15f);
	//ApplyGravitation(m_world->GetBodies(), 15.0f);

	//applyfoces
	m_world->Step(Scene::fixedTimestep);

}

void VectorScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, DARKGRAY);
	m_world->Draw(*this);



	m_camera->EndMode();
}

void VectorScene::DrawGUI()
{
	GUI::Draw();
}





//To implement a "player" and things chasing that player:
//Add this to innitialize:

	//Body* body = new Body(Vector2{ 3, 0 }, Vector2{ 0 }, 0.25, WHITE);
	//m_head = body;
	//m_player = body;
	//
	//for (int i = 0; i < 100; i++)
	//{
	//	body->next = new Body(Vector2{ randomf() * 10 - 5, (randomf() * 10) - 5}, Vector2{1, 0}, 0.25, RED);
	//	body->next->prev = body;
	//	body = body->next;
	//}


//Add this to Update:

	////player control
	//Vector2 input{ 0, 0 };
	//if (IsKeyDown(KEY_A)) input.x = -1;
	//if (IsKeyDown(KEY_D)) input.x = 1;
	//if (IsKeyDown(KEY_W)) input.y = 1;
	//if (IsKeyDown(KEY_S)) input.y = -1;
	//input = Vector2Normalize(input) * 2;
	//
	//m_player->velocity = input;
	//
	//
	//Body* body = m_head;
	//while (body) //while not a null pointer
	//{
	//	if (body == m_player)
	//	{
	//		body->Step(dt);
	//		body = body->next;
	//		continue;
	//	}
	//
	//	Vector2 direction = m_player->position - body->position;
	//	direction = Vector2Normalize(direction) * 1;
	//	body->velocity = direction;
	//
	//	body->Step(dt);
	//	body = body->next;
	//}


//And add this to Draw:

	//Body* body = m_head;
	//while (body) //while not a null pointer
	//{
	//	body->Draw(*this);
	//	body = body->next;
	//}
