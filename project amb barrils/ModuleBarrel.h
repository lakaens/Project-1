#ifndef __ModuleBarrel_H__
#define __ModuleBarrel_H__

#include "Module.h"

#define MAX_BARRELS 20

struct SDL_Texture;
struct Collider;

class Barrel;

struct BarrelInfo
{
	int x, y;
};


class ModuleBarrel : public Module
{

public:
	iPoint position;

public:
	ModuleBarrel();
	~ModuleBarrel();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);
	bool AddBarrel(int x, int y);

private:
	void SpawnBarrel(const BarrelInfo& info);
	SDL_Texture* text;
	BarrelInfo queue[MAX_BARRELS];
	Barrel* barrels[MAX_BARRELS];
};


#endif