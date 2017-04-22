#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBarrel.h"
#include "ModuleCollision.h"



ModuleBarrel::ModuleBarrel()
{
	position.x = 160;
	position.y = -20;
}

/*App->barrel->AddBarrel(160, -20);
App->barrel->AddBarrel(160, -346);
App->barrel->AddBarrel(172, -934);
App->barrel->AddBarrel(172, -950);
App->barrel->AddBarrel(48, -1138);
App->barrel->AddBarrel(48, -1417);
App->barrel->AddBarrel(48, -1681);
App->barrel->AddBarrel(48, -1697);
App->barrel->AddBarrel(48, -1713);
App->barrel->AddBarrel(48, -1866);
App->barrel->AddBarrel(160, -2057);
App->barrel->AddBarrel(160, -2089);
App->barrel->AddBarrel(160, -2233);
App->barrel->AddBarrel(32, -2642);*/


//BOSS FINAL -> X = 122, Y = -2728

ModuleBarrel::~ModuleBarrel()
{

}

// Load assets
bool ModuleBarrel::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("particles1.png");

	idle.PushBack({ 6, 53, 16, 16 });


	barrel.PushBack({ 31,54,15,15 });
	barrel.PushBack({ 54,54,15,15 });
	barrel.PushBack({ 78,55,16,14 });
	barrel.PushBack({ 102,56,16,13 });
	barrel.PushBack({ 126,55,16,14 });
	barrel.PushBack({ 152,58,14,11 });
	barrel.loop = false;
	barrel.speed = 0.2;


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