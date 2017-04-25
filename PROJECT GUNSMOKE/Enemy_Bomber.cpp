#include "Application.h"
#include "Enemy_Bomber.h"
#include "ModuleCollision.h"

Enemy_Bomber::Enemy_Bomber(int x, int y) :Enemy(x, y) {

	move.PushBack({ 333,130,23,28 });
	move.PushBack({ 374, 129, 20, 30 });
	move.PushBack({ 412, 130, 22, 28 });
	move.speed = 0.05f;

	path.PushBack({ 0.f,0.5f }, 10);
	
	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_Bomber::Move()
{
	position = original_pos + path.GetCurrentSpeed();
}