#ifndef _BIGBOTTLE_BARREL_H_
#define _BIGBOTTLE_BARREL_H_

#include "Enemy.h"

class BigBottle_Barrel : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	BigBottle_Barrel(int x, int y);
};


#endif