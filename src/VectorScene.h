#pragma once

#include "scene.h"


class Body; //avoid cyclical references (fine as long as the include is in the cpp)
class VectorScene : public Scene //calling Scene public allows it to be seen from here
{
public:
	VectorScene(const std::string& title, int width, int height, const Color& background = BLACK) :
		Scene(title, width, height, background)
	{

	}


	// Inherited via Scene
	void Initialize() override;

	void Update() override;

	void FixedUpdate() override;


	void Draw() override;

	void DrawGUI() override;



private:
	//Body* m_head = nullptr;
	//Body* m_player = nullptr;

	//bool mouseOverGUI = false;
	//
	//Vector2 anchor01 = { 48, 56 };

	//bool PhysicsWindowBoxActive = true;
	//float GravitySliderValue = 1.0f;
	//float GravityScaleSliderValue = 1.0f;
	//float BodyMassSliderValue = 1.0f;
	//float BodySizeSliderValue = 0.2f;
	//float BodyDampintSliderValue = 0.0f;
	//bool BodyTypeDropdownBoxEditMode = false;
	//int BodyTypeDropdownBoxActive = 0;
	//
	//
	//float m_bodyMass{ 1 };
	//float m_bodySize{ 0.2f };
	//
	////Body::Type m_type = Body::Type::Dynamic;
};