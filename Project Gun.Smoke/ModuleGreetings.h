#ifndef __ModuleGreetings_H__
#define __ModuleGreetings_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"


struct SDL_Texture;


class ModuleGreetings : public Module
{
public:

	ModuleGreetings();
	~ModuleGreetings();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* texture = nullptr;
	SDL_Rect background;
	bool state = true;



};
#endif 