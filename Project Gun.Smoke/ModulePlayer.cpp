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
	forward.PushBack({ 15, 0, 18, 27});
	forward.PushBack({ 55, 1, 19, 26});
	forward.PushBack({ 95, 1, 18, 26});
	forward.PushBack({ 134, 1, 19, 26});
	forward.PushBack({ 175, 0, 18, 28});
	forward.speed = 0.05f;

	shootf.PushBack({215, 0, 18, 27});
	shootf.PushBack({255, 1, 18, 26});
	shootf.PushBack({295, 1, 18, 26});
	shootf.PushBack({335, 1, 18, 26});
	shootf.PushBack({375, 0, 18, 27});
	shootf.speed = 0.05f;

	diagonalr.PushBack({417,0,16,25});
	diagonalr.PushBack({457,1,15,25});
	diagonalr.PushBack({17,41,15,26});
	diagonalr.PushBack({56,41,16,25});
	diagonalr.PushBack({94,40,20,25});
	diagonalr.speed = 0.05f;

	diagonall.PushBack({82,119,16,25});
	diagonall.PushBack({106,119,15,25});
	diagonall.PushBack({126,119,15,26});
	diagonall.PushBack({145,119,16,25});
	diagonall.PushBack({164,119,20,25});
	diagonall.speed = 0.05f;

	shootdr.PushBack({ 137,40,17,25});
	shootdr.PushBack({ 177,41,17,25});
	shootdr.PushBack({ 217,41,17,26});
	shootdr.PushBack({ 257,41,17,25});
	shootdr.PushBack({ 297,40,17,25});
	shootdr.speed = 0.05f;

	shootdl.PushBack({193,120,17,25});
	shootdl.PushBack({214,120,17,25});
	shootdl.PushBack({235,120,17,26});
	shootdl.PushBack({255,121,17,25});
	shootdl.PushBack({276,121,17,25});
	shootdl.speed = 0.05f;


}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("char.png"); // arcade version

	bulletsound = App->audio->Loadeffect("laser.wav");
	
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
		if (position.y < SCREEN_WIDTH + 90) {
			current_animation = &forward;

			position.y += speed;
		}
			
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x < SCREEN_HEIGHT - 133) {
			current_animation = &diagonalr;

			position.x += speed;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x > 0) {
			current_animation = &diagonall;

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

		App->particles->AddParticle(App->particles->bulletdl, position.x + 5, position.y);
		App->particles->AddParticle(App->particles->bulletdl, position.x + 15, position.y);
		bullet++;
		App->audio->Playeffect(bulletsound);
		

	}

	if (App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN) {
		
			App->particles->AddParticle(App->particles->bulletf, position.x + 5, position.y);
			App->particles->AddParticle(App->particles->bulletf, position.x + 15, position.y);
			bullet++;
			App->audio->Playeffect(bulletsound);

	}
	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN) {

		App->particles->AddParticle(App->particles->bulletdr, position.x + 8, position.y);
		App->particles->AddParticle(App->particles->bulletdr, position.x + 18, position.y);
		bullet++;
		App->audio->Playeffect(bulletsound);
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