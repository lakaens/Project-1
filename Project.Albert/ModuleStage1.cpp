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
#include "ModuleBarrel.h"
#include "ModuleGreetings.h"

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
	App->barrel->Enable();

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

	//LOS ENEMIGOS TIPO GUNMEN ESTAN COLOCADOS EN ORDEN DE SPAWN
	
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 80, -16);//Spawn andando hacia abajo -- 1
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 113, -112);//Spawn andando hacia abajo -- 2
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 48, -209);//Spawn andando hacia abajo -- 3
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 1, -197);//Spawn andando de forma horizontal despues de matar el enemy 3 -- 4
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 28, -278);//Spawn andando hacia abajo --  5
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 1, -309);//Spawn andando hacia abajo -- 6
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 113, -336);//Spawn andando hacia abajo -- 7
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 1, -419);//Spawn andando hacia abajo -- 8
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 75, -474);//Spawn andando hacia abajo -- 9
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 120, -499);//Spawn andando hacia abajo -- 10
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 1, -558);//Spawn andando hacia abajo -- 11
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 70, -600);//Spawn andando hacia abajo -- 12
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 107, -600);//Spawn andando hacia abajo -- 13
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 91, -692);//Spawn andando hacia abajo -- 14
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 213, -744);//Spawn andando de forma horizontal (de derecha a izquierda) -- 15
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 74, -772);//Spawn andando hacia abajo -- 16
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 1, -768);//Spawn andando de forma horizontal (de izquierda a derecha) despues de matar al enemy 16 -- 17
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 225, -806);//Spawn andando de forma horizontal (de derecha a izquierda) despues de matar al enemy 17 -- 18
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 64, -861);//Spawn andando hacia abajo -- 19
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 108, -937);//Spawn andando hacia abajo -- 20
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 1, -893);//Spawn andando de forma horizontal (de izuqierda a derecha) despues de matar al enemy 20 -- 21
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 107, -938);//Spawn andando hacia abajo -- 22
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 85, -1113);//Spawn andando hacia abajo -- 23
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 110,-1213);//Spawn andando hacia abajo -- 24
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 112,-1309);//Spawn andando hacia abajo -- 25
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 1,-1282);//Spawn saltando desde el tejado de la casa izquierda depsues de matar al enemy 25 -- 26
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 1,-1324);//Spawn saltando desde el tejado de la casa izquierda justo despues de que haga spawn el enemy 26 -- 27
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 80,-1433);//Spawn andando hacia abajo -- 28
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 167,-1546);//Spawn andando hacia abajo -- 29
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 150,-1674);//Spawn andando hacia abajo -- 30
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 225,-1674);//Spawn andando de forma horizontal (de derecha a izquierda) segundos despues de que aparezca el enemy 30 -- 31
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 129,-1852);//Spawn andando hacia abajo -- 32
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 225,-1914);//Spawn andando de forma horizontal (de derecha a izquierda) segundos despues de que aparezca el enemy 32 -- 33
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 82,-1970);//Spawn andando hacia abajo (lo hace a la vez que el enemy 33) -- 34
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 11,-2070);//Spawn andando hacia abajo -- 35
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 72,-2097);//Spawn andando hacia abajo -- 36
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 128,-2118);//Spawn andando hacia abajo -- 37
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 1,-2132);//Spawn andando de forma horizontal(de izquierda a derecha) despues de matar al enemy 37 -- 38
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 189,-2308);//Spawn andando hacia abajo (se mueve en un balcon y no sale de el, al morir cae a la calle)--39
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 69,-2383);//Spawn andando bordeando el lago -- 40
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 189,-2475);//Spawn andando hacia abajo (se mueve en un balcon y no sale de el, al morir cae a la calle) -- 41
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 101,-2545);//Spawn andando hacia abajo -- 42

	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 152, -1738);//Spawn anda unos pasos y parece quedarse quieto -- 43
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 190, -11738);//Spawn anda unos pasos y parece quedarse quieto -- 44
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 41, -2089);//Spawn anda unos pasos y parece quedarse quieto -- 45

	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERRIGHT, 5, -95);//Spawn al acercarse sin movimiento -- 46
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 205, -380);//Spawn al acercarse sin movimiento -- 47
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 205, -542);//Spawn al acercarse sin movimiento -- 48
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 205, -1053);//Spawn al acercarse sin movimiento -- 49
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERRIGHT, 5, 1558);//Spawn al acercarse sin movimiento -- 50
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERRIGHT, 4, 1365);//Spawn al acercarse sin movimiento -- 51
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERRIGHT, 4, 1109);//Spawn al acercarse sin movimiento -- 52
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 205, -2140);//Spawn al acercarse sin movimiento -- 53
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 195, -2331);//Spawn al acercarse sin movimiento -- 54
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 195, -2523);//Spawn al acercarse sin movimiento -- 55

	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 42, -673);//Spawn andando hacia abajo -- 56
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 140, -691);//Spawn andando hacia abajo -- 57
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 97, -2233);//Spawn andando hacia abajo -- 58
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 51, -2477);//Spawn andando hacia abajo -- 59

	App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 25, -2562);//Spawn saltando desde las casas de la derecha hacia el player -- 60

	

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
		App->fade->FadeToBlack(this, App->greetings, 1.0f);
		state = true;
	}

	
		App->render->camera.y -= 1 * SCREEN_SIZE ;

	return UPDATE_CONTINUE;
	
}


