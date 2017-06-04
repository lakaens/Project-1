#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"


#define MAX_ENEMIES 300

enum ENEMY_TYPES
{
	NO_TYPE,
	GUNMEN,
	WINDOWSNIPERLEFT,
	WINDOWSNIPERRIGHT,
	BOMBER,
	RIFFLEMEN,
	BACKSTABBER,
	BOOTS,
	RIFLE,
	BULLET,
	HORSE,
	LITTLEBOTTLE,
	BIGBOTTLE,
	BARREL,
	GUNMENJUMPER,
	GUNMENBALCONY,
	GUNMENLEFT,
	GUNMENRIGHT,
	BOSS
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
	bool horse = false;
	bool AddEnemy(ENEMY_TYPES type, int x, int y);
	bool boots = false;
	bool bomb = false;

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
	
	
};

#endif // __ModuleEnemies_H__