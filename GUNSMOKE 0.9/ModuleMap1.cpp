#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleMap1.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleGameOver.h"


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
	App->render->camera.y = 2770*SCREEN_SIZE;
	

	LOG("Loading space scene");
	
	background = App->textures->Load("Gunsmoke/map2.png");
	
	App->audio->musicLoad("Gunsmoke/stage1.ogg");

	App->collision->Enable();
	App->player->Enable();
	App->particles->Enable();

	App->enemies->Enable();
	
	//// Colliders ---
	////left buildings
	App->collision->AddCollider({ 180, 2502, 44, 290 }, COLLIDER_WALL);
	App->collision->AddCollider({ 192, 2464, 32, 38 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, 2365, 44, 80 }, COLLIDER_WALL);
	App->collision->AddCollider({ 169, 2076, 59, 289 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, 2043, 44, 33 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, 1980, 44, 63 }, COLLIDER_WALL);
	App->collision->AddCollider({ 208, 1951, 16, 29 }, COLLIDER_WALL);
	App->collision->AddCollider({ 182, 1979, 1, 1 }, COLLIDER_WALL);
	App->collision->AddCollider({ 183, 1978, 1, 2 }, COLLIDER_WALL);
	App->collision->AddCollider({ 184, 1977, 1, 3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 185, 1976, 1, 4 }, COLLIDER_WALL);
	App->collision->AddCollider({ 186, 1975, 1, 5 }, COLLIDER_WALL);
	App->collision->AddCollider({ 187, 1974, 1, 6 }, COLLIDER_WALL);
	App->collision->AddCollider({ 188, 1973, 1, 7 }, COLLIDER_WALL);
	App->collision->AddCollider({ 189, 1972, 1, 8 }, COLLIDER_WALL);
	App->collision->AddCollider({ 190, 1971, 1, 9 }, COLLIDER_WALL);
	App->collision->AddCollider({ 191, 1970, 1, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 192, 1969, 1, 11 }, COLLIDER_WALL);
	App->collision->AddCollider({ 193, 1968, 1, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 194, 1967, 1, 13 }, COLLIDER_WALL);
	App->collision->AddCollider({ 195, 1966, 1, 14 }, COLLIDER_WALL);
	App->collision->AddCollider({ 196, 1965, 1, 15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 197, 1964, 1, 16 }, COLLIDER_WALL);
	App->collision->AddCollider({ 198, 1963, 1, 17 }, COLLIDER_WALL);
	App->collision->AddCollider({ 199, 1962, 1, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 200, 1961, 1, 19 }, COLLIDER_WALL);
	App->collision->AddCollider({ 201, 1958, 1, 22 }, COLLIDER_WALL);
	App->collision->AddCollider({ 202, 1957, 1, 23 }, COLLIDER_WALL);
	App->collision->AddCollider({ 203, 1956, 1, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 204, 1955, 1, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 205, 1954, 1, 26 }, COLLIDER_WALL);
	App->collision->AddCollider({ 206, 1953, 1, 27 }, COLLIDER_WALL);
	App->collision->AddCollider({ 207, 1952, 1, 28 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, 327, 48, 940 }, COLLIDER_WALL);

	//stairs
	App->collision->AddCollider({ 145,2302,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,2206,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,2110,24,3 }, COLLIDER_WALL);

	
	//POWERUPS
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLEBOTTLE, 164, 2753);
	App->enemies->AddEnemy(ENEMY_TYPES::BOOTS, 164, 2737);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFLE, 164, 2625);
	App->enemies->AddEnemy(ENEMY_TYPES::BIGBOTTLE, 160, 2001);
	App->enemies->AddEnemy(ENEMY_TYPES::HORSE, 160, 1985);
	App->enemies->AddEnemy(ENEMY_TYPES::BIGBOTTLE, 208, 1634);
	App->enemies->AddEnemy(ENEMY_TYPES::BOOTS, 48, 1634);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLEBOTTLE, 208, 1458);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFLE, 44, 1153);
	App->enemies->AddEnemy(ENEMY_TYPES::BIGBOTTLE, 44, 946);
	App->enemies->AddEnemy(ENEMY_TYPES::BIGBOTTLE, 44, 849);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLEBOTTLE, 44, 833);
	App->enemies->AddEnemy(ENEMY_TYPES::BOOTS, 44, 641);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFLE, 44, 625);
	App->enemies->AddEnemy(ENEMY_TYPES::BIGBOTTLE, 44, 465);

	
	// Enemies ---
	//MAP 2 ENEMIES::::

	App->enemies->AddEnemy(ENEMY_TYPES::BOSS, 35, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 62, 2725);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 123, 2717);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 80, 2616);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 139, 2554);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 18, 2490);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 70, 2451);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 73, 2039);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 41, 1969);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 48, 1975);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 143, 1747);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 9, 1630);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 173, 1624);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 56, 1527);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 110, 1528);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 160, 1528);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 81, 1268);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 110, 1085);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 107, 817);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 89, 764);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 155, 580);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 90, 321);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 47, 52);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 78, 61);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 162, 69);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 192, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 126, 51);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 46, 18);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 148, 28);




	App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 224, 2573);
	App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 224, 2463);
	App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 224, 2438);
	App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 223, 1972);


	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 59, 2294);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 114, 2189);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 106, 1764);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 118, 1581);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 48, 1454);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 165, 1439);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 185, 1287);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 53, 1277);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 74, 1158);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 74, 896);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 68, 787);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 83, 549);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 83, 471);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 131, 454);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 169, 444);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 77, 429);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 156, 326);


	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 83, 2170);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 66, 1918);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 128, 1369);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 116, 672);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 35, 44);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 181, 44);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 59, 14);
	App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 179, 20);

	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 2561);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 2382);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 2306);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 2053);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 1881);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 1596);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 1524);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 1460);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 1358);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENLEFT, 0, 150);

	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 224, 1870);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 223, 1683);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 224, 1661);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 224, 1340);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 224, 1269);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 222, 1161);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 223, 782);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 224, 594);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 224, 560);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENRIGHT, 225, 150);
	//////
	////////barrels
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 164, 2753);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 164, 2737);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 164, 2641);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 164, 2625);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 160, 2001);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 160, 1985);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 208, 1634);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 48, 1634);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 208, 1458);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 44, 1169);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 44, 1153);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 44, 946);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 44, 849);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 44, 833);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 44, 641);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 44, 625);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 44, 465);


	//BOSS COORDS = 111, 133, 18, 29
	
	
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
	App->map->Disable();

	return true;
}

// Update: draw background
update_status ModuleMap1::Update()
{
	// Move camera forward -----------------------------
	if (App->player->cameralim > 0) {
		App->render->camera.y -= 1 ;
	}


	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	
	return UPDATE_CONTINUE;
}