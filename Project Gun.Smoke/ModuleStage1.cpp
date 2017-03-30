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


ModuleStage1::ModuleStage1() {
	background.x = 0;
	background.y = 0;
	background.w = 224;
	background.h = 3200;
}
ModuleStage1::~ModuleStage1() {

}

bool ModuleStage1::Start() {

	LOG("Loading stage1: ");
	App->player->Enable();
	texture = App->textures->Load("mapa1.png");
	App->audio->musicLoad("stage1.ogg");
	

	return true;
}
bool ModuleStage1::CleanUp() {

	App->player->Disable();
	App->audio->Disable();

	return true;

}
update_status ModuleStage1::Update() {
	update_status ret = UPDATE_CONTINUE;
	
	if (!App->render->Blit(texture, 0, -3000 + SCREEN_HEIGHT, &background, 0.75f)) {
		ret = UPDATE_ERROR;
		LOG("Blit error: %s", SDL_GetError());
	}
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(App->stage1, App->stage2, 1.0f);
	}


	return UPDATE_CONTINUE;
	
}
