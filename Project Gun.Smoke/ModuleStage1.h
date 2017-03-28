#ifndef __ModuleStage1_H__
#define __ModuleStage1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleStage1 : public Module
{
public:

	ModuleStage1();
	~ModuleStage1();

	bool Start();
	update_status Update();
	
public:
	SDL_Texture* texture = nullptr;
	SDL_Rect background;


};
#endif 