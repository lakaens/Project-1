#ifndef __ENEMY_BACKSTABBER_H__
#define __ENEMY_BACKSTABBER_H__

#include "Enemy.h"

class Enemy_BackStabber : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;

public:

	Enemy_BackStabber(int x, int y);
	void Move();
};


#endif