
#ifndef __ENEMY_GUNMEN_H__
#define __ENEMY_GUNMEN_H__

#include "Enemy.h"
#include "path.h"

class Enemy_GunMen : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	iPoint speed;
	Animation right;
	Animation downright;
	Animation downleft;
	Animation upright;
	Animation upleft;
	Animation left;
	Animation down;
	bool gate[4];

public:

	Enemy_GunMen(int x, int y);
	void Move();
	void Shoot();
};


#endif

