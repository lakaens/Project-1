#include "Application.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleBarrel.h"
#include "Barrel.h"


ModuleBarrel::ModuleBarrel()
{
}

ModuleBarrel::~ModuleBarrel()
{
}

bool ModuleBarrel::Start()
{
	text = App->textures->Load("rtype/barrel.png");
	return true;
}

update_status ModuleBarrel::PreUpdate()
{
	for (uint i = 0; i < MAX_BARRELS; ++i)
	{
		if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
		{
			SpawnBarrel(queue[i]);
			LOG("Spawning Barrel at %d", queue[i].x * SCREEN_SIZE);
		}
	}

	return UPDATE_CONTINUE;
}

update_status ModuleBarrel::Update()
{
	for (uint i = 0; i < MAX_BARRELS; ++i) {
		if (barrels[i] != nullptr) {
			barrels[i]->Draw(text);
		}
	}



	return UPDATE_CONTINUE;
}

update_status ModuleBarrel::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_BARRELS; ++i)
	{
		if (barrels[i] != nullptr)
		{
			if (barrels[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", barrels[i]->position.x * SCREEN_SIZE);
				delete barrels[i];
				barrels[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

bool ModuleBarrel::AddBarrel(int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_BARRELS; ++i)
	{
		queue[i].x = x;
		queue[i].y = y;
		ret = true;
		break;
	}
	return ret;
}

void ModuleBarrel::SpawnBarrel(const BarrelInfo& info)
{
	// find room for the new enemy
	uint i;
	for (i = 0; barrels[i] != nullptr && i < MAX_BARRELS; ++i);

	if (i != MAX_BARRELS)
	{
		barrels[i] = new Barrel(info.x, info.y);
	}
}


bool ModuleBarrel::CleanUp()
{
	LOG("Freeing all barrels");

	App->textures->Unload(text);

	for (uint i = 0; i < MAX_BARRELS; ++i)
	{
		if (barrels[i] != nullptr)
		{
			delete barrels[i];
			barrels[i] = nullptr;
		}
	}

	return true;
}

void ModuleBarrel::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (barrels[i] != nullptr && barrels[i]->collider == c1)
		{
			delete barrels[i];
			barrels[i] = nullptr;
			break;
		}
	}
}