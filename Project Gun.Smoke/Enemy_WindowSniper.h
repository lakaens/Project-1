#ifndef __ENEMY_WINDOWSNIPER_H__
#define __ENEMY_WINDOWSNIPER_H__

#include "Enemy.h"

class Enemy_WindowSniper : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;

public:

	Enemy_WindowSniper(int x, int y);
	void Move();
};


#endif