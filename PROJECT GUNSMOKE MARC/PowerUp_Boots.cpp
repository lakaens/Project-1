#include "Application.h"
#include "PowerUp_Boots.h"
#include "ModuleCollision.h"

PowerUp_Boots::PowerUp_Boots(int x, int y) :Enemy(x, y) {

	//taking the boots = +200 points
	//taking the bullets = +50 points
	//taking a bottle = +1000 points
	//taking the horse = no points
	//taking the rifle = no points

	move.PushBack({ 377, 25, 16, 16 });
	move.PushBack({ 377, 49, 16, 16 });
	move.loop = true;
	move.speed = 0.3f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,16,16 }, COLLIDER_TYPE::COLLIDER_POWERUPS, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}