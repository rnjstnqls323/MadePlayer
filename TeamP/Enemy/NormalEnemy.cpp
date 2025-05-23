#include "Framework.h"
#include "NormalEnemy.h"

NormalEnemy::NormalEnemy()
{
}

NormalEnemy::~NormalEnemy()
{
}

void NormalEnemy::Fire()
{
	fireTimer += DELTA;
	if (fireTimer > FIRE_INTERVAL)
	{
		Vector2 direction = player->GetCenter() - center;
		EnemyBulletManager::Get()->Fire(center, direction, RGB(0,255,255));
		fireTimer = 0.0f;
	}
}
