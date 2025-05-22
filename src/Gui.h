#pragma once
#include "World.h"
#include<raylib.h>
#include "scene_camera.h"

class GUI
{
public:
	static void Update();
	static void Draw();

	static struct Body* GetBodyIntersect(const Vector2& position, bodies_t& bodies, const SceneCamera& camera);

public:
	inline static bool mouseOverGUI = false;
	 
	inline static Vector2 anchor01 = { 48, 56 };
	//inline static Vector2 anchor02 = { 112, 104 };

	inline static bool PhysicsWindowBoxActive = true;
	 
	inline static float GravitySliderValue = -9.81f;
	inline static float GravityScaleSliderValue = 1.0f;
	inline static float BodyMassSliderValue = 1.0f;
	inline static float BodySizeSliderValue = 0.2f;
	inline static float BodyDampintSliderValue = 0.0f;
	inline static bool BodyTypeDropdownBoxEditMode = false;
	inline static int BodyTypeDropdownBoxActive = 0;
	 
	 
	inline static float m_bodyMass{ 1 };
	inline static float m_bodySize{ 0.2f };

	//Body::Type m_type = Body::Type::Dynamic;
};