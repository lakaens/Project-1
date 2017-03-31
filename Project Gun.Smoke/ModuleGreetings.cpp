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
#include "ModuleGreetings.h"
#include "ModuleWelcome.h"


ModuleGreetings::ModuleGreetings() {
	background.x = 0;
	background.y = 0;
	background.w = SCREEN_WIDTH;
	background.h = SCREEN_HEIGHT;
}
ModuleGreetings::~ModuleGreetings() {

}

bool ModuleGreetings::Start() {

	LOG("Loading greetings: ");

	texture = App->textures->Load("greetings.png");


	return true;
}
bool ModuleGreetings::CleanUp() {
	App->textures->Unload(texture);
	App->audio->StopMusic();
	return true;

}
update_status ModuleGreetings::Update() {
	update_status ret = UPDATE_CONTINUE;

	App->render->Blit(texture, 0, 0, &background, 0.75f);

		
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && state) {
		state = false;
		App->fade->FadeToBlack(this, App->welcome, 1.0f);
		state = true;
	}


	return UPDATE_CONTINUE;

}