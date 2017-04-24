#ifndef __ENEMY_RIFFLEMEN_H__
#define __ENEMY_RIFFLEMEN_H__

#include "Enemy.h"

class Enemy_RiffleMen : public Enemy
{
private:
	
	Animation move;

public:

	Enemy_RiffleMen(int x, int y);
	void Move();
};


#endif


