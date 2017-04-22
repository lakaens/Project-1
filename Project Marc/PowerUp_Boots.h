#ifndef __POWERUP_BOOTS_H__
#define __POWERUP_BOOTS_H__

#include "PowerUp.h"

class PowerUp_Boots : public PowerUp
{
private:
	float wave = -1.0f;
	int original_y = 0;
	Animation idle;

public:

	PowerUp_Boots(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);

};


#endif