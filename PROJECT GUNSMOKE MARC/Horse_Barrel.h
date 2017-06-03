#ifndef _HORSE_BARREL_H_
#define _HORSE_BARREL_H_

#include "Enemy.h"

class Horse_Barrel : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	Horse_Barrel(int x, int y);
};


#endif