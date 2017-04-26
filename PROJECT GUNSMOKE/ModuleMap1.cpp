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
	
	background = App->textures->Load("Gunsmoke/map1.png");
	App->audio->musicLoad("Gunsmoke/stage1.ogg");

	App->collision->Enable();
	App->player->Enable();
	App->particles->Enable();

	App->enemies->Enable();
	App->audio->Enable();
	// Colliders ---
	//left buildings
	App->collision->AddCollider({ 0,3037,37,16 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,2689,55,348 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,1661,55,192 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,1377,55,284 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,1309,55,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,1349,49,28 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,1121,55,188 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,1021,55,100 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,832,55,189 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,124,37,18 }, COLLIDER_WALL);;
	App->collision->AddCollider({ 0,0,55,124 }, COLLIDER_WALL);

	//right buildings
	App->collision->AddCollider({ 169,2685,65,70 }, COLLIDER_WALL);
	App->collision->AddCollider({ 176,2755,48,20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 169,2401,68,284 }, COLLIDER_WALL);
	App->collision->AddCollider({ 171,2333,63,68 }, COLLIDER_WALL);
	App->collision->AddCollider({ 169,2144,66,189 }, COLLIDER_WALL);
	App->collision->AddCollider({ 169,1729,55,92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 187,1821,37,17 }, COLLIDER_WALL);
	App->collision->AddCollider({ 171,1661,53,68 }, COLLIDER_WALL);
	App->collision->AddCollider({ 169,1473,55,188 }, COLLIDER_WALL);
	App->collision->AddCollider({ 169,0,55,732 }, COLLIDER_WALL);


	//left stairs
	App->collision->AddCollider({ 55,2972,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,2876,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,2814,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,2716,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,1788,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,1596,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,1500,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,1404,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,1342,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,1244,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,1148,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,956,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,860,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,60,24,3 }, COLLIDER_WALL);

	//right stairs
	App->collision->AddCollider({ 145,2620,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,2522,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,2427,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 147,2366,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,2268,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,2172,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,1756,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 147,1694,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,1596,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,1500,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,668,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,476,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,380,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,284,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,188,24,3 }, COLLIDER_WALL);
	App->collision->AddCollider({ 145,92,24,3 }, COLLIDER_WALL);

	//well && boxes
	App->collision->AddCollider({ 117,2915,22,12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 98,1883,28,18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 117,803,22,12 }, COLLIDER_WALL);

	//lake
	App->collision->AddCollider({ 0,352,8,177 }, COLLIDER_WALL);
	App->collision->AddCollider({ 8,356,10,173 }, COLLIDER_WALL);
	App->collision->AddCollider({ 18,359,18,170 }, COLLIDER_WALL);
	App->collision->AddCollider({ 36,367,11,162 }, COLLIDER_WALL);
	App->collision->AddCollider({ 47,373,14,157 }, COLLIDER_WALL);
	App->collision->AddCollider({ 61,389,12,136 }, COLLIDER_WALL);
	App->collision->AddCollider({ 73,398,10,120 }, COLLIDER_WALL);
	App->collision->AddCollider({ 83,407,8,97 }, COLLIDER_WALL);
	App->collision->AddCollider({ 91,425,7,63 }, COLLIDER_WALL);
	App->collision->AddCollider({ 98,435,7,43 }, COLLIDER_WALL);

	//horse fences
	App->collision->AddCollider({ 150,2573,19,19 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,1453,19,19 }, COLLIDER_WALL);
	App->collision->AddCollider({ 150,333,19,19 }, COLLIDER_WALL);
	App->collision->AddCollider({ 55,13,19,19 }, COLLIDER_WALL);

	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 82, 2754);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 113, 2661);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, 2574);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 48, 2565);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 28, 2492);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, 2465);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 111, 2436);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, 2357);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 75, 2300);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 119, 2275);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, 2215);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 69, 2174);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 103, 2176);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 91, 2081);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 212, 2030);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 3, 2003);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 73, 2000);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 212, 1967);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 61, 1913);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 0, 1878);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 107, 1835);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 107, 1741);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 73, 1662);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 108, 1560);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 110, 1464);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 80, 1340);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 166, 1230);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 212, 1108);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 147, 1099);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 125, 925);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 212, 859);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 52, 804);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 10, 704);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 70, 677);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 120, 656);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 3, 640);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 65, 390);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 94, 228);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMEN, 5, 191);

	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 41, 2099);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 138, 2082);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 87, 548);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 51, 298);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMBER, 110, 20);

	App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 224, 211);
	App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 223, 102);

	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENJUMPER, 0, 1490);
	App->enemies->AddEnemy(ENEMY_TYPES::GUNMENJUMPER, 0, 1452);

	//App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 149, 1038);
	//App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 191, 1038);
	//App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 37, 683);
	//App->enemies->AddEnemy(ENEMY_TYPES::RIFFLEMEN, 78, 23);

	//App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 212, 212);
	//App->enemies->AddEnemy(ENEMY_TYPES::BACKSTABBER, 212, 100);
	/*App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERRIGHT, 7, 2681);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERRIGHT, 7, 1561);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERRIGHT, 7, 1369);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERRIGHT, 7, 1113);

	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 203, 2393);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 203, 2234);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 203, 1721);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 203, 633);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWSNIPERLEFT, 194, 259);*/
	//App->particles->AddParticle(App->particles->enemysimplebullet, SCREEN_WIDTH / 2, 2700, COLLIDER_ENEMY_SHOT);
	
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
	if (App->player->cameralim > 0) {
		App->render->camera.y -= 1 * SCREEN_SIZE;
	}


	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	/*if (App->player->destroyed==true) {
		App->fade->FadeToBlack(this, this);
	}*/
	
	return UPDATE_CONTINUE;
}