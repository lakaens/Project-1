#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleStage1.h"
#include "ModuleStage2.h"
#include "Module.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleWelcome.h"


ModuleWelcome::ModuleWelcome() {
	background.x = 0;
	background.y = 0;
	background.w = SCREEN_WIDTH;
	background.h = SCREEN_HEIGHT;
}
ModuleWelcome::~ModuleWelcome() {

}

bool ModuleWelcome::Start() {

	LOG("Loading stage1: ");

	texture = App->textures->Load("welcome.png");


	return true;
}
bool ModuleWelcome::CleanUp() {

	App->textures->Unload(texture);

	return true;

}
update_status ModuleWelcome::Update() {
	update_status ret = UPDATE_CONTINUE;

	App->render->Blit(texture, 0, 0, &background, 0.75f);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && state) {
		state = false;
		App->fade->FadeToBlack(this, App->stage1, 1);
		state = true;
	}


	return UPDATE_CONTINUE;

}