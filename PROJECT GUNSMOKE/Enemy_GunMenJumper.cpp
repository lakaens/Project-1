#include "Application.h"
#include "Enemy_GunMenJumper.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

Enemy_GunMenJumper::Enemy_GunMenJumper(int x, int y) :Enemy(x, y) {

	horizontal.PushBack({ 92, 132, 22, 28 });//horizontal
	stay.PushBack({ 93, 51, 21, 29 });//stay
	diagonaldown.PushBack({ 132, 132, 25, 28 });//diagonaldown
	move.PushBack({ 214, 51, 20, 28 });
	move.PushBack({ 254, 53, 20, 28 });
	move.PushBack({ 294, 51, 20, 28 });
	horizontal.speed = 0.f;
	stay.speed = 0.f;
	diagonaldown.speed = 0.f;
	move.speed = 0.2f;

	path.PushBack({ 1.3f,0.f }, 45, &horizontal);
	path.PushBack({ 1.f,1.f }, 35, &diagonaldown);
	path.PushBack({ 0.f,0.f }, 20, &stay);
	path.PushBack({ 0.f,0.5f }, 200, &move);



	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_GunMenJumper::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}

void Enemy_GunMenJumper::Shoot() {


}