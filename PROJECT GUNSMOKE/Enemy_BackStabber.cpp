#include "Application.h"
#include "Enemy_BackStabber.h"
#include "ModuleCollision.h"

Enemy_BackStabber::Enemy_BackStabber(int x, int y) :Enemy(x, y) {

	move.PushBack({ 336,173,20,24 });
	move.PushBack({ 372, 171, 19, 25 });
	move.PushBack({ 411, 168, 22, 26 });
	move.PushBack({ 450, 170, 21, 24 });
	move.speed = 0.2f;

	path.PushBack({ 0.f,0.5f }, 100);

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMYBUILDING, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
	
}

void Enemy_BackStabber::Move()
{
	position = original_pos + path.GetCurrentSpeed();
}