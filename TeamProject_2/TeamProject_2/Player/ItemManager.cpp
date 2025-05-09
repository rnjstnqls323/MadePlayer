#include "Framework.h"
#include "ItemManager.h"

ItemManager::ItemManager()
{
	items.resize(ITEM_POOL_SIZE);
	for (Item* item : items)
	{
		item = new Item();
		item->SetActive(false);
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

void ItemManager::Update()
{
}

void ItemManager::Render(HDC hdc)
{
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

