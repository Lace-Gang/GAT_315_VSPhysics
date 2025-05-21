#pragma once

#include "scene.h"


class PolarScene : public Scene
{
public:
	PolarScene(const std::string& title, int width, int height, const Color& background = BLACK) :
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
	void DrawSpiral(float startRadius, float spacing);
	void DrawCardioid(float size);
	void DrawLimacon(float loop, float dimple);
	void DrawRoseCurve(float size, int petals);
	void DrawUserSpiral(float size, int petals, float difference);
};