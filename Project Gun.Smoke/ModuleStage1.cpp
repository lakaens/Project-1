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
#include "ModuleCollision.h"


ModuleStage1::ModuleStage1() {
	background.x = 0;
	background_y = -3000;
	background.w = 224;
	background.h = 3200;
}
ModuleStage1::~ModuleStage1() {

}

bool ModuleStage1::Start() {
	numColliders = 0;
	down_speed = 0;
	LOG("Loading stage1: ");
	App->player->Enable();
	texture = App->textures->Load("mapa1.png");
	App->audio->musicLoad("stage1.ogg");

	App->collision->Enable();

	coliders[numColliders++] = App->collision->AddCollider({ 98,-1400,28,29 }, COLLIDER_WALL);
	coliders[numColliders++] = App->collision->AddCollider({ 0,0,80,140 }, COLLIDER_WALL);

	return true;
}
bool ModuleStage1::CleanUp() {


	App->textures->Unload(texture);
	App->collision->Disable();

	return true;

}
update_status ModuleStage1::Update() {
	update_status ret = UPDATE_CONTINUE;
	
	App->render->Blit(texture, 0, background_y + SCREEN_HEIGHT, &background, 0.75f);


	
	if (background_y < -SCREEN_HEIGHT) {
		background_y += 1;
		down_speed += 1;
	}
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && state) {
		state = false;
		App->fade->FadeToBlack(this, App->stage2, 1.0f);
		state = true;
	}

	for (int i = 0; i < numColliders; i++)
	{
		coliders[i]->SetPos(coliders[i]->rect.x, 60 + down_speed);
		coliders[i]->SetPos(coliders[i]->rect.x, 1400 + down_speed);
	}

	


	return UPDATE_CONTINUE;
	
}


