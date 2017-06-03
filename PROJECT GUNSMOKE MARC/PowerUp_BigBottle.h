#ifndef _POWERUP_BIGBOTTLE_H_
#define _POWERUP_BIGBOTTLE_H_

#include "Enemy.h"

class BigBottle : public Enemy
{
private:
	Animation bottle;


public:

	BigBottle(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);

};

#endif