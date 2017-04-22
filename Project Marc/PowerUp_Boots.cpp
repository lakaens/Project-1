#include "Application.h"
#include "PowerUp_Boots.h"
#include "ModuleCollision.h"

PowerUp_Boots::PowerUp_Boots(int x, int y) :PowerUp(x, y) {

	/*{30, 5, 16, 16}*/

	idle.PushBack({ 30, 5, 16, 16 });

	animation = &idle;

	collider = App->collision->AddCollider({ x, y, 16, 16 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->powerup);

	original_y = y;
}

void PowerUp_Boots::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_PLAYER) {
		if (collider != nullptr)
			collider->to_delete = true;
	}
}