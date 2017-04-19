#ifndef __ENEMY_RIFFLEMEN_H__
#define __ENEMY_RIFFLEMEN_H__

#include "Enemy.h"

class Enemy_RiffleMen : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;

public:

	Enemy_RiffleMen(int x, int y);
	void Move();
};


#endif

