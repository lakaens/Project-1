#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_GunMen.h"
#include "Enemy_WindowSniperRight.h"
#include "Enemy_WindowSniperLeft.h"
#include "Enemy_Bomber.h"
#include "Enemy_RiffleMen.h"
#include "Enemy_BackStabber.h"


#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	EnemySprites = App->textures->Load("EnemySprites.png");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] != nullptr) {
			enemies[i]->Draw(EnemySprites);
		
		}
	}

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
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

	App->textures->Unload(EnemySprites);


	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
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

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::GUNMEN:
			enemies[i] = new Enemy_GunMen(info.x, info.y);
			break;
		case ENEMY_TYPES::WINDOWSNIPERLEFT:
			enemies[i] = new Enemy_WindowSniperLeft(info.x, info.y);
			break;
		case ENEMY_TYPES::WINDOWSNIPERRIGHT:
			enemies[i] = new Enemy_WindowSniperRight(info.x, info.y);
			break;
		case ENEMY_TYPES::BOMBER:
			enemies[i] = new Enemy_Bomber(info.x, info.y);
			break;
		case ENEMY_TYPES::RIFFLEMEN:
			enemies[i] = new Enemy_RiffleMen(info.x, info.y);
			break;
		case ENEMY_TYPES::BACKSTABBER:
			enemies[i] = new Enemy_BackStabber(info.x, info.y);
			break;
		
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_PLAYER_SHOT) {
		
	}
}