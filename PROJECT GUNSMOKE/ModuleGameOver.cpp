#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleGameOver.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"



ModuleGameOver::ModuleGameOver()
{
	stage.x = 0;
	stage.y = 0;
	stage.w = 224;
	stage.h = 313;
}

ModuleGameOver::~ModuleGameOver()
{}

// Load assets
bool ModuleGameOver::Start()
{
	


	LOG("Loading space scene");

	background = App->textures->Load("Gunsmoke/gameover.png");
	

	

	return true;
}

// UnLoad assets
bool ModuleGameOver::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleGameOver::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	return UPDATE_CONTINUE;
}