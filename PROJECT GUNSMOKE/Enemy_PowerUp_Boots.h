#ifndef __Power_Up_H__
#define __Power_Up_H__

#include "Enemy.h"

class PowerUp_Boots : public Enemy
{
private:
	Animation boots;
	bool up;
	bool right;

public:

	PowerUp_Boots(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);

};

#endif
