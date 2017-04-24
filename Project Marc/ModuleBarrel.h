#ifndef __ModuleBarrel_H__
#define __ModuleBarrel_H__



#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

#define MAX_BARRELS 20


class Barrel;

class ModuleBarrel : public Module
{
public:

	ModuleBarrel();
	~ModuleBarrel();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);


private:

	SDL_Texture* barrelsprites = nullptr;
	Animation* current_animation;
	Collider* barrelcollider;
	int life = 5;
	Barrel* barrels[MAX_BARRELS];

};

#endif // __ModuleBarrel_H__