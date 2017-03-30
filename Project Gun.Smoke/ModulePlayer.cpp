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

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2;

	// idle animation (arcade sprite sheet)
	forward.PushBack({ 1, 1, 60, 80});
	forward.PushBack({ 60, 1, 60, 80});
	forward.PushBack({ 130, 1, 60, 80});
	forward.PushBack({ 190, 1, 60, 80});
	forward.PushBack({ 260, 1, 60, 80});
	forward.speed = 0.09f;

	idle.PushBack({ 130, 1, 60, 80 });

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{

	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("char.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 3;

	if (App->input->keyboard[SDL_SCANCODE_UP] == 1 && position.y != 0)
	{

		current_animation = &forward;

		position.y -= speed;
		//}
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == 1 && position.y != 176)
	{
	
		current_animation = &forward;
		position.y += speed;
			
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == 1)
	{
			
		current_animation = &forward;
		position.x += speed;
			
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == 1 && position.x != 0)
	{
			
		current_animation = &forward;
		position.x -= speed;
			
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == 1 && App->input->keyboard[SDL_SCANCODE_UP] == 1) {

		current_animation = &forward;
		speed = 0.1;
		position.x += speed;
		position.y -= speed;

	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == 1 && App->input->keyboard[SDL_SCANCODE_DOWN] == 1) {

		current_animation = &forward;
		speed = 0.1;
		position.x += speed;
		position.y += speed;

	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == 1 && App->input->keyboard[SDL_SCANCODE_UP] == 1) {

		current_animation = &forward;
		speed = 0.1;
		position.x -= speed;
		position.y -= speed;

	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == 1 && App->input->keyboard[SDL_SCANCODE_DOWN] == 1) {

		current_animation = &forward;
		speed = 0.1;
		position.x -= speed;
		position.y += speed;

	}


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}