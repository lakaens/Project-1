#ifndef _BOOTS_BARREL_H_
#define _BOOTS_BARREL_H_

#include "Enemy.h"

class Boots_Barrel : public Enemy
{
private:

	Animation move;
	


public:
	iPoint original_pos;
	Boots_Barrel(int x, int y);
};


#endif