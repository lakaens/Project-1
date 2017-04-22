#include "Application.h"
#include "Enemy_WindowSniperLeft.h"
#include "ModuleCollision.h"

Enemy_WindowSniperLeft::Enemy_WindowSniperLeft(int x, int y) :Enemy(x, y) {

	move.PushBack({ 547,987,10,14 });
	move.PushBack({ 560,987,9,14 });
	move.PushBack({ 586,973,11,14 });
	move.PushBack({ 637,973,16,13 });
	move.PushBack({ 683,975,18,11 });
	move.PushBack({ 714,973,16,12 });
	move.PushBack({ 714,984,16,13 });
	move.PushBack({ 745,985,15,14 });


	move.speed = 0.2f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	
}

void Enemy_WindowSniperLeft::Move()
{

}