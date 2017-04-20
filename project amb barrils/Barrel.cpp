#include "Application.h"
#include "Barrel.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"

Barrel::Barrel(int x, int y) : position(x, y)
{
	rect.x = x;
	rect.y = y;
	rect.w = 21;
	rect.h = 25;

	destroy.PushBack({ 0, 0, 21, 25 });
	destroy.PushBack({ 34, 0, 21, 25 });
	destroy.PushBack({ 66, 0, 21, 25 });
	destroy.PushBack({ 91, 0, 21, 25 });
	destroy.PushBack({ 121, 0, 21, 25 });
	destroy.PushBack({ 150, 0, 21, 25 });
	destroy.PushBack({ 179, 0, 21, 25 });
	destroy.loop = false;
	destroy.speed = 1.0f;

	animation = &destroy;

	collider = App->collision->AddCollider({ 0, 0, 21, 25 }, COLLIDER_TYPE::COLLIDER_BARREL, (Module*)App->barrel);
}

Barrel::~Barrel()
{
}

const Collider* Barrel::GetCollider() const
{
	return collider;
}

void Barrel::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (!dead)
		App->render->Blit(sprites, 0, 0, &rect);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void Barrel::OnCollision(Collider* c1, Collider* c2)
{
	/*for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}*/
}