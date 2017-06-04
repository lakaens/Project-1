#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleWin.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleSceneIntro.h"


ModuleWin::ModuleWin()
{
	stage.x = 0;
	stage.y = 0;
	stage.w = SCREEN_WIDTH;
	stage.h = SCREEN_HEIGHT;
}

ModuleWin::~ModuleWin()
{}

// Load assets
bool ModuleWin::Start()
{

	App->render->camera.x = App->render->camera.y = 0;
	App->audio->musicLoad("Gunsmoke/win.ogg");
	LOG("Loading space scene");

	background = App->textures->Load("Gunsmoke/finalscene.png");




	return true;
}

// UnLoad assets
bool ModuleWin::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleWin::Update()
{
	App->render->Blit(background, 0, 0, &stage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->buttonStart && App->fade->IsFading() == false) {
		App->fade->FadeToBlack((Module*)App->win, (Module*)App->scene_intro);
	}

	return UPDATE_CONTINUE;
}