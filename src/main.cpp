/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "TrigonometryScene.h"
#include "PolarScene.h"



//Raylib is a C Library. There are classes but not functions
//For this reason we have to rename main.c to main.cpp so we can have classes.

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1280, 800, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");
	
	
	//Key word new constrcts on the heap
	//Scene* scene = new TrigonometryScene("trigonometry", 1280, 720);
	Scene* scene = new PolarScene("polar", 1280, 720);
	scene->Initialize();

	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		scene->Update();
		scene->BeginDraw();
		scene->Draw();
		scene -> EndDraw();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}








//// drawing
//BeginDrawing();
//
//
//
//
//// Setup the back buffer for drawing (clear color and depth buffers)
//ClearBackground(BLACK);
//
//// draw some text using the default font
//DrawText("Hello Raylib", 200, 200, 20, WHITE);
//
//// draw our texture to the screen
//DrawTexture(wabbit, 400, 200, WHITE);
//
//////
////DrawCircle(200, 200, 200, RED);
//DrawCircleV(GetMousePosition(), 200, RED);
//
//
//
//// end the frame and get ready for the next one  (display frame, poll input, etc...)
//EndDrawing();