#ifndef __Bootle1_H__
#define __Bootle1_H__

#include "Enemy.h"

class Enemy_Bootle1: public Enemy
{
private:
	Animation bottle;
	

public:

	Enemy_Bootle1(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);

};

#endif
