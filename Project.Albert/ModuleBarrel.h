#ifndef __ModuleBarrel_H__
#define __ModuleBarrel_H__



#include "Module.h"
#include "Animation.h"
#include "p2Point.h"


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

};

#endif // __ModuleCollision_H__
