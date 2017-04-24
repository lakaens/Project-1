#ifndef __ENEMY_BOMBER_H__
#define __ENEMY_BOMBER_H__

#include "Enemy.h"

class Enemy_Bomber : public Enemy
{
private:

	Animation move;

public:

	Enemy_Bomber(int x, int y);
	void Move();
};


#endif

