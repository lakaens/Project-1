#ifndef __ENEMY_BOSS_H__
#define __ENEMY_BOSS_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Boss : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	Animation down;
	Animation diagonal;
	Animation stay;
	Animation up;
	

public:

	Enemy_Boss(int x, int y);
	void Move();
};


#endif

