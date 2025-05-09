#include "Framework.h"
#include "Item.h"

Item::Item():Circle(20)
{
}

Item::~Item()
{
}

void Item::Update()
{
}


void Item::UpgradeSpeed(Player* player)
{
	player->SetSpeed(player->GetSpeed() + AddSpeed);
	wstring str = L"PLAYER 속도 UP!";
	TextOut(hdc, SCREEN_WIDTH >> 1 , SCREEN_HEIGHT *0.3f , str.c_str(), str.size());
}

void Item::UpgradeBulletSpeed(Player* player)
{
	player->SetBulletSpeed(player->GetBulletSpeed() + AddBulletSpeed);
	wstring str = L"BULLET 속도 UP!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}

void Item::UpgradeBulletPower(Player* player)
{
	player->SetBulletPower(player->GetBulletPower() + AddBulletPower);
	wstring str = L"BULLET 파워 UP!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}

void Item::AddBulletLine(Player* player)
{
	wstring str = L"PLAYER 총 증가!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}
