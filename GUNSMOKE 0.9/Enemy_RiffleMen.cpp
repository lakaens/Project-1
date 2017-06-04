#include "Application.h"
#include "Enemy_RiffleMen.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

#define ENEMY_SHOOTING_SPEED 3000
#define ENEMY_SHOT_SPEED 3.0f

Enemy_RiffleMen::Enemy_RiffleMen(int x, int y) :Enemy(x, y) {

	move.PushBack({ 175,212,16,27 });
	move.PushBack({ 215, 213, 16, 27 });
	move.PushBack({ 255, 212, 17, 27 });
	move.loop = true;
	move.speed = 0.2f;

	sides.PushBack({ 294, 213, 17, 27 });
	sides.PushBack({ 215, 213, 16, 27 });
	sides.PushBack({ 334, 213, 18, 27 });
	sides.loop = true;
	sides.speed = 0.07f;

	path.PushBack({ 0.f,0.5f }, 75, &move);
	path.PushBack({ 0.f,0.f }, 500, &sides);

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
	
}

void Enemy_RiffleMen::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}

void Enemy_RiffleMen::Shoot()
{
	uint currentTime = SDL_GetTicks();
	float angle;
	speed.x = (App->player->position.x) - position.x;
	speed.y = (App->player->position.y) - (position.y);
	h = sqrt((pow(speed.x, 2) + pow(speed.y, 2)));



	if ((currentTime > (lastTime + ENEMY_SHOOTING_SPEED)) && speed.y<125) {

		App->particles->enemysimplebullet.speed.x = (speed.x / h)*ENEMY_SHOT_SPEED;
		App->particles->enemysimplebullet.speed.y = (speed.y / h)*ENEMY_SHOT_SPEED;


		App->particles->AddParticle(App->particles->enemysimplebullet, position.x + 3, position.y + 3, COLLIDER_ENEMY_SHOT);


		lastTime = currentTime;
	}

}