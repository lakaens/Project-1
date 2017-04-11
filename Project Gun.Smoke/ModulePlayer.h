#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"


struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
private:
	uint bulletsound;
	unsigned short bullet;
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

	void CollisionCheck(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	Animation forward;
	Animation shootf;
	Animation diagonalr;
	Animation diagonall;
	Animation shootdr;
	Animation shootdl;
	iPoint position;
	Collider* colider;
	

};

#endif
