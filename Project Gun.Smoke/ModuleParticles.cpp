#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("bullet.png");

	// Explosion particle
	bulletf.anim.PushBack({ 45, 21, 3, 8 });
	bulletf.anim.PushBack({ 45, 21, 3, 8 });
	bulletf.anim.loop = true;
	bulletf.anim.speed = 0.3f;
	bulletf.life = 2000;
	bulletf.speed.y = -5;

	bulletdr.anim.PushBack({109,21,9,9});
	bulletdr.anim.PushBack({ 109,21,9,9 });
	bulletdr.anim.loop = true;
	bulletdr.anim.speed = 0.3f;
	bulletdr.life = 2000;
	bulletdr.speed.y = -5;
	bulletdr.speed.x = +5;

	bulletdl.anim.PushBack({161,23,7,6});
	bulletdl.anim.PushBack({ 161,23,7,6 });
	bulletdl.anim.loop = true;
	bulletdl.anim.speed = 0.3f;
	bulletdl.life = 2000;
	bulletdl.speed.y = -5;
	bulletdl.speed.x = -5;


	// TODO 2: Create the template for a new particle "laser"

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				// Play particle fx here
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, Uint32 delay)
{
	Particle* p = new Particle(particle);
	p->born = SDL_GetTicks() + delay;
	p->position.x = x;
	p->position.y = y;

	active[last_particle++] = p;
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	return ret;
}