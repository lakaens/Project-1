#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleMap1.h"



ModuleMap1::ModuleMap1()
{
	stage.x = 0;
	stage.y = -3200;
	stage.w = 224;
	stage.h = 3200;
}

ModuleMap1::~ModuleMap1()
{}

// Load assets
bool ModuleMap1::Start()
{
	App->render->camera.y = 2750*SCREEN_SIZE;
	LOG("Loading space scene");
	
	background = App->textures->Load("Gunsmoke/map1.png");
	

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	
	// Colliders ---
	//colliders primera casa izquierda
	App->collision->AddCollider({ 0,-80,60,348 }, COLLIDER_WALL); //first house 
	App->collision->AddCollider({ 0,268,36,15 }, COLLIDER_WALL); //borde principio
	App->collision->AddCollider({ 0,-108,43,28 }, COLLIDER_WALL); //borde final
	App->collision->AddCollider({ 60,202,18,19 }, COLLIDER_WALL); //primera escalera
	App->collision->AddCollider({ 60,106,18,19 }, COLLIDER_WALL); //segunda escalera
	App->collision->AddCollider({ 60,44,15,18 }, COLLIDER_WALL); //tercera escalera
	App->collision->AddCollider({ 60,-54,20,19 }, COLLIDER_WALL); //cuarta escalera

																  //colliders primera casa derecha	
	App->collision->AddCollider({ 164,-623,60,630 }, COLLIDER_WALL); //primera casa derecha
	App->collision->AddCollider({ 180,-660,43,37 }, COLLIDER_WALL); //borde final
	App->collision->AddCollider({ 147,-196,17,26 }, COLLIDER_WALL); //barra caballos
	App->collision->AddCollider({ 145,-150,19,19 }, COLLIDER_WALL); //primera escalera
	App->collision->AddCollider({ 145,-246,19,19 }, COLLIDER_WALL); //segunda escalera
	App->collision->AddCollider({ 145,-342,19,19 }, COLLIDER_WALL); //tercera escalera
	App->collision->AddCollider({ 148,-404,16,19 }, COLLIDER_WALL); //cuarta escalera
	App->collision->AddCollider({ 145,-502,19,19 }, COLLIDER_WALL); //quinta escalera
	App->collision->AddCollider({ 145,-598,19,19 }, COLLIDER_WALL); //sexta escalera

																	//colliders casa medio izquierda
	App->collision->AddCollider({ 0,-1935,60,1019 }, COLLIDER_WALL); //casa medio izquierda
	App->collision->AddCollider({ 0,-1972,43,37 }, COLLIDER_WALL); //borde final
	App->collision->AddCollider({ 60,-1316,17,26 }, COLLIDER_WALL); //barra caballos
	App->collision->AddCollider({ 60,-982,18,19 }, COLLIDER_WALL); //primera escalera
	App->collision->AddCollider({ 60,-1174,18,19 }, COLLIDER_WALL); //segunda escalera
	App->collision->AddCollider({ 60,-1270,18,18 }, COLLIDER_WALL); //tercera escalera
	App->collision->AddCollider({ 60,-1366,20,19 }, COLLIDER_WALL); //cuarta escalera
	App->collision->AddCollider({ 60,-1428,15,18 }, COLLIDER_WALL); //quinta escalera
	App->collision->AddCollider({ 60,-1526,18,19 }, COLLIDER_WALL); //sexta escalera
	App->collision->AddCollider({ 60,-1622,18,19 }, COLLIDER_WALL); //septima escalera
	App->collision->AddCollider({ 60,-1814,17,19 }, COLLIDER_WALL); //octava escalera
	App->collision->AddCollider({ 60,-1910,18,19 }, COLLIDER_WALL); //novena escalera


																	//colliders casa medio derecha	
	App->collision->AddCollider({ 164,-1295,60,345 }, COLLIDER_WALL); //casa medio derecha
	App->collision->AddCollider({ 187,-950,36,17 }, COLLIDER_WALL); //borde principio
	App->collision->AddCollider({ 180,-1332,43,37 }, COLLIDER_WALL); //borde final
	App->collision->AddCollider({ 145,-1014,19,19 }, COLLIDER_WALL); //primera escalera
	App->collision->AddCollider({ 148,-1076,16,18 }, COLLIDER_WALL); //segunda escalera
	App->collision->AddCollider({ 145,-1174,19,19 }, COLLIDER_WALL); //tercera escalera
	App->collision->AddCollider({ 145,-1270,19,19 }, COLLIDER_WALL); //cuarta escalera

																	 //colliders ultima casa izquierda
	App->collision->AddCollider({ 0,-2770,60,125 }, COLLIDER_WALL); //ultima casa izquierda
	App->collision->AddCollider({ 0,-2645,36,16 }, COLLIDER_WALL); //borde principio
	App->collision->AddCollider({ 60,-2756,17,26 }, COLLIDER_WALL); //barra caballos
	App->collision->AddCollider({ 60,-2710,18,19 }, COLLIDER_WALL); //primera escalera

																	//colliders ultima casa derecha	
	App->collision->AddCollider({ 164,-2770,60,733 }, COLLIDER_WALL); //ultima casa derecha
	App->collision->AddCollider({ 147,-2436,17,26 }, COLLIDER_WALL); //barra caballos
	App->collision->AddCollider({ 145,-2102,19,19 }, COLLIDER_WALL); //primera escalera
	App->collision->AddCollider({ 145,-2294,19,19 }, COLLIDER_WALL); //segunda escalera
	App->collision->AddCollider({ 145,-2390,19,19 }, COLLIDER_WALL); //tercera escalera
	App->collision->AddCollider({ 145,-2486,19,19 }, COLLIDER_WALL); //cuarta escalera
	App->collision->AddCollider({ 145,-2582,19,19 }, COLLIDER_WALL); //quinta escalera
	App->collision->AddCollider({ 145,-2678,19,19 }, COLLIDER_WALL); //sexta escalera
	App->collision->AddCollider({ 145,-2770,19,15 }, COLLIDER_WALL); //septima escalera

																	 //colliders objetos
	App->collision->AddCollider({ 117,150,22,20 }, COLLIDER_WALL); //primera caja
	App->collision->AddCollider({ 98,-882,28,28 }, COLLIDER_WALL); //pozo
	App->collision->AddCollider({ 117,-1962,21,19 }, COLLIDER_WALL); //segunda caja

	// Enemies ---
	
	
	return true;
}

// UnLoad assets
bool ModuleMap1::CleanUp()
{
	LOG("Unloading space scene");

 	App->textures->Unload(background);

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleMap1::Update()
{
	// Move camera forward -----------------------------
	App->render->camera.y -= 1 * SCREEN_SIZE;

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	
	return UPDATE_CONTINUE;
}