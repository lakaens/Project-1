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
#include "ModuleEnemies.h"


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

	App->collision->Enable();

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

	
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERRIGHT,SCREEN_WIDTH/2,50);

	/*App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 81, -2752);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 111, -2660);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, -2576);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 60, -2568);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 27, -2492);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, -2464);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 110, -2436);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, -2355);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 74, -2300);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 120, -2274);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, -2215);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 69, -2174);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 102, -2176);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 91, -2080);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 209, -2029);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 71, -2001);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, -2003);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 212, -1967);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 61, -1914);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, -1879);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 104, -1835);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 104, -1742);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 72, -1661);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 108, -1560);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 108, -1466);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 80, -1340);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 165, -1231);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 143, -1100);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 2013, -1107);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 124, -926);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 211, -861);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 52, -803);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 6, -705);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 72, -681);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 118, 658);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, 640);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 61, 392);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 93, 230);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 187, 490);

	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 149, 1038);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 190, 1037);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 35, 686);

	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 6, 2681);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 212, 2395);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 210, 2238);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 211, 1726);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 5, 1558);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 4, 1365);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 4, 1109);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 212, 637);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 204, 452);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPER, 203, 261);

	

	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 41, 2100);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 139, 2081);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 82, 550);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 50, 298);

	App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 212, 212);*/
	
	

	return true;
}
bool ModuleStage1::CleanUp() {


	App->textures->Unload(texture);
	App->collision->Disable();

	return true;

}
update_status ModuleStage1::Update() {
	update_status ret = UPDATE_CONTINUE;


	
	
	App->render->Blit(texture, 0, -3200 + SCREEN_HEIGHT + 130, &background, 1.0f);

		
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && state) {
		state = false;
		App->fade->FadeToBlack(this, App->stage2, 1.0f);
		state = true;
	}

	
		App->render->camera.y -= 1 * SCREEN_SIZE ;

	return UPDATE_CONTINUE;
	
}


