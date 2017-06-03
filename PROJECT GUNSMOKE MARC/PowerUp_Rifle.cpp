#include "Application.h"
#include "PowerUp_Rifle.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

PowerUp_Rifle::PowerUp_Rifle(int x, int y) :Enemy(x, y) {


	move.PushBack({ 457, 26, 16, 14 });
	move.PushBack({ 457, 50, 16, 14 });
	move.loop = true;
	move.speed = 0.3f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,16,14 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}