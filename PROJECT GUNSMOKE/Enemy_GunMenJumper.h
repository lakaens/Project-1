
#ifndef __ENEMY_GUNMENJUMPER_H__
#define __ENEMY_GUNMENJUMPER_H__

#include "Enemy.h"
#include "path.h"

class Enemy_GunMenJumper : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	Animation horizontal;
	Animation stay;
	Animation diagonaldown;
	Animation move;
public:

	Enemy_GunMenJumper(int x, int y);
	void Move();
	void Shoot();
};


#endif

