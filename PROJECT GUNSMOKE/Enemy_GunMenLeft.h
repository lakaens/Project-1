
#ifndef __ENEMY_GUNMENLEFT_H__
#define __ENEMY_GUNMENLEFT_H__

#include "Enemy.h"
#include "path.h"

class Enemy_GunMenLeft : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	Animation horizontal;
	
public:

	Enemy_GunMenLeft(int x, int y);
	void Move();
	void Shoot();
};


#endif

