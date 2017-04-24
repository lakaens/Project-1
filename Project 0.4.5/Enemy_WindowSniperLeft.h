#ifndef __ENEMY_WINDOWSNIPERLEFT_H__
#define __ENEMY_WINDOWSNIPERLEFT_H__

#include "Enemy.h"

class Enemy_WindowSniperLeft : public Enemy
{
private:

	Animation move;

public:

	Enemy_WindowSniperLeft(int x, int y);
	void Move();
};


#endif

