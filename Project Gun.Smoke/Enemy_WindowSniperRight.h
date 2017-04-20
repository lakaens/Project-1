#ifndef __ENEMY_WINDOWSNIPERRIGHT_H__
#define __ENEMY_WINDOWSNIPERRIGHT_H__

#include "Enemy.h"

class Enemy_WindowSniperRight : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;

public:

	Enemy_WindowSniperRight(int x, int y);
	void Move();
};


#endif