#include "Application.h"
#include "Enemy_GunMenLeft.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

Enemy_GunMenLeft::Enemy_GunMenLeft(int x, int y) :Enemy(x, y) {

	horizontal.PushBack({ 217,12,17,18 });
	horizontal.PushBack({ 17,52,17,27 });
	horizontal.PushBack({ 56,51,19,27 });
	horizontal.speed = 0.1f;

	path.PushBack({ 0.5,0.f }, 100, &horizontal);
	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_GunMenLeft::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}

void Enemy_GunMenLeft::Shoot() {


}