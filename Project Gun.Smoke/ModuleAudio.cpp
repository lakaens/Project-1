#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

#include "SDL_mixer/include/SDL_mixer.h"

#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleAudio::ModuleAudio() : Module()
{}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Init()
{
	bool res = true;
	int initogg = MIX_INIT_OGG;
	int ogg = Mix_Init(initogg);
	float time= Musictime;
	

	SDL_Init(SDL_INIT_AUDIO);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
	LOG("SDL_AUDIO could not initialize! SDL_Error: %s", Mix_GetError());
		res = false;
	}

	if ((ogg&initogg != initogg)) {
		LOG("Error Mixer Lib: %s", Mix_GetError());
		res = false;
	}

	return res;
}

bool ModuleAudio::CleanUp() {
	if (music != NULL)
	{
		Mix_FreeMusic(music);
	}

	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	return true;
}



bool ModuleAudio::musicLoad(const char* path, float time) {
	bool res = true;

	music = Mix_LoadMUS(path);

	if (music == NULL) {
		LOG("Error sdl music: %s", SDL_GetError());
		LOG("Error loading music: %s", Mix_GetError());
		res = false;
	}
	else {
		if (time > 0.0f) {
			if (Mix_FadeInMusic(music, -1, (int)(time*1000.0f)) < 0) {
				LOG("Error fade in music: %s", Mix_GetError());
				res = false;
			}
		}
		else {
			if (Mix_PlayMusic(music, -1) < 0) {
				LOG("Unable to play music: %s", Mix_GetError());
				res = false;
			}
			return res;
		}
	}
}
		
