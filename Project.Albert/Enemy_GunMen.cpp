#include "Application.h"
#include "Enemy_GunMen.h"
#include "ModuleCollision.h"

Enemy_GunMen::Enemy_GunMen(int x, int y) :Enemy(x, y) {

	move.PushBack({ 222, 52,17,26 });
	move.PushBack({ 262, 53, 17, 26 });
	move.PushBack({ 302, 52, 21, 26 });

	move.speed = 0.08f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	

}

void Enemy_GunMen::Move()
{
	
}