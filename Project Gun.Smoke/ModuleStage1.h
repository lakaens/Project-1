#ifndef __ModuleStage1_H__
#define __ModuleStage1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleAudio.h"

#define MAX_COLLIDERS 10

struct SDL_Texture;
struct Collider;


class ModuleStage1 : public Module
{
private:
	uint numColliders;
public:

	ModuleStage1();
	~ModuleStage1();

	bool Start();
	update_status Update();
	bool CleanUp();

	
public:
	SDL_Texture* texture = nullptr;
	SDL_Rect background;
	Collider* coliders[MAX_COLLIDERS];
	bool state = true;

	int background_y;
	int down_speed;
	


};
#endif 