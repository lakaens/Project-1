#include "Application.h"
#include "Enemy_Bomber.h"
#include "ModuleCollision.h"

Enemy_Bomber::Enemy_Bomber(int x, int y) :Enemy(x, y) {

	move.PushBack({ 848,349,24,30 });
	move.PushBack({ 889, 348, 22, 32 });
	move.PushBack({ 928,349 , 23, 30 });
	move.PushBack({ 971, 348, 21, 32 });

	move.speed = 0.05f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	
}

void Enemy_Bomber::Move()
{

}