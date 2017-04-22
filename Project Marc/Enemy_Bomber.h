#ifndef __ENEMY_BOMBER_H__
#define __ENEMY_BOMBER_H__

#include "Enemy.h"

class Enemy_Bomber : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;

public:

	Enemy_Bomber(int x, int y);
	void Move();
};


#endif
