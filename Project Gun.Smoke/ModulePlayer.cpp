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
	position.x = 200;
	position.y = 400;
	cameralim.y = 0;

	// idle animation (arcade sprite sheet)
	forward.PushBack({ 15, 0, 18, 27});
	forward.PushBack({ 55, 1, 19, 26});
	forward.PushBack({ 95, 1, 18, 26});
	forward.PushBack({ 134, 1, 19, 26});
	forward.PushBack({ 175, 0, 18, 28});
	forward.loop = true;
	forward.speed = 0.05f;

	shootf.PushBack({215, 0, 18, 27});
	shootf.PushBack({255, 1, 18, 26});
	shootf.PushBack({295, 1, 18, 26});
	shootf.PushBack({335, 1, 18, 26});
	shootf.PushBack({375, 0, 18, 27});
	shootf.loop = true;
	shootf.speed = 0.05f;

	diagonalr.PushBack({417,0,16,25});
	diagonalr.PushBack({457,1,15,25});
	diagonalr.PushBack({17,41,15,26});
	diagonalr.PushBack({56,41,16,25});
	diagonalr.PushBack({94,40,20,25});
	diagonalr.loop = true;
	diagonalr.speed = 0.05f;

	diagonall.PushBack({82,119,16,25});
	diagonall.PushBack({106,119,15,25});
	diagonall.PushBack({126,119,15,26});
	diagonall.PushBack({145,119,16,25});
	diagonall.PushBack({164,119,20,25});
	diagonall.loop = true;
	diagonall.speed = 0.05f;

	shootdr.PushBack({ 137,40,17,25});
	shootdr.PushBack({ 177,41,17,25});
	shootdr.PushBack({ 217,41,17,26});
	shootdr.PushBack({ 257,41,17,25});
	shootdr.PushBack({ 297,40,17,25});
	shootdr.loop = true;
	shootdr.speed = 0.05f;

	shootdl.PushBack({193,120,17,25});
	shootdl.PushBack({214,120,17,25});
	shootdl.PushBack({235,120,17,26});
	shootdl.PushBack({255,121,17,25});
	shootdl.PushBack({276,121,17,25});
	shootdl.loop = true;
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

	position.x = 100;
	position.y = 400 ;

	bulletsound = App->audio->Loadeffect("laser.wav");

	colider = App->collision->AddCollider({position.x,position.y,17,27}, COLLIDER_PLAYER);
	
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &forward;
	position.y -= 1;
	int speed = 1;



	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		
		if (position.y > 0) {
			current_animation = &forward;
		}
		
		

	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		position.y += 1.5;
		if (position.y < SCREEN_HEIGHT-2) {
			current_animation = &forward;
		}
		

		


	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &diagonalr;
		if (position.x < SCREEN_WIDTH - 18) {
			position.x += speed;
		}
		
			
		
	
}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &diagonall;
			
			if (position.x > 0) {
				position.x -= speed;
			}
			
		
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {

		current_animation = &diagonalr;

		position.x += 0.2;
		position.y -= 0.2;
		
		
			
		

	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {


		position.x -= 0.2;
		position.y -= 0.2;

		
			current_animation = &diagonall;
		

	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {


		position.x -= -0.2;
		position.y += -0.2;

		
			current_animation = &diagonalr;
		

	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {


		position.x += 0.2;
		position.y += -0.2;

		
			current_animation = &diagonall;
		

	}
	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN) {

		App->particles->AddParticle(App->particles->bulletdl, position.x + 5, position.y);
		App->particles->AddParticle(App->particles->bulletdl, position.x + 15, position.y);
		bullet++;
		App->audio->Playeffect(bulletsound);
		if (App->particles->bulletdl.life == 0) {
			App->particles->AddParticle(App->particles->deadbullet, position.x,position.y);
		}
		
		

	}

	if (App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN) {
		
			App->particles->AddParticle(App->particles->bulletf, position.x + 3, position.y);
			App->particles->AddParticle(App->particles->bulletf, position.x + 13, position.y);
			bullet++;
			App->audio->Playeffect(bulletsound);
			

	}
	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN) {

		App->particles->AddParticle(App->particles->bulletdr, position.x + 5, position.y);
		App->particles->AddParticle(App->particles->bulletdr, position.x + 15, position.y);
		bullet++;
		App->audio->Playeffect(bulletsound);
		
	}	

	if (App->particles->bulletf.life == 0) {
		
	}
	
	colider->SetPos(position.x, position.y - 30);
	


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - 30, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}


bool ModulePlayer::CleanUp() {


	App->textures->Unload(graphics);
	return true;
	
}

void ModulePlayer::CollisionWall(Collider* c1,Collider* c2) {

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		position.x++;

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		position.x--;

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		position.y--;

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
		position.y++;
	
}
	
