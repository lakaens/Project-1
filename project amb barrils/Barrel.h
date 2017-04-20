#ifndef __BARREL_H__
#define __BARREL_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Barrel
{
protected:
	Animation* animation = nullptr;
	Collider* collider = nullptr;

public:
	iPoint position;

public:
	Barrel(int x, int y);
	virtual ~Barrel();
	int life = 5;
	bool dead = false;

	const Collider* GetCollider() const;

	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* c1, Collider* c2);

private:
	Animation destroy;
	SDL_Rect rect;
};

#endif // __BARREL_H__