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
#include "ModuleAudio.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = SCREEN_HEIGHT/2;
	position.y = SCREEN_WIDTH/2;

	// idle animation (arcade sprite sheet)
	forward.PushBack({ 15, 20, 30, 46});
	forward.PushBack({ 80, 23, 33, 43});
	forward.PushBack({ 145, 23, 32, 43});
	forward.PushBack({ 210, 23, 31, 43});
	forward.PushBack({ 277, 21, 31, 46});
	forward.speed = 0.05f;

	shootf.PushBack({277,21,30,46});
	shootf.PushBack({409,23,29,43});
	shootf.PushBack({475,23,28,44});
	shootf.PushBack({541,23,30,43});
	shootf.PushBack({608,22,29,46});
	shootf.speed = 0.05f;

	diagonalr.PushBack({676,22,27,41});
	diagonalr.PushBack({741,24,26,41});
	diagonalr.PushBack({19,90,24,41});
	diagonalr.PushBack({83,88,25,41});
	diagonalr.PushBack({146,86,32,42});
	diagonalr.speed = 0.05f;

	diagonall.PushBack({142,213,28,42});
	diagonall.PushBack({210,214,23,40});
	diagonall.PushBack({273,215,25,42});
	diagonall.PushBack({340,215,27,41});
	diagonall.PushBack({411,217,32,41});
	diagonall.speed = 0.05f;

	shootdr.PushBack({ 215,87,27,41});
	shootdr.PushBack({ 280,88,27,41});
	shootdr.PushBack({ 347,89,26,42});
	shootdr.PushBack({ 412,88,26,42});
	shootdr.PushBack({ 478,86,26,42});
	shootdr.PushBack({ 545,87,25,42});
	shootdr.PushBack({ 612,89,24,43});
	shootdr.PushBack({ 678,88,23,44});
	shootdr.PushBack({ 19,151,25,43});
	shootdr.speed = 0.05f;



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
	Animation* current_animation = &forward;

	int speed = 2;


	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > 0) {
			current_animation = &forward;

			position.y -= speed;
		}
		
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y < SCREEN_WIDTH - 10) {
			current_animation = &forward;

			position.y += speed;
		}
			
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x < SCREEN_HEIGHT - 63) {
			current_animation = &forward;

			position.x += speed;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x > 0) {
			current_animation = &forward;

			position.x -= speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {

		
		position.x += -0.2;
		position.y -= -0.2;
		
		current_animation = &diagonalr;

	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {


		position.x -= -1;
		position.y -= -0.2;

		current_animation = &diagonall;

	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {


		position.x -= -0.2;
		position.y += -0.2;

		current_animation = &diagonalr;

	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {


		position.x += -0.2;
		position.y += -0.2;

		current_animation = &diagonall;

	}
	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN) {

		App->particles->AddParticle(App->particles->bulletdl, position.x + 8, position.y);
		App->particles->AddParticle(App->particles->bulletdl, position.x + 18, position.y);
		App->audio->effectLoad("laser.wav");
		current_animation = &forward;

	}

	if (App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN) {
		
			App->particles->AddParticle(App->particles->bulletf, position.x + 8, position.y);
			App->particles->AddParticle(App->particles->bulletf, position.x + 18, position.y);
			App->audio->effectLoad("laser.wav");
			current_animation = &forward;

	}
	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN) {

		App->particles->AddParticle(App->particles->bulletdr, position.x + 8, position.y);
		App->particles->AddParticle(App->particles->bulletdr, position.x + 18, position.y);
		App->audio->effectLoad("laser.wav");
		current_animation = &forward;
	}	
	


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}


bool ModulePlayer::CleanUp() {


	App->textures->Unload(graphics);
	return true;
	
}