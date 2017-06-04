#include "Application.h"
#include "Enemy_Bomber.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#define ENEMY_SHOOTING_SPEED 5000
#define ENEMY_SHOT_SPEED 1.5f


Enemy_Bomber::Enemy_Bomber(int x, int y) :Enemy(x, y) {

	move.PushBack({ 333,130,23,28 });
	move.PushBack({ 374, 129, 20, 30 });
	move.PushBack({ 412, 130, 22, 28 });
	move.speed = 0.05f;
	stay.PushBack({ 333,130,23,28 });
	stay.PushBack({ 374, 129, 20, 30 });
	stay.PushBack({ 412, 130, 22, 28 });
	move.speed = 0.05f;
	stay.speed = 0.05f;
	path.PushBack({ 0.f,0.5f }, 50, &move);
	path.PushBack({ 0.f,0.f }, 250, &stay);



	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_Bomber::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}

void Enemy_Bomber::Shoot() {
	uint currentTime = SDL_GetTicks();
	float angle;
	speed.x = (App->player->position.x) - position.x;
	speed.y = (App->player->position.y) - (position.y);
	h = sqrt((pow(speed.x, 2) + pow(speed.y, 2)));



	if ((currentTime > (lastTime + ENEMY_SHOOTING_SPEED)) && speed.y<125) {

		App->particles->bomb.speed.x = (speed.x / h)*ENEMY_SHOT_SPEED;
		App->particles->bomb.speed.y = (speed.y / h)*ENEMY_SHOT_SPEED;


		App->particles->AddParticle(App->particles->bomb, position.x + 3, position.y + 3, COLLIDER_ENEMY_SHOT);


		lastTime = currentTime;
	}
	App->enemies->bomb = true;
}