#include "Application.h"
#include "PowerUp_LittleBottle.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

LittleBottle::LittleBottle(int x, int y) : Enemy(x, y)
{
	bottle.PushBack({ 459,76,12,13 });
	bottle.loop = false;
	bottle.speed = 0.5;

	animation = &bottle;

	collider = App->collision->AddCollider({ 0, 0, 12, 13 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}