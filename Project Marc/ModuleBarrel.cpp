#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBarrel.h"
#include "ModuleCollision.h"
#include "Barrel.h"



ModuleBarrel::ModuleBarrel()
{
	for (uint i = 0; i < MAX_BARRELS; ++i)
		barrels[i] = nullptr;
}

/*App->barrel->AddBarrel(160, -20);
App->barrel->AddBarrel(160, -346);
App->barrel->AddBarrel(172, -934);
App->barrel->AddBarrel(172, -950);
App->barrel->AddBarrel(48, -1138);
App->barrel->AddBarrel(48, -1417);
App->barrel->AddBarrel(48, -1681);
App->barrel->AddBarrel(48, -1697);
App->barrel->AddBarrel(48, -1713);
App->barrel->AddBarrel(48, -1866);
App->barrel->AddBarrel(160, -2057);
App->barrel->AddBarrel(160, -2089);
App->barrel->AddBarrel(160, -2233);
App->barrel->AddBarrel(32, -2642);*/


//BOSS FINAL -> X = 122, Y = -2728

ModuleBarrel::~ModuleBarrel()
{

}

// Load assets
bool ModuleBarrel::Start()
{
	LOG("Loading particles");
	barrelsprites = App->textures->Load("particles1.png");

	return true;
}

update_status ModuleBarrel::Update() {

	for (uint i = 0; i < MAX_BARRELS; ++i) {
		if (barrels[i] != nullptr) {
			barrels[i]->Draw(barrelsprites);

		}
	}

	return UPDATE_CONTINUE;

}
bool ModuleBarrel::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(barrelsprites);
	return true;

}

void ModuleBarrel::OnCollision(Collider* c1, Collider* c2)
{
}