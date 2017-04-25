#include "Application.h"
#include "Enemy_GunMen.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

Enemy_GunMen::Enemy_GunMen(int x, int y) :Enemy(x, y) {

	move.PushBack({ 214, 51, 20, 28 });
	move.PushBack({ 254, 53, 20, 28 });
	move.PushBack({ 294, 51, 20, 28 });
	move.speed = 0.2f;

	path.PushBack({ 0.f,0.5f },100);
	animation = &move;


	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_GunMen::Move()
{
	position = original_pos + path.GetCurrentSpeed();
}

void Enemy_GunMen::Shoot() {


}
