#include "stdafx.h"
#include "pirate.h"
#include "player.h"
HRESULT pirate::init()
{
	IMAGEMANAGER->addFrameImage("PirateMove","LostVikingsimage/Enemy/PirateMove.bmp", 180, 180, 2, 2, true,RGB(255,0,255));
	IMAGEMANAGER->addFrameImage("PirateAttack", "LostVikingsimage/Enemy/PirateAttack.bmp", 450, 180, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("EnemyDeathLtoR", "LostVikingsimage/Enemy/EnemyDeathLtoR.bmp", 450, 90, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("EnemyDeathRtoL", "LostVikingsimage/Enemy/EnemyDeathRtoL.bmp", 450, 90, 5, 1, true, RGB(255, 0, 255));
	isattack = isdamage = isdead= false;

	x = 1276;
	y = 912;

	_rc = RectMakeCenter(x, y, 60, 60);
	rangerc = RectMakeCenter(x, y, 110, 60);
	img=IMAGEMANAGER->findImage("PirateMove");
	img->setCenter(x, y);
	img->setFrameX(0);
	index = 0;
	isright = true;
	return S_OK;
}

void pirate::update()
{
	RECT temp;

	if (!isattack && !isdamage) {
		img = IMAGEMANAGER->findImage("PirateMove");
		state = MOVE;
		if (isright)
		{
			img->setFrameY(0);
			x += 1;
			if (x > 1421) isright = false;
		}
		else
		{
			img->setFrameY(1);
			x -= 1;
			if (x < 1111) isright = true;
		}
	}

	count++;
	if (count % 10 == 0) {
		if (state == MOVE)
		{
			if (isright) {

				if (index > 2) index = 0;
				img->setFrameX(index);
				index++;
			}
			else
			{
				if (index < 0) index = 1;
				img->setFrameX(index);
				index--;
			}
			rangerc = RectMakeCenter(x, y, 110, 60);
			_rc = RectMakeCenter(x, y, 60, 60);
		}
		if (state==ATTACK) {
			if (isright)
			{
				index++;
				img->setFrameX(index);
				if (index == 4)
				{
					attack_rc = RectMakeCenter(x + 20, y + 10, 50, 25);
				}
				if (index == 5)
				{
					attack_rc = RectMakeCenter(0, 0, 0, 0);
					isattack = false;
				}
			}
			else
			{
				index--;
				img->setFrameX(index);
				if (index == 0)
				{
					attack_rc = RectMakeCenter(x - 20, y + 10, 50, 25);
				}
				if (index == -1)
				{
					attack_rc = RectMakeCenter(0, 0, 0, 0);
					isattack = false;
				}
			}
			_rc = RectMakeCenter(x, y, 60, 60);
		}
		if (state==DAMAGE)
		{
			_rc = RectMakeCenter(0, 0, 0, 0);
			attack_rc = RectMakeCenter(0, 0, 0, 0);
			rangerc = RectMakeCenter(0, 0, 0, 0);
			if (isright)
			{
				img->setFrameX(index);
				index++;
				if (index >= 5) {
					img->setCenter(0, 0);
					x = 0, y = 0;
					index = 0;
				}
			}
			else
			{
				img->setFrameX(index);
				index--;
				if (index < -1) {
					img->setCenter(0, 0);
					x = 0, y = 0;
					index = 0;
				}
			}
		}
		count = 0;
		
	}

}

void pirate::release()
{

}

void pirate::render()
{

	img->frameRender(getMemDC(), x-45, y-45);
	//if (isattack)
	//{
	//	Rectangle(getMemDC(), attack_rc);
	//}


}

bool pirate::playerdamage(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &(player->getRECT()), &attack_rc))
	{
		return true;
	}
	return false;
}

void pirate::attackdamage(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &(player->attack), &_rc) || IntersectRect(&temp, &(player->bealogrc), &_rc))
	{
		if (isright)
		{
			index = 0;
			img = IMAGEMANAGER->findImage("EnemyDeathLtoR");
			img->setFrameX(0);
			img->setFrameY(0);
		}
		else
		{
			img = IMAGEMANAGER->findImage("EnemyDeathRtoL");
			index = 4;
			img->setFrameX(4);
			img->setFrameY(0);

		}
		state = DAMAGE;
		isdamage = true;
	}

}

void pirate::rangeplayer(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &(player->getRECT()), &rangerc)&& !isdamage && !isattack)
	{
		if (isright)
		{
			index = 0;
			img = IMAGEMANAGER->findImage("PirateAttack");
			img->setFrameX(0);
			img->setFrameY(0);
		}
		else
		{
			img = IMAGEMANAGER->findImage("PirateAttack");
			index = 4;
			img->setFrameX(4);
			img->setFrameY(0);

		}
		state = ATTACK;
		isattack = true;
	}
}
