#ifndef __ModuleBarrel_H__
#define __ModuleBarrel_H__



#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

#define MAX_BARRELS 20

struct Barrel {
	iPoint pos;
	Collider* barrelcoll;
	int life = 5;
};

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

	SDL_Texture* graphics = nullptr;
	Animation* current_animation;
	Animation idle;
	Animation barrel;
	iPoint position;
	Collider* barrelcollider;
	int life = 5;
	Barrel barrels[MAX_BARRELS];

};

#endif // __ModuleBarrel_H__