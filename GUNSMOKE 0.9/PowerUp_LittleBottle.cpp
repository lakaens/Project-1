#include "Application.h"
#include "PowerUp_LittleBottle.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

PowerUp_LittleBottle::PowerUp_LittleBottle(int x, int y) : Enemy(x, y)
{
	bottle.PushBack({ 459,76,12,13 });

	animation = &bottle;

	position.x = x;
	position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 12, 13 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);


}
