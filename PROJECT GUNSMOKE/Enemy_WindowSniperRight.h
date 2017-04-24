#ifndef _ENEMY_WINDOWSNIPERRIGHT_H_
#define _ENEMY_WINDOWSNIPERRIGHT_H_

#include "Enemy.h"
#include "Path.h"

class Enemy_WindowSniperRight : public Enemy
{
private:
	Path path;
	Animation move;
	iPoint original_pos;
public:

	Enemy_WindowSniperRight(int x, int y);
	void Move();
};


#endif