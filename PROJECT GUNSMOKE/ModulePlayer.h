#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	int font_score = -1;
	char score_text[10];
	uint score = 0;
	Animation* current_animation = nullptr;
	Animation right;
	Animation left;
	Animation up;
	Animation shootu;
	Animation shootr;
	Animation shootl;
	Animation dead;
	fPoint position;
	bool colup = false;
	bool coldown = false;
	bool colleft = false;
	bool colright = false;
	int cameralim;
	Collider* col;
	int cont = 0;
	bool destroyed = false;
private:
	uint bulletsound;
	unsigned short bullet;
};

#endif