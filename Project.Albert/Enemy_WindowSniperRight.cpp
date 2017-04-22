#include "Application.h"
#include "Enemy_WindowSniperRight.h"
#include "ModuleCollision.h"

Enemy_WindowSniperRight::Enemy_WindowSniperRight(int x, int y) :Enemy(x, y) {

	move.PushBack({ 537,931,8,12 });
	move.PushBack({ 559,931,8,12 });
	move.PushBack({ 586,929,9,12 });
	move.PushBack({ 613,928,11,12 });
	move.PushBack({ 640,929,14,11 });
	move.PushBack({ 668,930,16,9 });
	move.PushBack({ 702,931,14,10 });
	move.PushBack({ 734,929,13,12 });

	move.speed = 0.05f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	
}

void Enemy_WindowSniperRight::Move()
{
	
}