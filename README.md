# This is a C++ Physics Simulation Program for a class project.

Included inside are five different scenes:
* Fireworks
* Polar
* Spring
* Trigonometry
* Vector

# Trigonometry Scene
This scene displays a unit circle, a sign wave, and a cosine wave that move with time. This scene is non-interactable

<img width="625" alt="image" src="https://github.com/user-attachments/assets/7612b099-5d5b-47aa-a1a4-86dc23825224" />

# Polar Scene
This scene demonstrates the use of Polar coordinates by displaying different types of spirals. This scene is non-interactable

<img width="626" alt="image" src="https://github.com/user-attachments/assets/61ef28d8-3e01-487d-8950-a6c0e103df34" />


# Fireworks Scene
This is an interactable scene where three different types of fireworks can be created by clicking the screen
Fireworks have random Colors and sizes, and are being used to demonstrate different physics concepts such as 
gravity and velocity

<img width="617" alt="Fireworks_7" src="https://github.com/user-attachments/assets/0d8574d2-4dfb-49bd-b99d-23a9b47dfcc7" />
<img width="615" alt="Fireworks_5" src="https://github.com/user-attachments/assets/eba079c7-8cc1-4f0d-9018-7854a677a782" />

# Vector Scene
This is an interactable scene where a certain number of bodies (circles) can be created by clicking the screen
These bodies demonstrate gravity and velocity as well as size, mass, restitution and collision

<img width="450" alt="image" src="https://github.com/user-attachments/assets/ddb95e1c-a90b-4858-8af2-4ed8a55bbd05" />

# Spring Scene
This is a very interactable scene and can be considered the "Finished Product" in which users may adjust values in the GUI to see
different effects. By clicking outside the GUI, one body (circle) will be spawned in with the current GUI specifications a random velocity.
By holding left control and left click, a number of bodies will be created. Both the space bar and the simulate button can be use to pause 
the simulation. Right clicking a body and draging to another body allows users to connect a spring between the two bodies using the current 
spring settings specified in the GUI.

All settings, selections and buttons in the GUI have been implemented and a fully functional.

<img width="626" alt="image" src="https://github.com/user-attachments/assets/1a0d7277-8378-4f93-b704-9aa30a04e1bb" />





## Raylib Readme as required by license: 
# Raylib-Quickstart
A simple cross platform template for setting up a project with the bleeding edge raylib code.
Works with C or C++.

## Supported Platforms
Quickstart supports the main 3 desktop platforms:
* Windows
* Linux
* MacOS

# Naming projects
Do not name your game project 'raylib', it will conflict with the raylib library.

# VSCode Users (all platforms)
*Note* You must have a compiler toolchain installed in addition to vscode.

* Download the quickstart
* Rename the folder to your game name
* Open the folder in VSCode
* Run the build task ( CTRL+SHIFT+B or F5 )
* You are good to go

# Windows Users
There are two compiler toolchains available for windows, MinGW-W64 (a free compiler using GCC), and Microsoft Visual Studio
## Using MinGW-W64
* Double click the `build-MinGW-W64.bat` file
* CD into the folder in your terminal
* run `make`
* You are good to go

### Note on MinGW-64 versions
Make sure you have a modern version of MinGW-W64 (not mingw).
The best place to get it is from the W64devkit from
https://github.com/skeeto/w64devkit/releases
or the version installed with the raylib installer
#### If you have installed raylib from the installer
Make sure you have added the path

`C:\raylib\w64devkit\bin`

To your path environment variable so that the compiler that came with raylib can be found.

DO NOT INSTALL ANOTHER MinGW-W64 from another source such as msys2, you don't need it.

## Microsoft Visual Studio
* Run `build-VisualStudio2022.bat`
* double click the `.sln` file that is generated
* develop your game
* you are good to go

# Linux Users
* CD into the build folder
* run `./premake5 gmake2`
* CD back to the root
* run `make`
* you are good to go

# MacOS Users
* CD into the build folder
* run `./premake5.osx gmake2`
* CD back to the root
* run `make`
* you are good to go

# Output files
The built code will be in the bin dir

# Working directories and the resources folder
The example uses a utility function from `path_utils.h` that will find the resources dir and set it as the current working directory. This is very useful when starting out. If you wish to manage your own working directory you can simply remove the call to the function and the header.

# Changing to C++
Simply rename `src/main.c` to `src/main.cpp` and re-run the steps above and do a clean build.

# Using your own code
Simply remove `src/main.c` and replace it with your code, and re-run the steps above and do a clean build.

# Building for other OpenGL targets
If you need to build for a different OpenGL version than the default (OpenGL 3.3) you can specify an OpenGL version in your premake command line. Just modify the bat file or add the following to your command line

## For OpenGL 1.1
`--graphics=opengl11`

## For OpenGL 2.1
`--graphics=opengl21`

## For OpenGL 4.3
`--graphics=opengl43`

## For OpenGLES 2.0
`--graphics=opengles2`

## For OpenGLES 3.0
`--graphics=opengles3`

# License
Copyright (c) 2020-2025 Jeffery Myers

This software is provided "as-is", without any express or implied warranty. In no event 
will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial 
applications, and to alter it and redistribute it freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim that you 
  wrote the original software. If you use this software in a product, an acknowledgment 
  in the product documentation would be appreciated but is not required.

  2. Altered source versions must be plainly marked as such, and must not be misrepresented
  as being the original software.

  3. This notice may not be removed or altered from any source distribution.
