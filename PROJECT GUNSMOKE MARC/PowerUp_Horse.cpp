#include "Application.h"
#include "PowerUp_Horse.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"

PowerUp_Horse::PowerUp_Horse(int x, int y) :Enemy(x, y) {


	move.PushBack({ 20, 17, 16, 16 });
	move.loop = false;
	move.speed = 0.3f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,16,16 }, COLLIDER_TYPE::COLLIDER_POWERUPS, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}


void PowerUp_Horse::OnCollision(Collider* c1, Collider* c2) {

}