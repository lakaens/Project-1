#ifndef __ModuleStage1_H__
#define __ModuleStage1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleAudio.h"


struct SDL_Texture;


class ModuleStage1 : public Module
{
public:

	ModuleStage1();
	~ModuleStage1();

	bool Start();
	update_status Update();
	bool CleanUp();

	
public:
	SDL_Texture* texture = nullptr;
	SDL_Rect background;
	Collider* colider;
	bool state = true;

	int background_y;
	


};
#endif 