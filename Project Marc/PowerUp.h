#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class PowerUp
{
protected:

	Collider* collider = nullptr;
	Animation* animation = nullptr;

public:
	iPoint position;

public:
	PowerUp(int x, int y);
	virtual ~PowerUp();

	const Collider* GetCollider() const;

	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* c1, Collider* c2);
};

#endif // __POWERUP_H__