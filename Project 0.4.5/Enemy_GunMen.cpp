#include "Application.h"
#include "Enemy_GunMen.h"
#include "ModuleCollision.h"

Enemy_GunMen::Enemy_GunMen(int x, int y) :Enemy(x, y) {

	move.PushBack({ 2,9,20,29 });
	move.PushBack({ 39, 8, 20, 29 });
	move.PushBack({ 72, 9, 20, 29 });

	move.speed = 0.2f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	

}

void Enemy_GunMen::Move()
{
	
}