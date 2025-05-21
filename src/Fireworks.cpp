#include "Fireworks.h"
#include "raymath.h"
#include "Body.h" //cpp files do not have cyclic reference issues
#include "World.h"
#include "MathUtils.h"



void FireworksScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
	m_world = new World();
	m_world->Initialize();

	//m_world->m_gravityScale = 0.3;
}

void FireworksScene::Update()
{
	float dt = GetFrameTime();

	float theta = randomf(0, 360);



	if (IsMouseButtonPressed(0))
	{
		Vector2 position = m_camera->ScreenToWorld(GetMousePosition());
		//Color color = ColorFromHSV(randomf(360), 1, 1);
		Color color = ColorFromHSV(randomf(360), 0.6f, 1);
		//Color color2 = ColorFromHSV(40, 1, 1);
		//Color color2 = ColorFromHSV(50, 350, 1);
		//Color color2 = ColorFromHSV(55, 0.4, 1);
		float random = randomf();

		if (random > 0.65)
		{
			for (int i = 0; i < 100; i++)
			{
				float offset = randomf(0, 360);
				float x = cosf(theta * offset);
				float y = sinf(theta * offset);

				Body* body = m_world->CreateBody(position, 0.04f, color);
				body->velocity = Vector2{ x, y } *randomf(1, 6);
			};
			for (int i = 0; i < 200; i++)
			{
				Color color2 = ColorFromHSV(randomf(50, 55), 0.4, 1);
				float offset = randomf(0, 360);
				float x = cosf(theta * offset);
				float y = sinf(theta * offset);

				Body* body = m_world->CreateBody(position, 0.02f, color2);
				body->velocity = Vector2{ x, y } *randomf(0.1, 5.5);
			};
		}
		else if (random > 0.35)
		{
			float vel = randomf(3, 7);
			float xTilt = randomf();
			float yTilt = randomf();
			for (int i = 0; i < 50; i++)
			{
				float offset = (360 / 50.0f) * i;
				float x = cosf(offset) * vel * xTilt;
				float y = sinf(offset) * vel * yTilt;

				Body* body = m_world->CreateBody(position, 0.04f, color);
				body->velocity = Vector2{ x, y };
			};
			for (int i = 0; i < 150; i++)
			{
				Color color2 = ColorFromHSV(randomf(50, 55), 0.4, 1);
				float offset = (360 / 150) * i;
				float x = cosf(offset) * vel * (xTilt + 0.05);
				float y = sinf(offset) * vel * (yTilt + 0.02);

				Body* body = m_world->CreateBody(position, 0.02f, color2);
				body->velocity = Vector2{ x, y } *randomf(0.1, 0.9);
			};
		}
		else
		{
			float AdditionalOffset = randomf(0, 360);
			for (int i = 0; i < 20; i++)
			{
				float offset = randomf(0, 270) / 360 + AdditionalOffset;
				float x = cos(offset);
				float y = sin(offset);

				Body* body = m_world->CreateBody(position, 0.05f, color);
				body->velocity = Vector2{ x, y } *randomf(5, 9);
			};
			for (int i = 0; i < 150; i++)
			{
				Color color2 = ColorFromHSV(randomf(50, 55), 0.4, 1);
				float offset = randomf(0, 290) / 360 + AdditionalOffset;
				float x = cos(offset);
				float y = sin(offset);

				Body* body = m_world->CreateBody(position, 0.02f, color2);
				body->velocity = Vector2{ x, y } *randomf(0.1, 8);
			};
		}


		//body->velocity = Vector2{ randomf(-4, 4), randomf(-4, 4) };


	}

	m_world->Step(dt);

}

void FireworksScene::FixedUpdate()
{
}

void FireworksScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, DARKGRAY);
	m_world->Draw(*this);



	m_camera->EndMode();
}

void FireworksScene::DrawGUI()
{
}






