#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"

Enemy_Boss::Enemy_Boss(int x, int y) :Enemy(x, y) {

	down.PushBack({ 562,52,24,29 });
	down.PushBack({ 602,51,20,31 });
	down.PushBack({ 643,52,23,30 });
	down.PushBack({ 602,51,20,31 });
	down.PushBack({ 562,52,24,29 });
	down.speed = 0.5f;

	stay.PushBack({ 685,52,18,30 });
	stay.speed = 0.f;

	up.PushBack({ 884,51,20,31 });
	up.PushBack({ 601,95,26,24 });
	up.PushBack({ 644,93,20,21 });
	up.PushBack({ 681,91,26,13 });
	up.PushBack({ 725,90,18,23 });
	up.PushBack({ 762,95,24,20 });
	up.PushBack({ 798,93,31,23 });
	up.PushBack({ 842,91,24,31 });
	up.speed = 0.5f;

	diagonal.PushBack({ 925,55,21,25 });
	diagonal.PushBack({ 962,50,23,29 });
	diagonal.PushBack({ 518,90,32,26 });
	diagonal.PushBack({ 566,91,17,31 });
	diagonal.speed = 0.5f;

	

	collider = App->collision->AddCollider({ 0,0,18,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_Boss::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}