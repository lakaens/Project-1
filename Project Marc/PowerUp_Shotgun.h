#ifndef __POWERUP_SHOTGUN_H__
#define __POWERUP_SHOTGUN_H__

#include "PowerUp.h"

class PowerUp_Shotgun : public PowerUp
{
private:
	float wave = -1.0f;
	int original_y = 0;
	Animation idle;

public:

	PowerUp_Shotgun(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);

};


#endif