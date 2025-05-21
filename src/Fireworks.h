#pragma once
#include "scene.h"


struct  Body; //avoid cyclical references (fine as long as the include is in the cpp)
class FireworksScene : public Scene //calling Scene public allows it to be seen from here
{
public:
	FireworksScene(const std::string& title, int width, int height, const Color& background = BLACK) :
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
	Body* m_head = nullptr;
	Body* m_player = nullptr;
};