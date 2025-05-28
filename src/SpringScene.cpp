#include "SpringScene.h"
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

void SpringScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
	m_world = new World();
	m_world->Initialize();


}

void SpringScene::Update()
{
	float dt = GetFrameTime();
	GUI::Update();

	//float theta = randomf(0, 360);

	if (IsKeyPressed(KEY_SPACE)) World::simulate = !World::simulate;

	//if (IsMouseButtonPressed(0) && !mouseOverGUI)
	if (!GUI::mouseOverGUI)
	{
		if ( IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Vector2 position = m_camera->ScreenToWorld(GetMousePosition());
			Color color = ColorFromHSV(randomf(360), 0.6, 1);
			Body::Type type = static_cast<Body::Type>(GUI::BodyTypeDropdownBoxActive); //see if this fixes it
			//Body::Type type = (Body::Type)GUI::BodyTypeDropdownBoxActive;

			float random = randomf();

		
			//float offset = randomf(0, 360);
			//float x = cos(theta * offset);
			//float y = sin(theta * offset);
			
			Body* body = m_world->CreateBody(type, position, GUI::BodyMassSliderValue, GUI::BodySizeSliderValue, color);
			//body->velocity = Vector2{ x, y } * randomf(1, 6);
			
			body->type = type;
			//Add these in when you can/if we decide we want them as changable
			body->restitution = GUI::BodyRestitutionSliderValue * -1;
			//body->gravityScale = GUI::GravityScaleSliderValue;
			

		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			Vector2 position = m_camera->ScreenToWorld(GetMousePosition());
			m_selectedBody = GUI::GetBodyIntersect(position, m_world->GetBodies(), *m_camera);
		}
		if (m_selectedBody)
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
			{
				Vector2 position = m_camera->ScreenToWorld(GetMousePosition());
				m_connectBody = GUI::GetBodyIntersect(position, m_world->GetBodies(), *m_camera);
			}
			else
			{
				if (m_selectedBody && m_connectBody)
				{
					float distance = Vector2Distance(m_selectedBody->position, m_connectBody->position);
					//m_world->CreateSpring(m_selectedBody, m_connectBody, distance, 15.0f);	
					m_world->CreateSpring(m_selectedBody, m_connectBody, distance, GUI::SpringStiffnessSliderValue, GUI::SpringDampingSliderValue);	
				}
				m_selectedBody = nullptr;
				m_connectBody = nullptr;
			}
		}
			
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

void SpringScene::FixedUpdate()
{
	//Apply gravitation was moved to world.cpp
	//ApplyGravitation(m_world->GetBodies(), 0.15f);
	//ApplyGravitation(m_world->GetBodies(), 15.0f);

	//applyfoces
	m_world->Step(Scene::fixedTimestep);

}

void SpringScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, DARKGRAY);
	m_world->Draw(*this);

	if (m_selectedBody)
	{
		DrawCircleLine(m_selectedBody->position, m_selectedBody->size, YELLOW, 5);
		if (m_connectBody)
		{
			DrawCircleLine(m_selectedBody->position, m_selectedBody->size, YELLOW, 5);
			DrawLine(m_selectedBody->position, m_connectBody->position, 3, GREEN);
		}
		else
		{
			DrawLine(m_selectedBody->position, m_camera->ScreenToWorld(GetMousePosition()), 3, RED);
		}
	}

	m_camera->EndMode();
}

void SpringScene::DrawGUI()
{
	GUI::Draw();
}
