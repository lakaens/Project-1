#ifndef __ModulePowerUps_H__
#define __ModulePowerUps_H__

#include "Module.h"


#define MAX_POWERUPS 30



enum POWERUP_TYPES
{
	NO_TYPE,
	BOOTS,
	HORSE,
	POW,
	SHOTGUN,
};

class Enemy;

struct PowerUpInfo
{
	POWERUP_TYPES type = POWERUP_TYPES::NO_TYPE;
	int x, y;
};

class ModulePowerUps : public Module
{
public:

	ModulePowerUps();
	~ModulePowerUps();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddPowerUp(POWERUP_TYPES type, int x, int y);

private:

	void SpawnPowerUp(const PowerUpInfo& info);

private:

	PowerUpInfo queue[MAX_POWERUPS];
	PowerUp* powerups[MAX_POWERUPS];
	SDL_Texture* Powerups;

};

#endif // __ModulePowerUps_H__