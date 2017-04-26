#include "Enemy_GunMenRight.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "Application.h"

Enemy_GunMenRight::Enemy_GunMenRight(int x, int y) :Enemy(x, y) {


	horizontal.PushBack({ 337, 12, 15, 26 });
	horizontal.PushBack({ 18, 53, 15, 25 });
	horizontal.PushBack({ 57, 52, 17, 25 });
	horizontal.speed = 0.1f;

	path.PushBack({ -0.5,0.f }, 100, &horizontal);
	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_GunMenRight::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}

void Enemy_GunMenRight::Shoot() {


}