#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleStage1.h"
#include "ModuleStage2.h"

ModuleStage2::ModuleStage2() {
	background.x = 0;
	background.y = 0;
	background.w = 224;
	background.h = 3200;
}
ModuleStage2::~ModuleStage2() {

}

bool ModuleStage2::Start() {

	LOG("Texture error: %s", SDL_GetError());

	texture = App->textures->Load("mapa2.png");
	
	App->player->Enable();
		
		
	
	return true;
}
update_status ModuleStage2::Update() {
	update_status ret = UPDATE_CONTINUE;

	if (!App->render->Blit(texture, 0, -3000 + SCREEN_HEIGHT, &background, 0.75f)) {
		ret = UPDATE_ERROR;
		LOG("Blit error: %s", SDL_GetError());
	}

	return ret;

}