#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleBackground.h"

ModuleBackground::ModuleBackground(): Module() {
	background.x = 0;
	background.y = 0;
	background.w = 224;
	background.h = 3070;
}
ModuleBackground::~ModuleBackground() {

}

bool ModuleBackground::Start() {

	bool ret = true;
	texture = App->textures->Load("Game/stage1r.png");
	return ret;
}
update_status ModuleBackground::Update() {
	update_status ret = UPDATE_CONTINUE;
	
	App->render->Blit(texture, 0, -2036 + SCREEN_HEIGHT, &background, 0.75f);

	

	return ret;
	
}
