#include "Application.h"
#include "Enemy_RiffleMen.h"
#include "ModuleCollision.h"

Enemy_RiffleMen::Enemy_RiffleMen(int x, int y) :Enemy(x, y) {

	move.PushBack({ 5 , 6, 24, 24 });
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

	original_y = y;
}

void Enemy_RiffleMen::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	position.y = original_y + (0.25f * sinf(wave));
	position.x -= 1;
}