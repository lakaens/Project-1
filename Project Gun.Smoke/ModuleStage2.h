#ifndef __ModuleStage2_H__
#define __ModuleStage2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleStage2 : public Module
{
public:

	ModuleStage2();
	~ModuleStage2();

	bool Start();
	update_status Update();

public:
	SDL_Texture* texture = nullptr;
	SDL_Rect background;


};



#endif;