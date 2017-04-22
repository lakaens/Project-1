#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"

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
	graphics = App->textures->Load("particles1.png");

	// Explosion particle
	bulletf.anim.PushBack({ 205, 130, 2, 5 });
	bulletf.anim.PushBack({ 205, 130, 2, 5 });
	bulletf.anim.loop = false;
	bulletf.anim.speed = 0.3f;
	bulletf.life = 600;
	bulletf.speed.y = -4;

	bulletdr.anim.PushBack({ 252, 131, 4, 4 });
	bulletdr.anim.PushBack({ 275, 131, 5, 4 });
	bulletdr.anim.loop = false;
	bulletdr.anim.speed = 0.3f;
	bulletdr.life = 600;
	bulletdr.speed.y = -3;
	bulletdr.speed.x = +2;

	bulletdl.anim.PushBack({233, 139, 5, 4});
	bulletdl.anim.PushBack({ 242, 139, 4, 4});
	bulletdl.anim.loop = false;
	bulletdl.anim.speed = 0.3f;
	bulletdl.life = 600;
	bulletdl.speed.y = -3;
	bulletdl.speed.x = -2;

	deadbullet.anim.PushBack({ 177,23,4,4 });
	deadbullet.anim.PushBack({ 208,21,8,9 });
	deadbullet.anim.PushBack({ 238,18,17,16 });
	deadbullet.anim.loop = true;
	deadbullet.anim.speed = 0.3f;


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

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}
// -------------------------------------------------------------
// -------------------------------------------------------------
void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		App->collision->EraseCollider(collider);
}

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

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}