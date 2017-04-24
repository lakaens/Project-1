#include "Application.h"
#include "Enemy_WindowSniperRight.h"
#include "ModuleCollision.h"

Enemy_WindowSniperRight::Enemy_WindowSniperRight(int x, int y) :Enemy(x, y) {

	move.PushBack({ 536,931,10,13 });
	move.PushBack({ 568,942,11,13 });
	move.PushBack({ 585,941,11,14 });
	move.PushBack({ 612,940,13,14 });
	move.PushBack({ 639,940,16,13 });
	move.PushBack({ 667,929,18,11 });
	move.PushBack({ 702,941,15,12 });
	move.PushBack({ 733,941,15,14 });

	move.speed = 0.2f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


}

void Enemy_WindowSniperRight::Move()
{
	
}