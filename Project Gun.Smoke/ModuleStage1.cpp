#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleStage1.h"
#include "ModuleStage2.h"

ModuleStage1::ModuleStage1() {
	background.x = 0;
	background.y = 0;
	background.w = 224;
	background.h = 3200;
}
ModuleStage1::~ModuleStage1() {

}

bool ModuleStage1::Start() {

	bool ret = true;
	texture = App->textures->Load("mapa1.png");
	if (texture == nullptr) {
		LOG("Texture error: %s", SDL_GetError());
		ret = false;
	}
	return ret;
}
update_status ModuleStage1::Update() {
	update_status ret = UPDATE_CONTINUE;
	
	if (!App->render->Blit(texture, 0, -3000 + SCREEN_HEIGHT, &background, 0.75f)) {
		ret = UPDATE_ERROR;
		LOG("Blit error: %s", SDL_GetError());
	}
	
	return ret;
	
}
