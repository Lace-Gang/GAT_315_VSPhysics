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
	//if (PhysicsWindowBoxActive)
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
		GuiSlider(Rectangle { anchor01.x + 96, anchor01.y + 48, 120, 16 }, "Gravity", GUI_DATA(GravitySliderValue), -20, 20);
		GuiSlider(Rectangle { anchor01.x + 96, anchor01.y + 80, 120, 16 }, "Gravity Scale", GUI_DATA(GravityScaleSliderValue), 0, 100);
		GuiSlider(Rectangle { anchor01.x + 96, anchor01.y + 136, 120, 16 }, "Body Mass", GUI_DATA(BodyMassSliderValue), 0, 10);
		GuiSlider(Rectangle { anchor01.x + 96, anchor01.y + 168, 120, 16 }, "Body Size", GUI_DATA(BodySizeSliderValue), 0.01, 1);
		GuiSlider(Rectangle { anchor01.x + 96, anchor01.y + 200, 120, 16 }, "Body Damping", GUI_DATA(BodyDampintSliderValue), 0, 1);
		if (GuiDropdownBox(Rectangle { anchor01.x + 96, anchor01.y + 248, 120, 24 }, "DYNAMIC;STATIC;KINEMATIC", & BodyTypeDropdownBoxActive, BodyTypeDropdownBoxEditMode)) BodyTypeDropdownBoxEditMode = !BodyTypeDropdownBoxEditMode;

		//PhysicsWindowBoxActive = !GuiWindowBox(Rectangle{ anchor01.x + 0, anchor01.y + 0, 272, 512 }, "SAMPLE TEXT");
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 48, 120, 16 }, "Gravity", std::to_string(GravitySliderValue).c_str(), &m_world->m_gravity.y, -20, 20);
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 80, 120, 16 }, "Gravity Scale", std::to_string(GravityScaleSliderValue).c_str(), &m_world->m_gravityScale, 0, 100);
		////GuiSlider(Rectangle { anchor01.x + 96, anchor01.y + 136, 120, 16 }, "Body Mass", GUI_DATA(BodyMassSliderValue), &m_world->m_mass, 0, 10);
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 136, 120, 16 }, "Body Mass", std::to_string(BodyMassSliderValue).c_str(), &m_world->m_mass, 0, 10);
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 168, 120, 16 }, "Body Size", std::to_string(BodySizeSliderValue).c_str(), &m_bodySize, 0.01, 1);
		//GuiSlider(Rectangle{ anchor01.x + 96, anchor01.y + 200, 120, 16 }, "Body Damping", std::to_string(BodyDampintSliderValue).c_str(), &m_world->m_damping, 0, 1);
		//if (GuiDropdownBox(Rectangle{ anchor01.x + 96, anchor01.y + 248, 120, 24 }, "DYNAMIC;STATIC;KINEMATIC", &BodyTypeDropdownBoxActive, BodyTypeDropdownBoxEditMode)) BodyTypeDropdownBoxEditMode = !BodyTypeDropdownBoxEditMode;
	}
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
