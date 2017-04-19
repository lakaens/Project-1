#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"


#define MAX_ENEMIES 100



enum ENEMY_TYPES
{
	NO_TYPE,
	GUNMEN,
	WINDOWSNIPER,
	BOMBER,
	RIFFLEMEN,
	BACKSTABBER,
	
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y);

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* BackStabberSprites;
	SDL_Texture* BomberSprites;
	SDL_Texture* GunMenSprites;
	SDL_Texture* RiffleMenSprites;
	SDL_Texture* WindowSniperSprites;
};

#endif // __ModuleEnemies_H__
