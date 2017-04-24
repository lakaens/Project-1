#ifndef __ENEMY_WINDOWSNIPERRIGHT_H__
#define __ENEMY_WINDOWSNIPERRIGHT_H__

#include "Enemy.h"

class Enemy_WindowSniperRight : public Enemy
{
private:

	Animation move;

public:

	Enemy_WindowSniperRight(int x, int y);
	void Move();
};


#endif
