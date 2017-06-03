#ifndef _RIFLE_BARREL_H_
#define _RIFLE_BARREL_H_

#include "Enemy.h"

class Rifle_Barrel : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	Rifle_Barrel(int x, int y);
};


#endif