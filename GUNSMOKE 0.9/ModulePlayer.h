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
	Animation chorse;
	Animation right;
	Animation left;
	Animation up;
	Animation shootu;
	Animation shootr;
	Animation shootl;
	Animation empty;
	fPoint position;
	fPoint prevpos;
	float cameralim;
	Collider* col;
	int cont = 0;
	bool destroyed = false;
	int life = 3;
	int cont1 = 0;
	int original_camera;
	bool colup = false;
	bool colleft = false;
	bool coldown = false;
	bool colright = false;
	bool blockUL = false;
	bool blockUR = false;
	bool blockDL = false;
	bool blockDR = false;
	char str[10];
	char hscore[10] = { 0,0,0,0,0,0,0,0,0,0 };
	uint Hscore = 0;
	float speed = 1.5;
	bool GodMode = false;

private:
	uint bulletsound;
	unsigned short bullet;
};

#endif