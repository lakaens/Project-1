#include "Application.h"
#include "Enemy_GunMen.h"
#include "ModuleCollision.h"

Enemy_GunMen::Enemy_GunMen(int x, int y) :Enemy(x, y) {

	move.PushBack({ 214, 51, 20, 28 });
	move.PushBack({ 254, 53, 20, 28 });
	move.PushBack({ 294, 51, 20, 28 });

	move.speed = 0.2f;

	animation = &move;

	path.PushBack({ -0.5f, 0.0f }, 100);

	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_GunMen::Move()
{
	position = original_pos + path.GetCurrentSpeed();
}