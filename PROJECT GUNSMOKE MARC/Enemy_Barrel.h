#ifndef _ENEMY_BARREL_H_
#define _ENEMY_BARREL_H_

#include "Enemy.h"

class Enemy_Barrel : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	Enemy_Barrel(int x, int y);
};


#endif
