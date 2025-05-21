#include "TrigonometryScene.h"

void TrigonometryScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{m_width /2.0f, m_height /2.0f});
}

void TrigonometryScene::Update()
{
}

void TrigonometryScene::FixedUpdate()
{
}

float DegToRad(float degrees)
{
	return degrees * (PI / 180);
}

float RadToDeg(float radians)
{
	return radians * (180 / PI);
}


//was commented out because it's already in the raylib library <-- but that's not included here, so uncommenting it
//Get length of a vector
//length(square root) of x^2 + y^2
float Vector2Length(const Vector2& v) //passing references and consts again :D
{
	return sqrt((v.x * v.x) + (v.y * v.y));
}

//get normalized vector (such as would be needed in calculating direction)
Vector2 Vector2Normalize(const Vector2& v)
{
	float l = Vector2Length(v);
	if (l == 0) return { 0 }; //remember short hand to assign a vector that has all the same value
	return Vector2{ v.x / l, v.y / l };
}

//Get angle of a vactor (in radians)
float Vector2Angle(const Vector2& v)
{
	return atan2(v.y, v.x);
}

void TrigonometryScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, WHITE);
	//DrawCircle(0, 0, 50, RED);
	//DrawCircle((Vector2{ 0, 0 }), (1), RED);
	//DrawCircleV(m_camera->WorldToScreen(Vector2{ 0, 0 }), m_camera->WorldToScreen(1), RED);
	//100 pixels per unit, so a 1 diameter in world, is 200 pixels in screen?


	//Drawing something together!
	float radius = 3;
	float rate = 0.2f;
	float time = (float) GetTime() * rate;
	
	float radians = 180 * DEG2RAD;
	//circle
	int steps = 50;
	for (int i = 0; i < steps; i++)
	{
		//normalization: divide value by max value
		float theta = i / (steps * 1.0f) * (2 * PI); //0 to 1 
		//(forgetting the float thing will cause issues with integer division, and nothing will be visible)
		// * 2pi converts from radians to degrees
		float x = cos(theta) * radius; //gives us x coordinate
		//float x = cos(theta) * radius * 0.5f; //Would cause an elipse
		float y = sin(theta) * radius; //gives us y coordinate

		DrawCircle(Vector2{ x, y }, 0.25f, RED);
	}

	// sin / cos
	for (float x = -9.0f; x < 9; x += 0.2)
	{
		float theta = time + (x / 18) * (2 * PI); 
		float c = cos(theta) * radius;
		float s = sin(theta) * radius;

		DrawCircle(Vector2{ x, c }, 0.25f, GREEN);
		DrawCircle(Vector2{ x, s }, 0.25f, BLUE);

	}
	//things like this could be used to find the path of a projectile


	float theta = time;
	float x = cos(theta) * radius;
	float y = sin(theta) * radius;

	DrawCircle(Vector2{ x, y }, 0.25f, YELLOW);

	//sin of angle = opposite / hypoteneus
	//arcsin = hypoteneus / opposite = angle 
	//arc tangent of (y, x) = angle
	float angle = atan2(y, x); //(angle (in radians?))

	m_camera->EndMode();
}

void TrigonometryScene::DrawGUI()
{
}
