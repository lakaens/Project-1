#include<iostream>
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"

#include "SDL/include/SDL.h"

using namespace std;

// TODO 2: Init the library and check for possible error
// using SDL_GetError()

// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)


bool ModuleWindow::Init()
{
	bool ret = true;
		window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_WIDTH, SDL_WINDOW_SHOWN);
		if (window = nullptr) {
			LOG(SDL_GetError());
			ret = false;
		}
		else {
			SDL_UpdateWindowSurface(window);
		
		}
	return ret;
}


bool ModuleWindow::CleanUp()
{
	if (ModuleWindow::CleanUp() == true) {
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	return false;
}
