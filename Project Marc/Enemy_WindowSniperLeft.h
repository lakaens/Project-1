#ifndef __ENEMY_WINDOWSNIPERLEFT_H__
#define __ENEMY_WINDOWSNIPERLEFT_H__

#include "Enemy.h"

class Enemy_WindowSniperLeft : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;

public:

	Enemy_WindowSniperLeft(int x, int y);
	void Move();
};


#endif