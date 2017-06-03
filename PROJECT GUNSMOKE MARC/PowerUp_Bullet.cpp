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

	collider = App->collision->AddCollider({ 0,0,16,15 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}