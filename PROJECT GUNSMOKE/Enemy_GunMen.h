
#ifndef __ENEMY_GUNMEN_H__
#define __ENEMY_GUNMEN_H__

#include "Enemy.h"
#include "path.h"

class Enemy_GunMen : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	Animation move;

public:

	Enemy_GunMen(int x, int y);
	void Move();
};


#endif

