#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{
	player = new Player();

	BulletManager::Get();

}

ShootingScene::~ShootingScene()
{
	delete player;

	BulletManager::Delete();

}

void ShootingScene::Update()
{
	player->Update();

	BulletManager::Get()->Update();

}

void ShootingScene::Render(HDC hdc)
{
	player->Render(hdc);

	BulletManager::Get()->Render(hdc);
}
