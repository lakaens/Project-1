#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "stdio.h"
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneIntro::ModuleSceneIntro()
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading space intro");
	
	App->audio->musicLoad("Gunsmoke/mainmusic.ogg");
	font_score = App->fonts->Load("fonts/characters.png", " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ !¡?¿$^.:%*#()<>ªº+-=|&", 1);
	background = App->textures->Load("Gunsmoke/welcome.png");
	
	App->render->camera.x = App->render->camera.y = 0;
	
	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->render->Blit(background, 0, 0, NULL);
	App->fonts->BlitText(10, 10, font_score, "GUNMAN-1 HI-SCORE");
	sprintf_s(App->player->str, "%i", App->player->score);
	App->fonts->BlitText(10, 20, font_score, App->player->str);
	App->fonts->BlitText(81, 20, font_score, App->player->hscore);

	if(App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN || App->input->buttonStart == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->map);
	}

	return UPDATE_CONTINUE;
}