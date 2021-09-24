#include "stdafx.h"
#include "cannonbullet.h"
#include "player.h"

HRESULT cannonbullet::init(float x, float y, float width, float height, float bulletx, float bullety ,int i)
{
	char name[20];
	sprintf_s(name, "enemyBomb%d", i);
	img = IMAGEMANAGER->addImage(name, "LostVikingsimage/Enemy/enemyBomb.bmp", 45, 45,true, RGB(255, 0, 255));
	range_rc = RectMakeCenter(x, y, width, height);
	cannon_x = bulletx;
	cannon_y = bullety;
	bullet_x = cannon_x;
	isdamage = false;
	bullet = RectMake(0, 0, 0, 0);
	count = 0;
	isfire = false;
	return S_OK;
}

void cannonbullet::update()
{
	
	if (bullet_x < range_rc.left)
	{
		isfire = false;
		isdamage = false;
	}

	if (isfire)
	{
		bullet_x -= 2;
		if (!isdamage) {
			bullet = RectMakeCenter(bullet_x, cannon_y, 20, 20);
			img->setCenter(bullet_x, cannon_y);
		}
		else
		{
			bullet = RectMakeCenter(0, 0, 0, 0);
			img->setCenter(0, 0);
		}

	}
	else
	{
		bullet_x = cannon_x;
		bullet = RectMakeCenter(0, 0, 0, 0);
		img->setCenter(0, 0);
	}

}

void cannonbullet::release()
{

}

void cannonbullet::render()
{
	if (isfire)
	{
		img->render(getMemDC());
	}
}

void cannonbullet::rangeplayer(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &(player->getRECT()), &range_rc)&& !isfire)
	{
		bullet = RectMakeCenter(cannon_x, cannon_y ,20,20);
		isfire =true;
	}
}

bool cannonbullet::bulletdamage(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &(player->getRECT()), &bullet))
	{
		if (player->getcharacter() == 2 && !player->isTop&& player->getRECT().right > bullet.left)
		{
			isdamage = true;
			return false;
		}
		isdamage = true;
		return true;
	}
	return false;
}
