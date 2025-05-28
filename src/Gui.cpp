#include"Gui.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include<iostream>
#include <string>

#define GUI_DATA(data) TextFormat("%0.2f", data), &data


void GUI::Update()
{
	if (IsKeyPressed(KEY_TAB)) PhysicsWindowBoxActive = !PhysicsWindowBoxActive;

}

void GUI::Draw()
{
	///if (PhysicsWindowBoxActive)
	//{
	//	PhysicsWindowBoxActive = !GuiWindowBox(Rectangle { anchor01.x + 0, anchor01.y + 0, 272, 512 }, "SAMPLE TEXT");
	//	//GuiSlider(Rectangle { anchor01.x + 64, anchor01.y + 48, 120, 16 }, "Gravity", NULL, &World::m_gravity.y, -20, 20);
	//	GuiSlider(Rectangle { anchor01.x + 64, anchor01.y + 48, 120, 16 }, "Gravity", NULL, &m_world->m_gravity.y, -20, 20);
	//}

	mouseOverGUI = PhysicsWindowBoxActive && CheckCollisionPointRec(GetMousePosition(), { anchor01.x + 0, anchor01.y + 0, 272, 512 });

	if (BodyTypeDropdownBoxEditMode) GuiLock();

	if (PhysicsWindowBoxActive)
	{

		PhysicsWindowBoxActive = !GuiWindowBox(Rectangle { anchor01.x + 0, anchor01.y + 0, 272, 512 }, "SAMPLE TEXT");
		GuiGroupBox(Rectangle{ anchor01.x + 15, anchor01.y + 40, 240, 150 }, "Body");
		GuiSliderBar(Rectangle { anchor01.x + 96, anchor01.y + 50, 120, 16 }, "Body Mass", GUI_DATA(BodyMassSliderValue), 0, 10);
		GuiSliderBar(Rectangle { anchor01.x + 96, anchor01.y + 70, 120, 16 }, "Body Size", GUI_DATA(BodySizeSliderValue), 0.01, 1);
		GuiSliderBar(Rectangle { anchor01.x + 96, anchor01.y + 90, 120, 16 }, "Gravity Scale", GUI_DATA(GravityScaleSliderValue), 0, 20);
		GuiSliderBar(Rectangle { anchor01.x + 96, anchor01.y + 110, 120, 16 }, "Body Damping", GUI_DATA(BodyDampingSliderValue), 0, 1);
		GuiSliderBar(Rectangle { anchor01.x + 96, anchor01.y + 130, 120, 16 }, "Restitution", GUI_DATA(BodyRestitutionSliderValue), 0, 1);

		GuiGroupBox(Rectangle{ anchor01.x + 15, anchor01.y + 210, 240, 60 }, "Spring");
		GuiSliderBar(Rectangle{ anchor01.x + 96, anchor01.y + 220, 120, 16 }, "Damping", GUI_DATA(SpringDampingSliderValue), 0, 1);
		GuiSliderBar(Rectangle{ anchor01.x + 96, anchor01.y + 240, 120, 16 }, "Stiffness", GUI_DATA(SpringStiffnessSliderValue), 0, 1);

		GuiGroupBox(Rectangle{ anchor01.x + 15, anchor01.y + 290, 240, 80 }, "World");
		GuiSlider(Rectangle { anchor01.x + 96, anchor01.y + 300, 120, 16 }, "Gravitation", GUI_DATA(GravitationSliderValue), -20, 20);
		GuiSlider(Rectangle { anchor01.x + 96, anchor01.y + 320, 120, 16 }, "Gravity", GUI_DATA(GravitySliderValue), -20, 20);
		GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 340, 120, 16 }, "Stiffness X", GUI_DATA(World::springStiffnessMultiplier), 0, 100);

		if (GuiDropdownBox(Rectangle { anchor01.x + 96, anchor01.y + 150, 120, 24 }, "DYNAMIC;STATIC;KINEMATIC", & BodyTypeDropdownBoxActive, BodyTypeDropdownBoxEditMode)) BodyTypeDropdownBoxEditMode = !BodyTypeDropdownBoxEditMode;



		//put on top of gravitation in finished box +  160


		//PhysicsWindowBoxActive = !GuiWindowBox(Rectangle{ anchor01.x + 0, anchor01.y + 0, 272, 512 }, "SAMPLE TEXT");
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 48, 120, 16 }, "Gravity", std::to_string(GravitySliderValue).c_str(), &m_world->m_gravity.y, -20, 20);
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 80, 120, 16 }, "Gravity Scale", std::to_string(GravityScaleSliderValue).c_str(), &m_world->m_gravityScale, 0, 100);
		////GuiSlider(Rectangle { anchor01.x + 96, anchor01.y + 136, 120, 16 }, "Body Mass", GUI_DATA(BodyMassSliderValue), &m_world->m_mass, 0, 10);
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 136, 120, 16 }, "Body Mass", std::to_string(BodyMassSliderValue).c_str(), &m_world->m_mass, 0, 10);
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 168, 120, 16 }, "Body Size", std::to_string(BodySizeSliderValue).c_str(), &m_bodySize, 0.01, 1);
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 200, 120, 16 }, "Body Damping", std::to_string(BodyDampintSliderValue).c_str(), &m_world->m_damping, 0, 1);
		//if (GuiDropdownBox(Rectangle{ anchor01.x + 96, anchor01.y + 248, 120, 24 }, "DYNAMIC;STATIC;KINEMATIC", &BodyTypeDropdownBoxActive, BodyTypeDropdownBoxEditMode)) BodyTypeDropdownBoxEditMode = !BodyTypeDropdownBoxEditMode;
	}

	GuiUnlock();
}

Body* GUI::GetBodyIntersect(const Vector2& position, bodies_t& bodies, const SceneCamera& camera)
{
	for (auto body : bodies)
	{
		if (CheckCollisionPointCircle(position, body->position, body->size))
		{
			return body;
		}
	}

	return nullptr;
}
