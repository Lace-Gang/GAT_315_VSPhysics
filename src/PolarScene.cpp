#include "PolarScene.h"
#include "Polar.h"

void PolarScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
}

void PolarScene::Update()
{
}

void PolarScene::Draw()
{
	m_camera->BeginMode();

	//DrawSpiral(0.01f, 2.0f);
	//DrawSpiral(0.01f, 0.5f);
	//DrawCardioid(3.0f);
	//DrawLimacon(2, 5);
	//DrawRoseCurve(5, 20);
	DrawUserSpiral(4, 7, 2);
	


	m_camera->EndMode();
}

void PolarScene::DrawGUI()
{
}

void PolarScene::DrawSpiral(float startRadius, float spacing)
{
	Polar p1 = Polar(0, startRadius );
	Polar p2;

	for (float theta = 0.0f; theta < 12.0f; theta += 0.01)
	{
		float r = startRadius + (spacing * theta);
		p2 = Polar(theta, r);
		DrawLine(p1, p2, 2.0f, RED);
		p1 = p2;
	}
}

//float PolarScene::Cardioid(float size, float angle)
void PolarScene::DrawCardioid(float size)
{
	Polar p1 = Polar(0, size * (1 + (cos(0))));
	Polar p2;
	for (float theta = (-2 * PI); theta < (2 * PI); theta += 0.01)
	{
		float r = size * (1 + (cos(theta)));
		Polar p2 = Polar(theta, r);
		DrawLine(p2, p1, 2.0f, BLUE);
		p1 = p2;
	}
}

//float PolarScene::Limacon(float loop, float dimple, float angle)
void PolarScene::DrawLimacon(float loop, float dimple)
{
	Polar p1 = Polar(0, loop + (dimple * cos(0)));
	Polar p2;

	for (float theta = (-2 * PI); theta < (2 * PI); theta += 0.01)
	{
		float r = loop + (dimple * cos(theta));
		//float r = 0 + ((loop / dimple) * cos(theta));
		p2 = Polar(theta, r);
		DrawLine(p1, p2, 2.0f, GREEN);
		p1 = p2;
	}
}

//float PolarScene::RoseCurve(float size, int petals, float angle)
void PolarScene::DrawRoseCurve(float size, int petals)
{
	Polar p1 = Polar(0, 0);
	Polar p2;

	for (float theta = (-2 * PI); theta < (2 * PI); theta += 0.01)
	{
		float r = size * (sin(petals * theta));
		p2 = Polar(theta, r);
		DrawLine(p1, p2, 2.0f, PINK);
		p1 = p2;
	}
}


void PolarScene::DrawUserSpiral(float size, int petals, float difference)
{
	Polar p1 = Polar(0, 0);
	Polar p2;
	Polar p3 = Polar(0, 0);
	Polar p4;

	for (float theta = (-2 * PI); theta < (2 * PI); theta += 0.01)
	{
		float r = (size * 0.25) + size * (sin(petals * theta));
		p2 = Polar(theta, r);
		p4 = Polar(theta + 0.6, r + difference);
		DrawLine(p1, p2, 2.0f, PINK);
		DrawLine(p3, p4, 2.0f, ORANGE);
		p1 = p2;
		p3 = p4;
	}
}
