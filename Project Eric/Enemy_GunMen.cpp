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

	original_y = y;

}

void Enemy_GunMen::Move()
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