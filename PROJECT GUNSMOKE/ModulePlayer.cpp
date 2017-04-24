#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"

#include<stdio.h>

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	// idle animation (just the ship)
	

	// Move Up
	up.PushBack({ 95, 1, 18, 26 });
	up.PushBack({ 55, 1, 19, 26 });
	up.PushBack({ 15, 0, 18, 27 });
	up.PushBack({ 55, 1, 19, 26 });
	up.PushBack({ 95, 1, 18, 26 });
	up.PushBack({ 134, 1, 19, 26 });
	up.PushBack({ 175, 0, 18, 28 });
	up.loop = true;
	up.speed = 0.1f;

	// Shoot up
	shootu.PushBack({ 215, 0, 18, 27 });
	shootu.PushBack({ 255, 1, 18, 26 });
	shootu.PushBack({ 295, 1, 18, 26 });
	shootu.PushBack({ 335, 1, 18, 26 });
	shootu.PushBack({ 375, 0, 18, 27 });
	shootu.loop = true;
	shootu.speed = 0.1f;

	// Move Diagonal Right
	right.PushBack({ 417,0,16,25 });
	right.PushBack({ 457,1,15,25 });
	right.PushBack({ 17,41,15,26 });
	right.PushBack({ 56,41,16,25 });
	right.PushBack({ 94,40,20,25 });
	right.loop = true;
	right.speed = 0.1f;

	// Move Diagonal Left
	left.PushBack({ 82,119,16,25 });
	left.PushBack({ 106,119,15,25 });
	left.PushBack({ 126,119,15,26 });
	left.PushBack({ 145,119,16,25 });
	left.PushBack({ 164,119,20,25 });
	left.loop = true;
	left.speed = 0.1f;

	//Shoot Diagonal Right
	shootr.PushBack({ 137,40,17,25 });
	shootr.PushBack({ 177,41,17,25 });
	shootr.PushBack({ 217,41,17,26 });
	shootr.PushBack({ 257,41,17,25 });
	shootr.PushBack({ 297,40,17,25 });
	shootr.loop = true;
	shootr.speed = 0.1f;

	// Shoot Diagonal Left
	shootl.PushBack({ 193,120,17,25 });
	shootl.PushBack({ 214,120,17,25 });
	shootl.PushBack({ 235,120,17,26 });
	shootl.PushBack({ 255,121,17,25 });
	shootl.PushBack({ 276,121,17,25 });
	shootl.loop = true;
	shootl.speed = 0.1f;


}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	
	graphics = App->textures->Load("Gunsmoke/char.png");

	destroyed = false;
	position.x = SCREEN_WIDTH/2;
	position.y = 3000;
	score = 0;

	col = App->collision->AddCollider({(int)position.x, (int)position.y, 19, 27}, COLLIDER_PLAYER, this);

	bulletsound = App->audio->Loadeffect("Gunsmoke/laser.wav");

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->collision->EraseCollider(col);
	App->fonts->UnLoad(font_score);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	previouspos = position;

	current_animation = &up;
	position.y -= 1; // Automatic movement

	int speed = 1;

	if(App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) // MOVEMENT LEFT
	{
		
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
		if (position.x > 0) {
			position.x -= speed;
		}
		
	}

	if(App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) //MOVEMENT RIGHT
	{
		
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
		if (position.x < SCREEN_WIDTH - 19) {
			position.x += speed;
		}
	}

	if(App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) // MOVEMENT DOWN
	{
		position.y += speed + 1;
		if(current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
		
	}

	if(App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) // MOVEMENT UP
	{
		position.y -= speed;
		if(current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {

		
			current_animation = &right;
		
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {

		
			current_animation = &left;
		
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {

		
			current_animation = &left;
		
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {

		
			current_animation = &right;
		
	}
	if(App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT&& cont<=35)
	{
		cont++;
		current_animation = &shootl;
		if (cont == 35) {
			App->particles->AddParticle(App->particles->bulletl, position.x - 1, position.y + 5, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->bulletl, position.x + 10, position.y + 5, COLLIDER_PLAYER_SHOT);
			bullet++;
			App->audio->Playeffect(bulletsound);
			cont = 0;
		}
		
	}
	if (App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_REPEAT && cont<=35)
	{
		cont++;
		current_animation = &shootu;
		if (cont == 35) {
			App->particles->AddParticle(App->particles->bulletu, position.x + 3, position.y + 5, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->bulletu, position.x + 13, position.y + 5, COLLIDER_PLAYER_SHOT);
			bullet++;
			App->audio->Playeffect(bulletsound);
			cont = 0;
		}
		
	}
	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_REPEAT && cont<=35)
	{
		cont++;
		current_animation = &shootr;
		if (cont == 35) {
			App->particles->AddParticle(App->particles->bulletr, position.x + 5, position.y + 5, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->bulletr, position.x + 15, position.y + 5, COLLIDER_PLAYER_SHOT);
			bullet++;
			App->audio->Playeffect(bulletsound);
			cont = 0;
		}
		
	}

	

	col->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	if(destroyed == false)
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	// Draw UI (score) --------------------------------------
	

	

	

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_WALL)
	{
		position = previouspos;
	}
			
}
