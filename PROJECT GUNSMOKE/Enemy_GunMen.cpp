#include "Application.h"
#include "Enemy_GunMen.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_timer.h"

#define PI 3.14159265
#define to_degrees (180.0 / PI)

Enemy_GunMen::Enemy_GunMen(int x, int y) :Enemy(x, y) {

	down.PushBack({ 214, 51, 20, 28 });
	down.PushBack({ 254, 53, 20, 28 });
	down.PushBack({ 294, 51, 20, 28 });
	down.speed = 0.2f;

	right.PushBack({ 337, 12, 15, 26 });
	right.PushBack({ 18, 53, 15, 25 });
	right.PushBack({ 57, 52, 17, 25 });
	right.speed = 0.2f;

	left.PushBack({ 93, 92, 18, 25 });
	left.PushBack({ 132, 93, 19, 26 });
	left.PushBack({ 171, 92, 22, 25 });
	left.speed = 0.2f;

	upright.PushBack({ 97, 13, 18, 25 });
	upright.PushBack({ 136, 12, 20, 27 });
	upright.PushBack({ 258, 13, 17, 27 });
	upright.PushBack({ 297, 12, 19, 27 });
	upright.speed = 0.2f;

	upleft.PushBack({ 215, 92, 17, 27 });
	upleft.PushBack({ 258, 93, 14, 27 });
	upleft.PushBack({ 298, 92, 14, 27 });
	upleft.speed = 0.2f;

	downright.PushBack({ 94, 52, 19, 27 });
	downright.PushBack({ 135, 53, 17, 26 });
	downright.PushBack({ 176, 52, 16, 26 });
	downright.speed = 0.2f;

	downleft.PushBack({ 331, 52, 21, 26 });
	downleft.PushBack({ 11, 93, 22, 27 });
	downleft.PushBack({ 51, 92, 24, 27 });
	downleft.speed = 0.2f;

	animation = &down;


	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_GunMen::Move()
{
	float h = sqrt(pow(2, (App->player->position.x - position.x)) + (pow(2, (App->player->position.y - position.y))));
	float angle;
	speed.x = App->player->position.x - position.x;
	speed.y = App->player->position.y - position.y;

	angle *= to_degrees;

	if (speed.x != 0) {
		angle = atan2(speed.y, speed.x);
	}
	else {
		angle = atan2(speed.y, speed.x + 1);
	}
	if (angle <= 25 && angle < -25) {
		animation = &right;
	}
	else if (angle <= 75 && angle > 25) {
		animation = &downright;
	}
	else if (angle <= 105 && angle > 75) {
		animation = &down;
	}
	else if (angle <= 155 && angle > 105) {
		animation = &downleft;
	}
	else if (angle <= -155 && angle > 155) {
		animation = &left;
	}
	else if (angle <= -90 && angle > -155) {
		animation = &upleft;
	}
	else if (angle <= -25 && angle > -90) {
		animation = &upright;
	}

	uint Time = SDL_GetTicks();

	if (abs(App->player->position.y - position.y) < 300) {
		gate[0] = true;
	}
	if (gate[3] == true) {
		position.x--;
		position.y--;
		if (Time - (reseTime*repetitions) > (TimeUp + pathdelay)) {
			reseTime = 13000;
			repetitions++;
			for (int i = 0; i < 4; i++) {
				gate[i]=false;
			}
		}
	}
	else if (gate[2] == true) {
		position.y++;
		if (Time - (reseTime*repetitions) > (TimeUp + pathdelay)) {
			pathdelay += 3000;
			gate[3] = true;
		}
	}
	else if (gate[1] == true) {
		position.x++;
		position.y--;
		if (Time - (reseTime*repetitions) > (TimeUp + pathdelay)) {
			pathdelay += 3000;
			gate[2] = true;
		}
	}
	else if (gate[0] == true) {
		position.y++;
		pathdelay = 4000;
		if (Time - (reseTime*repetitions) > (TimeUp + pathdelay)) {
			pathdelay += 3000;
			gate[1] = true;
		}
	}
	if (position.x >= 200) {
		position.x--;
	}
	if (position.x <= 5) {
		position.x++;
	}
}

void Enemy_GunMen::Shoot() {

	App->particles->AddParticle(App->particles->enemysimplebullet, SCREEN_WIDTH / 2, 2700, COLLIDER_ENEMY_SHOT);

}
