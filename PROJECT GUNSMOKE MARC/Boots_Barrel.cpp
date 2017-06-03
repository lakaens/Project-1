#include "Application.h"
#include "Boots_Barrel.h"
#include "ModuleCollision.h"
Boots_Barrel::Boots_Barrel(int x, int y) :Enemy(x, y) {

	move.PushBack({ 738, 633, 16, 16 });
	move.loop = false;
	move.speed = 0.05f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,16,16 }, COLLIDER_TYPE::COLLIDER_BARREL, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	life = 5;

}