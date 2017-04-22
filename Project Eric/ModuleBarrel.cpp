#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBarrel.h"
#include "ModuleCollision.h"



ModuleBarrel::ModuleBarrel()
{
	position.x = SCREEN_WIDTH/2;
	position.y = -200;
}

ModuleBarrel::~ModuleBarrel()
{

}

// Load assets
bool ModuleBarrel::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("particles1.png");

	idle.PushBack({ 6, 53, 16, 16 });

	
	barrel.PushBack({31,54,15,15});
	barrel.PushBack({54,54,15,15});
	barrel.PushBack({78,55,16,14});
	barrel.PushBack({102,56,16,13});
	barrel.PushBack({126,55,16,14});
	barrel.PushBack({152,58,14,11});
	barrel.loop = false;
	barrel.speed = 0.02;


	barrelcollider = App->collision->AddCollider({ position.x,position.y,16,15 }, COLLIDER_BARREL, this);

	current_animation = &idle;

	return true;
}

update_status ModuleBarrel::Update() {

	

	barrelcollider->SetPos(position.x, position.y );

	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y , &(current_animation->GetCurrentFrame()));

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
	if (c2->type==COLLIDER_PLAYER_SHOT) {
		life--;
		
		if (life == 0) {
			current_animation = &barrel;
			if (barrelcollider != nullptr)
				barrelcollider->to_delete = true;
			
		}

	}
}
