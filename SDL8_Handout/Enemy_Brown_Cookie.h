#ifndef __ENEMY_Brown_Cookie_H__
#define __ENEMY_Brown_Cookie_H__

#include "Enemy.h"
#include"Path.h"
#include"p2Point.h"

class Enemy_Brown_Cookie : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	iPoint originalPosition;
	Animation fly;
	Path path;

public:
	

	Enemy_Brown_Cookie(int x, int y);

	void Move();
};

#endif // __ENEMY_Brown_Cookie_H__
