#ifndef __POWERUP_HORSE_H__
#define __POWERUP_HORSE_H__

#include "PowerUp.h"

class PowerUp_Horse : public PowerUp
{
private:
	float wave = -1.0f;
	int original_y = 0;
	Animation idle;

public:

	PowerUp_Horse(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);

};


#endif