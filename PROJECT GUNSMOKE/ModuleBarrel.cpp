#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBarrel.h"
#include "ModuleCollision.h"

ModuleBarrel::ModuleBarrel()
{
	
}

ModuleBarrel::~ModuleBarrel()
{

}

// Load assets
bool ModuleBarrel::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Gunsmoke/particles.png");

	position.x = SCREEN_WIDTH / 2;
	position.y = 2700;



	idle.PushBack({ 56, 58, 16, 16 });


	barrel.PushBack({ 81,59,15,15 });
	barrel.PushBack({ 104,59,15,15 });
	barrel.PushBack({ 128,60,16,14 });
	barrel.PushBack({ 152,61,16,13 });
	barrel.PushBack({ 176,60,16,14 });
	barrel.PushBack({ 202,63,14,11 });
	barrel.loop = false;
	barrel.speed = 0.02;


	barrelcollider = App->collision->AddCollider({ position.x,position.y,16,15 }, COLLIDER_BARREL, this);

	current_animation = &idle;

	return true;
}

update_status ModuleBarrel::Update() {



	barrelcollider->SetPos(position.x, position.y);

	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;


}
bool ModuleBarrel::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);
	return true;

}

void ModuleBarrel::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_PLAYER_SHOT) {
		life--;

		if (life == 0) {
			current_animation = &barrel;
			if (barrelcollider != nullptr)
				barrelcollider->to_delete = true;

		}

	}
}
