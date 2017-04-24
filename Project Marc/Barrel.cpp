#include "Application.h"
#include "Barrel.h"
#include "ModuleCollision.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"

Barrel::Barrel(int x, int y) : position(x, y)
{
	idle.PushBack({ 6, 53, 16, 16 });


	barrel.PushBack({ 31,54,15,15 });
	barrel.PushBack({ 54,54,15,15 });
	barrel.PushBack({ 78,55,16,14 });
	barrel.PushBack({ 102,56,16,13 });
	barrel.PushBack({ 126,55,16,14 });
	barrel.PushBack({ 152,58,14,11 });
	barrel.loop = false;
	barrel.speed = 0.2;

	collider = App->collision->AddCollider({ position.x,position.y,16,15 }, COLLIDER_BARREL, (Module*)App->barrels);

	current_animation = &idle;

}

Barrel::~Barrel()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Barrel::GetCollider() const
{
	return collider;
}

void Barrel::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (current_animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(current_animation->GetCurrentFrame()));
}

void Barrel::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_PLAYER_SHOT) {
		life--;
		if (life == 0) {
			current_animation = &barrel;
			if (collider != nullptr)
				collider->to_delete = true;
		}
	}
}