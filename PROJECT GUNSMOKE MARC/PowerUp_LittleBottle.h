#ifndef _POWERUP_LITTLEBOTTLE_H_
#define _POWERUP_LITTLEBOTTLE_H_

#include "Enemy.h"

class LittleBottle : public Enemy
{
private:
	Animation bottle;
	iPoint original_pos;

public:

	LittleBottle(int x, int y);

};

#endif