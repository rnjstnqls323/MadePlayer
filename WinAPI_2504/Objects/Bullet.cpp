#include "Framework.h"

Bullet::Bullet() : Circle(5)
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	center += direction * SPEED * DELTA;

	if (center.y < 0 || center.x < 0 || center.y > SCREEN_HEIGHT || center.x > SCREEN_WIDTH)
	{
		isActive = false;
	}
}
