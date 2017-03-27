#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleBackground.h"

ModuleBackground::ModuleBackground() {
	background.x = 0;
	background.y = 3200;
	background.w = 224;
	background.h = 3070;
}
ModuleBackground::~ModuleBackground() {

}

bool ModuleBackground::Start() {

	bool ret = true;
	texture = App->textures->Load("mapa1.png");
	if (texture == nullptr) {
		LOG("Texture error: %s", SDL_GetError());
		ret = false;
	}
	return ret;
}
update_status ModuleBackground::Update() {
	update_status ret = UPDATE_CONTINUE;
	
	if (!App->render->Blit(texture, background.x, SCREEN_HEIGHT - background.y, &background, 0.75f)) {
		ret = UPDATE_ERROR;
		LOG("Blit error: %s", SDL_GetError());
	}
	
	return ret;
	
}
