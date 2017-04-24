#ifndef __BARREL_H__
#define __BARREL_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Barrel
{

public:
	iPoint position;
	Collider* collider = nullptr;

public:
	Barrel(int x, int y);
	virtual ~Barrel();

	int life = 5;

	const Collider* GetCollider() const;

	Animation* current_animation;
	Animation idle;
	Animation barrel;

	void Draw(SDL_Texture* sprites);
	void OnCollision(Collider* c1, Collider* c2);
};

#endif // __BARREL_H__
