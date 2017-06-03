#ifndef _POWERUP_BULLET_H_
#define _POWERUP_BULLET_H_

#include "Enemy.h"

class PowerUp_Bullet : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	PowerUp_Bullet(int x, int y);
};


#endif