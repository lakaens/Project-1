#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_GunMen.h"
#include "Enemy_Backstabber.h"
#include "Enemy_Bomber.h"
#include "Enemy_WindowSniperRight.h"
#include "Enemy_WindowSniperLeft.h"
#include "Enemy_RiffleMen.h"
#include "PowerUp_Boots.h"
#include "PowerUp_Horse.h"
#include "PowerUp_LittleBottle.h"
#include "PowerUp_BigBottle.h"
#include "PowerUp_Rifle.h"
#include "Enemy_Barrel.h"
#include "Boots_Barrel.h"
#include "BigBottle_Barrel.h"
#include "LittleBottle_Barrel.h"
#include "Horse_Barrel.h"
#include "Rifle_Barrel.h"
#include "Enemy_GunMenJumper.h"
#include "Enemy_GunMenBalcony.h"
#include "Enemy_GunMenLeft.h"
#include "Enemy_GunMenRight.h"
#include "ModulePlayer.h"

#define SPAWN_MARGIN 70

ModuleEnemies::ModuleEnemies()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("Gunsmoke/EnemySprites.png");


	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if ((queue[i].type == ENEMY_TYPES::GUNMEN)
				|| (queue[i].type == ENEMY_TYPES::BARREL)
				|| (queue[i].type == ENEMY_TYPES::BOMBER)
				|| (queue[i].type == ENEMY_TYPES::RIFFLEMEN)
				|| (queue[i].type == ENEMY_TYPES::GUNMEN)
				|| (queue[i].type == ENEMY_TYPES::GUNMENBALCONY)
				|| (queue[i].type == ENEMY_TYPES::BOOTSBARREL)
				|| (queue[i].type == ENEMY_TYPES::BIGBOTTLEBARREL)
				|| (queue[i].type == ENEMY_TYPES::LITTLEBOTTLEBARREL)
				|| (queue[i].type == ENEMY_TYPES::HORSEBARREL)
				|| (queue[i].type == ENEMY_TYPES::RIFLEBARREL))
			{
				if (queue[i].y > (abs(App->render->camera.y) / SCREEN_SIZE) - SPAWN_MARGIN)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			if ((queue[i].type == ENEMY_TYPES::BOOTS)
				|| (queue[i].type == ENEMY_TYPES::HORSE)
				|| (queue[i].type == ENEMY_TYPES::BIGBOTTLE)
				|| (queue[i].type == ENEMY_TYPES::LITTLEBOTTLE)
				|| (queue[i].type == ENEMY_TYPES::RIFLE))
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
			}
			/*if (queue[i].type == ENEMY_TYPES::BOOTS) {
				if (boots)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			if (queue[i].type == ENEMY_TYPES::RIFLE) {
				if (rifle)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			if (queue[i].type == ENEMY_TYPES::BIGBOTTLE) {
				if (bigbottle)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			if (queue[i].type == ENEMY_TYPES::LITTLEBOTTLE) {
				if (littlebottle)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			if (queue[i].type == ENEMY_TYPES::HORSE) {
				if (bhorse)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}*/
			if ((queue[i].type == ENEMY_TYPES::BACKSTABBER)
				|| (queue[i].type == ENEMY_TYPES::GUNMENJUMPER)
				|| (queue[i].type == ENEMY_TYPES::GUNMENLEFT)
				|| (queue[i].type == ENEMY_TYPES::GUNMENRIGHT))
			{
				if (queue[i].y > (abs(App->render->camera.y) / SCREEN_SIZE) + 70)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			if ((queue[i].type == ENEMY_TYPES::WINDOWSNIPERLEFT)
				|| (queue[i].type == ENEMY_TYPES::WINDOWSNIPERRIGHT))
			{
				if (queue[i].y > (abs(App->render->camera.y) / SCREEN_SIZE) + 20)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		if(enemies[i] != nullptr) enemies[i]->Move();

	for(uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) {
			enemies[i]->Draw(sprites);
			enemies[i]->Shoot(); 
		
		}

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			if (enemies[i]->position.y>((abs(App->render->camera.y) + SCREEN_WIDTH) / SCREEN_SIZE) + 240)
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			/*if (type == ENEMY_TYPES::BOOTS) {
				if (boots) {
					queue[i].type = type;
					queue[i].x = x;
					queue[i].y = y;
					ret = true;
					break;
				}
			}
			else {*/
				queue[i].type = type;
				queue[i].x = x;
				queue[i].y = y;
				ret = true;
				break;
			/*}*/
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	

	uint i = 0;
	for(; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if(i != MAX_ENEMIES)
	{
		switch(info.type)
		{
			case ENEMY_TYPES::GUNMEN:
				enemies[i] = new Enemy_GunMen(info.x,info.y);
				enemies[i]->type = ENEMY_TYPES::GUNMEN;
				break;
			case ENEMY_TYPES::BACKSTABBER:
				enemies[i] = new Enemy_BackStabber(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::BACKSTABBER;
				break;
			case ENEMY_TYPES::WINDOWSNIPERLEFT:
				enemies[i] = new Enemy_WindowSniperLeft(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::WINDOWSNIPERLEFT;
				break;
			case ENEMY_TYPES::WINDOWSNIPERRIGHT:
				enemies[i] = new Enemy_WindowSniperRight(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::WINDOWSNIPERRIGHT;
				break;
			case ENEMY_TYPES::BOMBER:
				enemies[i] = new Enemy_Bomber(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::BOMBER;
				break;
			case ENEMY_TYPES::RIFFLEMEN:
				enemies[i] = new Enemy_RiffleMen(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::RIFFLEMEN;
				break;
			case ENEMY_TYPES::BARREL:
				enemies[i] = new Enemy_Barrel(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::BARREL;
				break;
			case ENEMY_TYPES::BOOTSBARREL:
				enemies[i] = new Enemy_Barrel(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::BOOTSBARREL;
				break;
			case ENEMY_TYPES::BIGBOTTLEBARREL:
				enemies[i] = new Enemy_Barrel(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::BIGBOTTLEBARREL;
				break;
			case ENEMY_TYPES::LITTLEBOTTLEBARREL:
				enemies[i] = new Enemy_Barrel(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::LITTLEBOTTLEBARREL;
				break;
			case ENEMY_TYPES::HORSEBARREL:
				enemies[i] = new Enemy_Barrel(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::HORSEBARREL;
				break;
			case ENEMY_TYPES::RIFLEBARREL:
				enemies[i] = new Enemy_Barrel(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::RIFLEBARREL;
				break;
			case ENEMY_TYPES::GUNMENJUMPER:
				enemies[i] = new Enemy_GunMenJumper(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::GUNMENJUMPER;
				break;
			case ENEMY_TYPES::GUNMENBALCONY:
				enemies[i] = new Enemy_GunMenBalcony(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::GUNMENBALCONY;
				break;
			case ENEMY_TYPES::GUNMENLEFT:
				enemies[i] = new Enemy_GunMenBalcony(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::GUNMENLEFT;
				break;
			case ENEMY_TYPES::GUNMENRIGHT:
				enemies[i] = new Enemy_GunMenBalcony(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::GUNMENRIGHT;
				break;
			/*
			case ENEMY_TYPES::BOOTS:
			if (boots) {
			enemies[i] = new PowerUp_Boots(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BOOTS;
			}
			break;
			case ENEMY_TYPES::HORSE:
			if (bhorse) {
			enemies[i] = new PowerUp_Horse(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::HORSE;
			}
			break;
			case ENEMY_TYPES::BIGBOTTLE:
			if (bigbottle) {
			enemies[i] = new BigBottle(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BIGBOTTLE;
			}
			break;
			case ENEMY_TYPES::LITTLEBOTTLE:
			if (littlebottle) {
			enemies[i] = new LittleBottle(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::LITTLEBOTTLE;
			}
			break;
			case ENEMY_TYPES::RIFLE:
			if (rifle) {
			enemies[i] = new PowerUp_Rifle(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::RIFLE;
			}
			break;
			*/
			case ENEMY_TYPES::BOOTS:
				
					enemies[i] = new PowerUp_Boots(info.x, info.y);
					enemies[i]->type = ENEMY_TYPES::BOOTS;
				
				break;
			case ENEMY_TYPES::HORSE:
				
					enemies[i] = new PowerUp_Horse(info.x, info.y);
					enemies[i]->type = ENEMY_TYPES::HORSE;
				
				break;
			case ENEMY_TYPES::BIGBOTTLE:
				
					enemies[i] = new BigBottle(info.x, info.y);
					enemies[i]->type = ENEMY_TYPES::BIGBOTTLE;
				
				break;
			case ENEMY_TYPES::LITTLEBOTTLE:
				
					enemies[i] = new LittleBottle(info.x, info.y);
					enemies[i]->type = ENEMY_TYPES::LITTLEBOTTLE;
				
				break;
			case ENEMY_TYPES::RIFLE:
				
					enemies[i] = new PowerUp_Rifle(info.x, info.y);
					enemies[i]->type = ENEMY_TYPES::RIFLE;
				
				break;

		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			
			enemies[i]->OnCollision(c2);
			if ((enemies[i]->type == ENEMY_TYPES::GUNMEN)
				|| (enemies[i]->type == ENEMY_TYPES::GUNMENJUMPER)
				|| (enemies[i]->type == ENEMY_TYPES::GUNMENLEFT)
				|| (enemies[i]->type == ENEMY_TYPES::GUNMENRIGHT)
				|| (enemies[i]->type == ENEMY_TYPES::GUNMENBALCONY))
			{
				if (c2->type == COLLIDER_PLAYER_SHOT) {
					App->player->score += 200;
					App->particles->AddParticle(App->particles->deadGunMen, c1->rect.x, c1->rect.y, COLLIDER_NONE);

					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type==ENEMY_TYPES::WINDOWSNIPERRIGHT) 
			{
				if (c2->type == COLLIDER_PLAYER_SHOT) {
					App->player->score += 500;
					App->particles->AddParticle(App->particles->deadWindowSniperRight, c1->rect.x, c1->rect.y, COLLIDER_NONE);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if(enemies[i]->type == ENEMY_TYPES::BOMBER)
			{
				if (c2->type == COLLIDER_PLAYER_SHOT) {
					App->player->score += 300;
					App->particles->AddParticle(App->particles->deadBomber, c1->rect.x, c1->rect.y, COLLIDER_NONE);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::WINDOWSNIPERLEFT)
			{
				if (c2->type == COLLIDER_PLAYER_SHOT) {
					App->player->score += 500;
					App->particles->AddParticle(App->particles->deadWindowSniperLeft, c1->rect.x, c1->rect.y, COLLIDER_NONE);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::BACKSTABBER)
			{
				if (c2->type == COLLIDER_PLAYER_SHOT) {
					App->player->score += 800;
					App->particles->AddParticle(App->particles->deadBackStabber, c1->rect.x, c1->rect.y, COLLIDER_NONE);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::RIFFLEMEN) 
			{
				if (c2->type == COLLIDER_PLAYER_SHOT) {
					App->player->score += 400;
					App->particles->AddParticle(App->particles->deadRiffleMen, c1->rect.x, c1->rect.y, COLLIDER_NONE);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::BARREL
				|| enemies[i]->type == ENEMY_TYPES::BOOTSBARREL
				|| enemies[i]->type == ENEMY_TYPES::BIGBOTTLEBARREL
				|| enemies[i]->type == ENEMY_TYPES::LITTLEBOTTLEBARREL
				|| enemies[i]->type == ENEMY_TYPES::RIFLEBARREL
				|| enemies[i]->type == ENEMY_TYPES::HORSEBARREL)
			{
				if (c2->type == COLLIDER_PLAYER_SHOT) {
					--enemies[i]->life;
					if (enemies[i]->life == 0) {
						App->player->score += 50;
						App->particles->AddParticle(App->particles->deadBarrel, c1->rect.x, c1->rect.y, COLLIDER_NONE);
						/*switch (enemies[i]->type)
						{
						case ENEMY_TYPES::BARREL:
							break;
						case ENEMY_TYPES::BOOTSBARREL:
							this->AddEnemy(ENEMY_TYPES::BOOTS, c1->rect.x, c1->rect.y);
							break;
						case ENEMY_TYPES::BIGBOTTLEBARREL:
							this->AddEnemy(ENEMY_TYPES::BIGBOTTLE, c1->rect.x, c1->rect.y);
							break;
						case ENEMY_TYPES::LITTLEBOTTLEBARREL:
							this->AddEnemy(ENEMY_TYPES::LITTLEBOTTLE, c1->rect.x, c1->rect.y);
							break;
						case ENEMY_TYPES::RIFLEBARREL:
							this->AddEnemy(ENEMY_TYPES::RIFLE, c1->rect.x, c1->rect.y);
							break;
						case ENEMY_TYPES::HORSEBARREL:
							this->AddEnemy(ENEMY_TYPES::HORSE, c1->rect.x, c1->rect.y);
							break;
						}
						*/
						delete enemies[i];
						enemies[i] = nullptr;
						
					}
				}
			}
			//bottle=1000 points
			//riffle=reach
			
			if (enemies[i]->type == ENEMY_TYPES::BOOTS){
				if (c2->type == COLLIDER_PLAYER) {
					App->player->speed += 0.3;
					delete enemies[i];
					enemies[i] = nullptr;
				}
				break;
			}
			if (enemies[i]->type == ENEMY_TYPES::HORSE) {
				if (c2->type == COLLIDER_PLAYER) {
					horse = true;
					delete enemies[i];
					enemies[i] = nullptr;
				}
				break;
			}
			if (enemies[i]->type == ENEMY_TYPES::RIFLE) {
				if (c2->type == COLLIDER_PLAYER) {
					App->particles->bulletl.life += 75;
					App->particles->bulletr.life += 75;
					App->particles->bulletu.life += 75;
					delete enemies[i];
					enemies[i] = nullptr;
				}
				break;
			}
			if (enemies[i]->type == ENEMY_TYPES::BIGBOTTLE) {
				if (c2->type == COLLIDER_PLAYER) {
					App->player->score += 1000;
					delete enemies[i];
					enemies[i] = nullptr;
				}
				break;
			}
			if (enemies[i]->type == ENEMY_TYPES::LITTLEBOTTLE) {
				if (c2->type == COLLIDER_PLAYER) {
					App->player->score += 1000;
					delete enemies[i];
					enemies[i] = nullptr;
				}
				break;
			}
		}
		if ((c2->type == COLLIDER_WALL || c2->type == COLLIDER_BARREL) && enemies[i] != nullptr && c1->CheckCollision(c2->rect) == true && enemies[i]->GetCollider() == c1)
		{
			if (c1->rect.y<c2->rect.y + c2->rect.h && c1->rect.y + 3>c2->rect.y + c2->rect.h) {

				enemies[i]->position.y = enemies[i]->position.y + 1;
			}



			else if (c1->rect.y + c1->rect.h > c2->rect.y && c1->rect.y + c1->rect.h - 3< c2->rect.y)

			{
				enemies[i]->position.y = enemies[i]->position.y - 1;

			}


			else if (c1->rect.x + c1->rect.w > c2->rect.x && c1->rect.x + c1->rect.w - 3 < c2->rect.x)
			{
				enemies[i]->position.x = enemies[i]->position.x - 1;

			}
			else if (c1->rect.x < c2->rect.x + c2->rect.w && c1->rect.x + 3 > c2->rect.x + c2->rect.w)
			{
				enemies[i]->position.x = enemies[i]->position.x + 1;

			}

		}
	}
}