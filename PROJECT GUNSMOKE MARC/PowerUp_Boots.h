#ifndef _POWERUP_BOOTS_H_
#define _POWERUP_BOOTS_H_

#include "Enemy.h"

class PowerUp_Boots : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	PowerUp_Boots(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);
};


#endif
