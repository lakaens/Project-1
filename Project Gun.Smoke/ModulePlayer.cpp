#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleStage1.h"
#include "ModuleInput.h"
#include "Module.h"
#include "ModuleStage2.h"
#include "ModuleParticles.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{


	// idle animation (arcade sprite sheet)
	forward.PushBack({ 15, 20, 30, 46});
	forward.PushBack({ 80, 23, 33, 43});
	forward.PushBack({ 145, 23, 32, 43});
	forward.PushBack({ 210, 23, 31, 43});
	forward.PushBack({ 277, 21, 31, 46});
	forward.speed = 0.05f;

	forwardbullet.PushBack({277,21,30,46});
	forwardbullet.PushBack({409,23,29,43});
	forwardbullet.PushBack({475,23,28,44});
	forwardbullet.PushBack({541,23,30,43});
	forwardbullet.PushBack({608,22,29,46});
	forwardbullet.speed = 0.05f;


}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	position.x = 150;
	position.y = 120;
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("char.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &forward;

	int speed = 2;


	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{

		current_animation = &forward;

			position.y -= speed;
		
		
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
	
		current_animation = &forward;

			position.y += speed;
		
			
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
			
		current_animation = &forward;

			position.x += speed;
		
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
			
		current_animation = &forward;

			position.x -= speed;
		
	}

	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN) {
		
		current_animation = &forwardbullet;
		App->particles->AddParticle(App->particles->bullets, position.x +8, position.y);
		App->particles->AddParticle(App->particles->bullets, position.x +18, position.y);

	}
	


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}