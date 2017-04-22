#include "Application.h"
#include "PowerUp_Horse.h"
#include "ModuleCollision.h"

PowerUp_Horse::PowerUp_Horse(int x, int y) :PowerUp(x, y) {

	/*{414, 5, 16, 16}*/

	idle.PushBack({ 414, 5, 16, 16 });

	animation = &idle;

	collider = App->collision->AddCollider({ x, y, 16, 16 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->powerup);

	original_y = y;
}

void PowerUp_Horse::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_PLAYER) {
		if (collider != nullptr)
			collider->to_delete = true;
	}
}