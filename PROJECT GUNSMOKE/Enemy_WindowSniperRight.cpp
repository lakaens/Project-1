#include "Application.h"
#include "Enemy_WindowSniperRight.h"
#include "ModuleCollision.h"

Enemy_WindowSniperRight::Enemy_WindowSniperRight(int x, int y) :Enemy(x, y) {

	move.PushBack({ 176,553,14,11 });
	move.PushBack({ 216,556,16,9 });
	move.PushBack({ 256,556,14,10 });
	move.PushBack({ 216,556,16,9 });
	move.speed = 0.05f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMYBUILDING, (Module*)App->enemies);


	original_pos.x = x;
	original_pos.y = y;


}

void Enemy_WindowSniperRight::Move()
{
	position = original_pos + path.GetCurrentSpeed();
}