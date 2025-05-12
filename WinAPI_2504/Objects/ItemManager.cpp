#include "Framework.h"
#include "ItemManager.h"

ItemManager::ItemManager()
{
	items.resize(ITEM_POOL_SIZE);
	for (size_t i = 0; i < ITEM_POOL_SIZE; ++i)
	{
		items[i] = new Item();
		items[i]->SetActive(false);  // �⺻�� ��Ȱ�� ���·� ����
	}
}
ItemManager::~ItemManager()
{
	for (Item* item : items)
	{
		delete item;
	}
	items.clear();
}


void ItemManager::Render(HDC hdc)
{
	for (Item* item : items)
		item->Render(hdc);
}

void ItemManager::Update()
{
	spawnTime += DELTA;
	if (spawnTime > 3.0f)
	{

	}
}

bool ItemManager::IsCollision(Player* player)
{
	for (Item* item : items)
	{
		if (!item->IsCollisionCircle(player) || !item->IsActive())
			continue;
		return true;
	}
	return false;
}

ItemType ItemManager::GetItem(Player* player)
{
	for (Item* item : items)
	{
		if (IsCollision(player))
			return item->GetItemTag();
	}
	return ItemType(End);
}




