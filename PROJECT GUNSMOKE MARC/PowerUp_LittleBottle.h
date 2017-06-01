#ifndef _POWERUP_LITTLEBOTTLE_H_
#define _POWERUP_LITTLEBOTTLE_H_

#include "Enemy.h"

class LittleBottle : public Enemy
{
private:
	Animation bottle;


public:

	LittleBottle(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);

};

#endif