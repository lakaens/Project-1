#include "Application.h"
#include "PowerUp_Pow.h"
#include "ModuleCollision.h"

PowerUp_Pow::PowerUp_Pow(int x, int y) :PowerUp(x, y) {

	/*{199, 33, 14, 10}*/

	idle.PushBack({ 199, 33, 14, 10 });

	animation = &idle;

	collider = App->collision->AddCollider({ x, y, 16, 16 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->powerup);

	original_y = y;
}

void PowerUp_Pow::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_PLAYER) {
		if (collider != nullptr)
			collider->to_delete = true;
	}
}