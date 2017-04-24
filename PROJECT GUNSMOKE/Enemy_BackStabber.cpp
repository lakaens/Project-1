#include "Application.h"
#include "Enemy_BackStabber.h"
#include "ModuleCollision.h"

Enemy_BackStabber::Enemy_BackStabber(int x, int y) :Enemy(x, y) {

	move.PushBack({ 5,6,24,24 });
	move.PushBack({ 38, 6, 24, 24 });
	move.PushBack({ 71, 6, 24, 24 });
	move.PushBack({ 104, 6, 24, 24 });
	move.PushBack({ 137, 6, 24, 24 });
	move.PushBack({ 170, 6, 24, 24 });
	move.PushBack({ 203, 6, 24, 24 });
	move.PushBack({ 236, 6, 24, 24 });
	move.speed = 0.2f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	
}

void Enemy_BackStabber::Move()
{
	
}