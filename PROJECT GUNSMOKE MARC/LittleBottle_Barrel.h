#ifndef _LITTLEBOTTLE_BARREL_H_
#define _LITTLEBOTTLE_BARREL_H_

#include "Enemy.h"

class LittleBottle_Barrel : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	LittleBottle_Barrel(int x, int y);
};


#endif