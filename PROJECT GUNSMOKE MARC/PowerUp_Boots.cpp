#include "Application.h"
#include "PowerUp_Boots.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

PowerUp_Boots::PowerUp_Boots(int x, int y) :Enemy(x, y) {


	move.PushBack({ 377, 25, 16, 16 });
	move.PushBack({ 377, 49, 16, 16 });
	move.loop = true;
	move.speed = 0.3f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,16,16 }, COLLIDER_TYPE::COLLIDER_POWERUPS, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}


void PowerUp_Boots::OnCollision(Collider* c1, Collider* c2) {

	if (c1->type == COLLIDER_POWERUPS && c2->type == COLLIDER_PLAYER) {
		App->player->speed += 1;
	}
}