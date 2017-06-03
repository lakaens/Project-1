#ifndef _POWERUP_RIFLE_H_
#define _POWERUP_RIFLE_H_

#include "Enemy.h"

class PowerUp_Rifle : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	PowerUp_Rifle(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);
};


#endif