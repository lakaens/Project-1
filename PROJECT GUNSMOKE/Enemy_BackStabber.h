#ifndef __ENEMY_BACKSTABBER_H__
#define __ENEMY_BACKSTABBER_H__

#include "Enemy.h"

class Enemy_BackStabber : public Enemy
{
private:

	Animation move;

public:

	Enemy_BackStabber(int x, int y);
	void Move();
};


#endif
