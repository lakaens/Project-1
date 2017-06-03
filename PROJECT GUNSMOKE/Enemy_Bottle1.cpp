#include "Application.h"
#include "Enemy_Bottle1.h"
#include "ModuleCollision.h"
#include "Path.h"
#include"ModuleInput.h"
#include "ModulePlayer.h"

Enemy_Bottle1::Enemy_Bottle1(int x, int y) : Enemy(x, y)
{
	bottle.PushBack({60,17,11,13});
	
	animation = &bottle;

	position.x = x;
	position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 11, 13 }, COLLIDER_TYPE::COLLIDER_POWERUPS, (Module*)App->enemies);

	
}

void Enemy_Bottle1::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_PLAYER) {
		App->player->score += 1000;
	}
	
}
