#include "Application.h"
#include "PowerUp_Shotgun.h"
#include "ModuleCollision.h"

PowerUp_Shotgun::PowerUp_Shotgun(int x, int y) :PowerUp(x, y) {

	/*{54, 7, 16, 14}*/

	idle.PushBack({ 54, 7, 16, 14 });

	animation = &idle;

	collider = App->collision->AddCollider({ x, y, 16, 16 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->powerup);

	original_y = y;
}

void PowerUp_Shotgun::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_PLAYER) {
		if (collider != nullptr)
			collider->to_delete = true;
	}
}