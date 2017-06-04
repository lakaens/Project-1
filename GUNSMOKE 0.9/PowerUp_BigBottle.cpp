#include "Application.h"
#include "PowerUp_BigBottle.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

PowerUp_BigBottle::PowerUp_BigBottle(int x, int y) : Enemy(x, y)
{
	bottle.PushBack({ 60,17,11,13 });

	animation = &bottle;

	position.x = x;
	position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 11, 13 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);


}

