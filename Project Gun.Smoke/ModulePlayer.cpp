#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	player.PushBack({ , , ,  });
	player.PushBack({ , , ,  });
	player.PushBack({ , , ,  });
	player.PushBack({ , , ,  });
	player.PushBack({ , , ,  });
	player.speed = 0.2f;


}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load(""); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &player;

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_UP] == 1)
	{
		current_animation = &forward;
		position.y -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == 1)
	{
		current_animation = &forward;
		position.y += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == 1 && position.x != )
	{
		current_animation = &forward;
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == 1 && position.x != 0)
	{
		current_animation = &forward;
		position.x -= speed;
	}
	if (position.y != 0 && up) position.y -= 5;
	if (position.y != 430 && down)position.y += 5;
	if (position.x != 590 && right)position.x += 5;
	if (position.x != 0 && left) position.x -= 5;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}