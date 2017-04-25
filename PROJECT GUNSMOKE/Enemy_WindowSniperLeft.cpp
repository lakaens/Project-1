#include "Application.h"
#include "Enemy_WindowSniperLeft.h"
#include "ModuleCollision.h"

Enemy_WindowSniperLeft::Enemy_WindowSniperLeft(int x, int y) :Enemy(x, y) {

	move.PushBack({ 214,619,16,12 });
	move.PushBack({ 252,619,18,11 });
	move.PushBack({ 295,616,16,13 });
	move.PushBack({ 252,619,18,11 });
	move.speed = 0.05f;


	move.speed = 0.2f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMYBUILDING, (Module*)App->enemies);

	
}

void Enemy_WindowSniperLeft::Move()
{
	
}