#include "stdafx.h"
#include "item.h"
#include "player.h"

HRESULT key::init()
{
	
	IMAGEMANAGER->addImage("itemKey", "LostVikingsimage/NPC_item/itemKey.bmp", 45, 45, true ,RGB(255,0,255));
	_key._img = IMAGEMANAGER->findImage("itemKey");
	_key._img->setCenter(2158, 1877);
	_key._rc = RectMakeCenter(2158, 1877, 45,45);

	return S_OK;
}

void key::update()
{
	_key._rc = RectMakeCenter(0, 0, 0, 0);
	_key._img->setX(0);
	_key._img->setY(0);
}

void key::release()
{

}

void key::render()
{
	_key._img->render(getMemDC());
}

bool key::keycheck(player* player)
{
	RECT temp;
	if (IntersectRect(&temp, &(player->getRECT()), &_key._rc))
	{
		return true;
	}
	if (player->key)
	{
		return true;
	}
}

HRESULT heal::init(float x, float y)
{
	return S_OK;
}

void heal::update()
{

}

void heal::release()
{

}

void heal::render()
{

}

HRESULT bomb::init(float x, float y)
{
	return S_OK;
}

void bomb::update()
{

}

void bomb::release()
{

}

void bomb::render()
{

}

HRESULT clearobject1::init(float x, float y ,int i)
{
	IMAGEMANAGER->addImage("itemCard", "LostVikingsimage/NPC_item/itemCard.bmp", 48, 48, true, RGB(255, 0, 255));
	if(i ==1) _clear._img = IMAGEMANAGER->findImage("itemCard");
	_clear._img->setCenter(x, y);
	this->x = x;
	this->y = y;
	_clear._rc = RectMakeCenter(x, y, 48, 48);

	return S_OK;
}

void clearobject1::update()
{
	_clear._rc = RectMakeCenter(0, 0, 0, 0);
	_clear._img->setX(0);
	_clear._img->setY(0);
}

void clearobject1::release()
{

}

void clearobject1::render()
{
	_clear._img->render(getMemDC());

}

bool clearobject1::clearcheck1(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &(player->getRECT()), &_clear._rc))
	{
		return true;
	}
	if (player->clear1)
	{
		return true;
	}
}
HRESULT clearobject2::init(float x, float y, int i)
{

	IMAGEMANAGER->addImage("itemOrb", "LostVikingsimage/NPC_item/itemOrb.bmp", 45, 45, true, RGB(255, 0, 255));
	if (i == 2) _clear._img = IMAGEMANAGER->findImage("itemOrb");
	_clear._img->setCenter(x, y);
	this->x = x;
	this->y = y;
	_clear._rc = RectMakeCenter(x, y, 48, 48);

	return S_OK;
}

void clearobject2::update()
{
	_clear._rc = RectMakeCenter(0, 0, 0, 0);
	_clear._img->setX(0);
	_clear._img->setY(0);
}

void clearobject2::release()
{

}

void clearobject2::render()
{
	_clear._img->render(getMemDC());
}

bool clearobject2::clearcheck2(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &(player->getRECT()), &_clear._rc))
	{
		return true;
	}
	if (player->clear2)
	{
		return true;
	}
}

