#include "Application.h"
#include "PowerUp_Bullet.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"

PowerUp_Bullet::PowerUp_Bullet(int x, int y) :Enemy(x, y) {


	move.PushBack({ 417, 26, 16, 15 });
	move.PushBack({ 417, 50, 16, 15 });
	move.loop = true;
	move.speed = 0.3f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,16,15 }, COLLIDER_TYPE::COLLIDER_POWERUPS, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}


void PowerUp_Bullet::OnCollision(Collider* c1, Collider* c2) {

	if (c1->type == COLLIDER_POWERUPS && c2->type == COLLIDER_PLAYER) {
		App->player->score += 50;
		App->particles->bulletl.speed.y += 1;
		App->particles->bulletl.speed.x += 1;
		App->particles->bulletr.speed.y += 1;
		App->particles->bulletl.speed.x += 1;
		App->particles->bulletu.speed.y += 1;
	}
}