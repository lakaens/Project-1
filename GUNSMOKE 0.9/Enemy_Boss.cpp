#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL_timer.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"

#define PI 3.14159265
#define ENEMY_SHOOTING_SPEED 1000
#define ENEMY_SHOT_SPEED 3.0f

Enemy_Boss::Enemy_Boss(int x, int y) :Enemy(x, y) {

	down.PushBack({ 562,52,24,29 });
	down.PushBack({ 602,51,20,31 });
	down.PushBack({ 643,52,23,30 });
	down.PushBack({ 602,51,20,31 });
	down.PushBack({ 562,52,24,29 });
	down.speed = 0.07f;

	stay.PushBack({ 685,52,18,30 });
	stay.speed = 0.f;

	up.PushBack({ 884,51,20,31 });
	up.PushBack({ 601,95,26,24 });
	up.PushBack({ 644,93,20,21 });
	up.PushBack({ 681,91,26,13 });
	up.PushBack({ 725,90,18,23 });
	up.PushBack({ 762,95,24,20 });
	//up.PushBack({ 798,93,31,23 });
	//up.PushBack({ 842,91,24,31 });
	up.speed = 0.07f;


	/*diagonal.PushBack({ 962,50,23,29 });*/
	diagonal.PushBack({ 518,90,32,26 });
	diagonal.speed = 0.02f;

	path.PushBack({ 0.f,0.5f }, 100, &down);
	path.PushBack({ 0.f,0.f }, 40, &stay);
	path.PushBack({ 0.f,-0.5f }, 100, &up);
	path.PushBack({ 0.f,0.f }, 40, &stay);
	path.PushBack({ 1.0f,0.5f }, 100, &diagonal);
	path.PushBack({ 0.f,0.f }, 40, &stay);
	path.PushBack({ 0.f,-0.5f }, 100, &up);
	path.PushBack({ 0.f,0.f }, 40, &stay);
	path.PushBack({ -1.0f,0.5f }, 100, &diagonal);
	path.PushBack({ 0.f,0.f }, 40, &stay);
	path.PushBack({ 0.f,-0.5f }, 100, &up);

	collider = App->collision->AddCollider({ 0,0,18,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;


	bosslife = 12;
}

void Enemy_Boss::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}

void Enemy_Boss::Shoot()
{
	uint currentTime = SDL_GetTicks();
	float angle;
	speed.x = (App->player->position.x) - position.x;
	speed.y = (App->player->position.y) - (position.y);
	h = sqrt((pow(speed.x, 2) + pow(speed.y, 2)));



	if ((currentTime > (lastTime + ENEMY_SHOOTING_SPEED)) && speed.y<125) {

		App->particles->knife.speed.x = (speed.x / h)*ENEMY_SHOT_SPEED;
		App->particles->knife.speed.y = (speed.y / h)*ENEMY_SHOT_SPEED;


		App->particles->AddParticle(App->particles->knife, position.x, position.y, COLLIDER_ENEMY_SHOT);
		

		lastTime = currentTime;
	}

}