#ifndef _POWERUP_HORSE_H_
#define _POWERUP_HORSE_H_

#include "Enemy.h"

class PowerUp_Horse : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	PowerUp_Horse(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);
};


#endif