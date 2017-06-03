#ifndef _POWERUP_BIGBOTTLE_H_
#define _POWERUP_BIGBOTTLE_H_

#include "Enemy.h"

class BigBottle : public Enemy
{
private:
	Animation bottle;
	iPoint original_pos;

public:

	BigBottle(int x, int y);

};

#endif