#include "Application.h"
#include "Enemy_Brown_Cookie.h"
#include "ModuleCollision.h"
#include "Path.h"

Enemy_Brown_Cookie::Enemy_Brown_Cookie(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 5,72,21,22 });

	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalPosition.x = x;
	originalPosition.y = y;

	path.PushBack({ -1.0f, -0.75f }, 100, &fly);
	path.PushBack({-1.0f,0.75f}, 150, &fly);
}

void Enemy_Brown_Cookie::Move()
{
	
	position = originalPosition + path.GetCurrentPosition();
	
}