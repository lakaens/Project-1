#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "Globals.h"

#define Musictime 2.0f

class ModuleAudio : public Module 
{
public:

	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	bool musicLoad(const char* path, float time = Musictime);

	bool ModuleAudio::StopMusic();

private:
	Mix_Music* music = nullptr;
};
#endif 