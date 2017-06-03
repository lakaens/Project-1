#include "Application.h"
#include "PowerUp_Horse.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

PowerUp_Horse::PowerUp_Horse(int x, int y) :Enemy(x, y) {


	move.PushBack({ 20, 17, 16, 16 });


	animation = &move;

	collider = App->collision->AddCollider({ 0,0,16,16 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

