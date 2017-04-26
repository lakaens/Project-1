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

	// Player dead
	dead.PushBack({56,81,14,26});
	dead.PushBack({95,78,16,29});
	dead.PushBack({132,80,21,27});
	dead.PushBack({172,80,23,27});
	dead.PushBack({209,83,27,24});
	dead.PushBack({ 249,84,31,22 });
	dead.PushBack({ 289,87,31,19 });
	dead.loop = false;
	dead.speed = 0.1f;


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
	cameralim = 2770;
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
	
	if (cameralim > 0) {
		position.y -= 1;// Automatic movement
		if (colup == false)
			position.y -= 1;// Automatic movement
	
	current_animation = &up;
	if (cameralim > 0) {
		position.y -= 1;// Automatic movement
	}
	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) // MOVEMENT LEFT
	{
		if (colleft == false) {
			if (position.x > 0) {
				position.x -= speed;
			}
		}
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}

	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) //MOVEMENT RIGHT
	{
		if (colright == false) {
			if (position.x < SCREEN_WIDTH - 19) {
				position.x += speed;
			}
		}
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}

	}

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) // MOVEMENT DOWN
	{
		if (coldown == false) {
			if (position.y < cameralim + SCREEN_HEIGHT - 27) {
				position.y += speed + 1;
			}
		}
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}

	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) // MOVEMENT UP
	{
		if (colup == false) {
			if (position.y > cameralim) {
				position.y -= speed;
			}
		}
		if (current_animation != &up)
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
	if(App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT || App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && cont<=15)
	{
		cont++;
		current_animation = &shootl;
		if (cont == 15|| App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN) {
			App->particles->AddParticle(App->particles->bulletl, position.x - 1, position.y + 5, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->bulletl, position.x + 10, position.y + 5, COLLIDER_PLAYER_SHOT);
			bullet++;
			App->audio->Playeffect(bulletsound);
			cont = 0;
		}
		
	}
	if (App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_REPEAT || App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN&& cont<=15)
	{
		cont++;
		current_animation = &shootu;
		if (cont == 15|| App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN) {
			App->particles->AddParticle(App->particles->bulletu, position.x + 3, position.y + 5, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->bulletu, position.x + 13, position.y + 5, COLLIDER_PLAYER_SHOT);
			bullet++;
			App->audio->Playeffect(bulletsound);
			cont = 0;
		}
		
	}
	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_REPEAT || App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_REPEAT && cont<=15)
	{
		cont++;
		current_animation = &shootr;
		if (cont == 15|| App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN) {
			App->particles->AddParticle(App->particles->bulletr, position.x + 5, position.y + 5, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->bulletr, position.x + 15, position.y + 5, COLLIDER_PLAYER_SHOT);
			bullet++;
			App->audio->Playeffect(bulletsound);
			cont = 0;
		}
		
	}
	colup=false;
	coldown = false;
	colright = false;
	colleft = false;
	

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
			//Check collision right
			if ((c1->rect.x + c1->rect.w) - c2->rect.x == 1
				&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
				&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
				&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1)
			{
				colright = true;
			}

			//Check collision Left
			if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
				&& (c2->rect.x + c2->rect.w) - c1->rect.x == 1
				&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
				&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1)
			{
				colleft = true;
			}

			//Check collision Up
			if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
				&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
				&& (c2->rect.y + c2->rect.h) - c1->rect.y == 1
				&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1)
			{
				colup = true;
			}

			//Check collision Down
			if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
				&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
				&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
				&& (c1->rect.y + c1->rect.h) - c2->rect.y == 1)
			{
				coldown = true;
			}

		}
		if (c2->type == COLLIDER_ENEMY_SHOT) {
			destroyed = true;
			current_animation = &dead;
		}
		if (c2->type == COLLIDER_ENEMY) {
			destroyed = true;
			current_animation = &dead;
		}

	}

