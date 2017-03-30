#ifndef __ModuleWelcome_H__
#define __ModuleWelcome_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"


struct SDL_Texture;


class ModuleWelcome : public Module
{
public:

	ModuleWelcome();
	~ModuleWelcome();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	bool state = true;
	SDL_Texture* texture = nullptr;
	SDL_Rect background;



};
#endif 
