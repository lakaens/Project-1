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
#include "ModuleGameOver.h"
#include "ModuleMap1.h"
#include "ModuleWin.h"
#include "SDL/include/SDL.h"

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

	// Player empty

	empty.PushBack({ 454,206,6,7 });

	
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
	font_score = App->fonts->Load("fonts/characters.png", " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ !¡?¿$^.:%*#()<>ªº+-=|&", 1);
	bulletsound = App->audio->Loadeffect("Gunsmoke/shotfx.wav");

	original_camera = 2770 * SCREEN_SIZE;
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->player->Disable();
	
	App->audio->unloadeffect(bulletsound);
	if (col != nullptr)
		col->to_delete = true;
	App->fonts->UnLoad(font_score);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	prevpos = position;

	App->fonts->BlitText(10, -13, font_score, "GUNMAN-1 HI-SCORE");
	char str[10];
	sprintf_s(str, "%i", score);
	App->fonts->BlitText(10, 0, font_score, str);
	sprintf_s(hscore, "%i", Hscore);
	App->fonts->BlitText(81, 0, font_score, hscore);




	if (Hscore < score){
		Hscore = score;
	}
	cont1++;
	current_animation = &up;

	if (cameralim > 0) {
		cameralim -= 0.5;
		position.y -= 0.5;// Automatic movement
	}
		float speed = 1.5;

		SDL_Event event;
		/* Other initializtion code goes here */

		/* Start main game loop here */

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_JOYAXISMOTION:  /* Handle Joystick Motion */
				if ((event.jaxis.value < -3200) || (event.jaxis.value > 3200))
				{
					if (event.jaxis.axis == 0)
					{
						/* Left-right movement code goes here */
					}

					if (event.jaxis.axis == 1)
					{
						/* Up-Down movement code goes here */
					}
				}
				break;
			case SDL_JOYBUTTONDOWN:  /* Handle Joystick Button Presses */
				if (event.jbutton.button == 0)
				{
					/* code goes here */
				}
				break;
			case SDL_JOYBALLMOTION:  /* Handle Joyball Motion */
				if (event.jball.ball == 0)
				{
					/* ball handling */
				}
				break;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) // MOVEMENT LEFT
		{
			if (!colleft) {
				if (position.x > 0)
					position.x -= speed;
				
			}
			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;
			}

		}

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) //MOVEMENT RIGHT
		{
			if (!colright) {
				if (position.x < SCREEN_WIDTH - 19)
					position.x += speed;
				
			}
			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;
			}

		}

		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) // MOVEMENT DOWN
		{
			
				if (position.y < cameralim + SCREEN_HEIGHT - 27) {
					position.y += speed + 1;
				
			}
			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;
			}

		}

		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT ) // MOVEMENT UP
		{
			
				if (position.y > cameralim) {
					position.y -= speed;
				
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
		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT || App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_REPEAT || App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_REPEAT) {
			if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_REPEAT || App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && cont <= 15)
			{
				cont++;
				current_animation = &shootl;
				if (cont == 15 || App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN) {
					App->particles->AddParticle(App->particles->bulletl, position.x - 1, position.y + 5, COLLIDER_PLAYER_SHOT,PARTICLE_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->bulletl, position.x + 10, position.y + 5, COLLIDER_PLAYER_SHOT, PARTICLE_PLAYER_SHOT);
					bullet++;
					App->audio->Playeffect(bulletsound);
					cont = 0;
				}

			}
			if (App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_REPEAT || App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN&& cont <= 15)
			{
				cont++;
				current_animation = &shootu;
				if (cont == 15 || App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN) {
					App->particles->AddParticle(App->particles->bulletu, position.x + 3, position.y + 5, COLLIDER_PLAYER_SHOT, PARTICLE_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->bulletu, position.x + 13, position.y + 5, COLLIDER_PLAYER_SHOT, PARTICLE_PLAYER_SHOT);
					bullet++;
					App->audio->Playeffect(bulletsound);
					cont = 0;
				}

			}
			if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_REPEAT || App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_REPEAT && cont <= 15)
			{
				cont++;
				current_animation = &shootr;
				if (cont == 15 || App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN) {
					App->particles->AddParticle(App->particles->bulletr, position.x + 5, position.y + 5, COLLIDER_PLAYER_SHOT, PARTICLE_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->bulletr, position.x + 15, position.y + 5, COLLIDER_PLAYER_SHOT, PARTICLE_PLAYER_SHOT);
					bullet++;
					App->audio->Playeffect(bulletsound);
					cont = 0;
				}

			}
		}
		if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN) {

			col->to_delete = true;

		}
		if (destroyed == false && position.y == 0) {
			App->fade->FadeToBlack(this, App->win);
		}

		col->SetPos(position.x, position.y);

		// Draw everything --------------------------------------
		if (destroyed == false)
			App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

		// Draw UI (score) --------------------------------------


		

		sprintf_s(score_text, 10, "%7d", score);

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_WALL && destroyed == false) {

		position=prevpos;
		

	}

	if ((c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_WALL))
	{
		//Check collision Right
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

		//Block Up-Right Diagonal
		if ((c1->rect.x + c1->rect.w) - c2->rect.x == 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y == 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1
			&& colup == false
			&& coldown == false
			&& colleft == false
			&& colright == false)
		{
			blockUR = true;
		}

		//Block Up-Left Diagonal
		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x == 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y == 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1
			&& colup == false
			&& coldown == false
			&& colleft == false
			&& colright == false)
		{
			blockUL = true;
		}

		//Block Down-Left Diagonal
		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x == 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y == 1
			&& colup == false
			&& coldown == false
			&& colleft == false
			&& colright == false)
		{
			blockDL = true;
		}

		//Block Down-Right Diagonal
		if ((c1->rect.x + c1->rect.w) - c2->rect.x == 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y == 1
			&& colup == false
			&& coldown == false
			&& colleft == false
			&& colright == false)
		{
			blockDR = true;
		}

	}
	if (c2->type == COLLIDER_ENEMY_SHOT || c2->type == COLLIDER_ENEMY && destroyed == false && App->fade->IsFading() == false) {

		if (col != nullptr) {
			col->to_delete = true;
		}
		if (life > 1) {
			--life;
			App->particles->AddParticle(App->particles->playerdead, position.x, position.y, COLLIDER_NONE);
			App->fade->FadeToBlack(App->map, App->map);
		}
		else if (life = 1) {
			destroyed = true;
			App->particles->AddParticle(App->particles->playerdead, position.x, position.y, COLLIDER_NONE);
			cameralim = 0;
			life = 3;
			App->fade->FadeToBlack(App->map, App->gameover);
		}
		/*if (col != nullptr) {
			col->to_delete = true;
		}
		destroyed = true;
		App->particles->AddParticle(App->particles->playerdead, position.x, position.y, COLLIDER_NONE);
		if (destroyed=true) {
			App->fade->FadeToBlack(App->map, App->gameover);
		}*/

	}		
		
}

