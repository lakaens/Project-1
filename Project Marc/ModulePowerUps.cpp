#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePowerUps.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "PowerUp.h"
#include "PowerUp_Boots.h"
#include "PowerUp_Horse.h"
#include "PowerUp_Pow.h"
#include "PowerUp_Shotgun.h"


#define SPAWN_MARGIN 50

ModulePowerUps::ModulePowerUps()
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
		powerups[i] = nullptr;
}

// Destructor
ModulePowerUps::~ModulePowerUps()
{
}

bool ModulePowerUps::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	Powerups = App->textures->Load("particles1.png");

	return true;
}

update_status ModulePowerUps::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type != POWERUP_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnPowerUp(queue[i]);
				queue[i].type = POWERUP_TYPES::NO_TYPE;
				LOG("Spawning powerup at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModulePowerUps::Update()
{

	for (uint i = 0; i < MAX_POWERUPS; ++i) {
		if (powerups[i] != nullptr) {
			powerups[i]->Draw(Powerups);

		}
	}

	return UPDATE_CONTINUE;
}

update_status ModulePowerUps::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerups[i] != nullptr)
		{
			if (powerups[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning powerup at %d", powerups[i]->position.x * SCREEN_SIZE);
				delete powerups[i];
				powerups[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePowerUps::CleanUp()
{
	LOG("Freeing all powerups");

	App->textures->Unload(Powerups);


	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerups[i] != nullptr)
		{
			delete powerups[i];
			powerups[i] = nullptr;
		}
	}

	return true;
}

bool ModulePowerUps::AddPowerUp(POWERUP_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type == POWERUP_TYPES::NO_TYPE)
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

void ModulePowerUps::SpawnPowerUp(const PowerUpInfo& info)
{
	// find room for the new enemy

	for (uint i = 0; powerups[i] != nullptr && i < MAX_POWERUPS; ++i) {
		if (i != MAX_POWERUPS)
		{
			switch (info.type)
			{
			case POWERUP_TYPES::BOOTS:
				powerups[i] = new PowerUp_Boots(info.x, info.y);
				break;
			case POWERUP_TYPES::HORSE:
				powerups[i] = new PowerUp_Horse(info.x, info.y);
				break;
			case POWERUP_TYPES::POW:
				powerups[i] = new PowerUp_Pow(info.x, info.y);
				break;
			case POWERUP_TYPES::SHOTGUN:
				powerups[i] = new PowerUp_Shotgun(info.x, info.y);
				break;
		}
	}
}