#ifndef __POWERUP_POW_H__
#define __POWERUP_POW_H__

#include "PowerUp.h"

class PowerUp_Pow : public PowerUp
{
private:
	float wave = -1.0f;
	int original_y = 0;
	Animation idle;

public:

	PowerUp_Pow(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);

};


#endif