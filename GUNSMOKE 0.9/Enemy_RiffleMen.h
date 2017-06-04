#ifndef __ENEMY_RIFFLEMEN_H__
#define __ENEMY_RIFFLEMEN_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_RiffleMen : public Enemy
{
private:
	
	Path path;
	iPoint original_pos;
	Animation move;
	Animation sides; 
	iPoint speed;
	float h;
	uint lastTime = 0;
	uint lastTime2 = 0;

public:

	Enemy_RiffleMen(int x, int y);
	void Move();
	void Shoot();
};


#endif


