#include "stdafx.h"
#include "HUD.h"


HRESULT HUD::init(image* hud ,float x ,float y)
{
	_x = x;
	_y = y;
	pointY = 61;

	_hudMode = false;

	_hud = hud;

	hp = IMAGEMANAGER->findImage("hp");
	hp1 = IMAGEMANAGER->findImage("hp1");
	hp2 = IMAGEMANAGER->findImage("hp2");
	
	//에릭 허드 
	if (_hud == IMAGEMANAGER->findImage("HUDone"))
	{
		_playerimg = IMAGEMANAGER->findImage("NoneErik");
		_point = IMAGEMANAGER->findImage("itempoint");
		pointX = 182;
	}
	//벨로그 허드 
	else if (_hud == IMAGEMANAGER->findImage("HUDtwo"))
	{
		_playerimg = IMAGEMANAGER->findImage("NoneBealog");
		_point = IMAGEMANAGER->findImage("itempoint");
		pointX = 156;
	}
	//올라프 허드
	else if(_hud== IMAGEMANAGER->findImage("HUDThree"))
	{
		_playerimg = IMAGEMANAGER->findImage("NoneOlaf");
		_point = IMAGEMANAGER->findImage("itempoint");
		pointX = 156;
	}
	//쓰레기 허드 
	else if (_hud == IMAGEMANAGER->findImage("trash"))
	{
		_point = IMAGEMANAGER->findImage("trashpoint");
		pointX = 5;
	}
	return S_OK;
}

void HUD::update(image* player)
{
	if (!(_hud == IMAGEMANAGER->findImage("trash")))
	{
		_playerimg = player;

		
		keyimg = IMAGEMANAGER->addImage("itemKey1", "LostVikingsimage/NPC_item/itemKey.bmp", 45, 45, true, RGB(255, 0, 255));
		clear1img = IMAGEMANAGER->addImage("clear2", "LostVikingsimage/NPC_item/itemCard.bmp", 48, 48, true, RGB(255, 0, 255));
		clear2img = IMAGEMANAGER->addImage("clear3", "LostVikingsimage/NPC_item/itemOrb.bmp", 45, 45, true, RGB(255, 0, 255));


	}
	if (_hud == IMAGEMANAGER->findImage("HUDone") && _player->gethp() == 0)
	{
		_playerimg = IMAGEMANAGER->findImage("DeadErik");
	}
	if (_hud == IMAGEMANAGER->findImage("HUDtwo") && _player->gethp() == 0)
	{
		_playerimg = IMAGEMANAGER->findImage("DeadBealog");
	}
	if (_hud == IMAGEMANAGER->findImage("HUDThree") && _player->gethp() == 0)
	{
		_playerimg = IMAGEMANAGER->findImage("DeadOlaf");
	}
	if (_hudMode && present)
	{
		if (_hud == IMAGEMANAGER->findImage("HUDone"))
		{
			if (  pointX< 304   ) {
				_point = IMAGEMANAGER->findImage("itempoint");
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					pointX -= 61;
					if(181 > pointX) pointX = 740;
				}
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					pointX += 61;
					if (pointX > 245)  pointX = 460;
			
				}
			}
			else if (459 < pointX && pointX < 581) {
				_point = IMAGEMANAGER->findImage("itempoint");
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					pointX -= 61;
					if (459 > pointX) pointX = 182;
				}
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					pointX += 61;
					if (pointX > 581)  pointX = 740;
				}
			}
			else if (739 < pointX && pointX <862) {
				_point = IMAGEMANAGER->findImage("itempoint");
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					pointX -= 61;
					if (739 > pointX) pointX = 521;
				}
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					pointX += 61;
					if (pointX > 861)  pointX = 869;

				}
			}
			else if (868 < pointX)
			{
				_point = IMAGEMANAGER->findImage("trashpoint");
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					pointX = 801;
				}
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					pointX = 182;
				}
			}
		}

		else if (_hud == IMAGEMANAGER->findImage("HUDtwo"))
		{
			
			if (pointX < 96) {
		
				_point = IMAGEMANAGER->findImage("itempoint");
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					pointX -= 61;
					if (-149 > pointX) pointX = 563;
				}
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					pointX += 61;
					if (pointX > -1) pointX = 156;
				}
			}

			if (  155 <pointX &&pointX < 277) {
		
				_point = IMAGEMANAGER->findImage("itempoint");
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{

					pointX -= 61;
					if (pointX < 155) pointX = -61;
			
				}
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					pointX += 61;
					if (pointX >277)pointX = 436;
			
				}
			}
			if ( 435<pointX && pointX < 557) {
				_point = IMAGEMANAGER->findImage("itempoint");
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					pointX -= 61;
					if (pointX < 435)pointX = 217;
				}
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					pointX += 61;
					if (pointX > 557) pointX = 563;
				}
			}
			if (pointX > 559) {
				_point = IMAGEMANAGER->findImage("trashpoint");
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					pointX = 497;
				}
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					pointX = -122;
				}
			}
		}

		else if (_hud == IMAGEMANAGER->findImage("HUDThree"))
		{
			
		if (pointX < -277) {
			_point = IMAGEMANAGER->findImage("itempoint");
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				pointX -= 61;
				if (-404 > pointX) pointX = 283;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				pointX += 61;
				if (pointX > -341) pointX = -124;
			}
		}

		if (-125 < pointX &&pointX < -60) {
			_point = IMAGEMANAGER->findImage("itempoint");
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{

				pointX -= 61;
				if (pointX < -125) pointX = -341;

			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				pointX += 61;
				if (pointX > -3)pointX = 156;

			}
		}
		if (155 < pointX &&pointX < 277) {
			_point = IMAGEMANAGER->findImage("itempoint");
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				pointX -= 61;
				if (pointX < 154)pointX = -63;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				pointX += 61;
				if (pointX > 277) pointX = 283;
			}
		}
		if (pointX > 279) {
			_point = IMAGEMANAGER->findImage("trashpoint");
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				pointX = 217;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				pointX = -402;
			}
		}
		}

		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			pointY -= 61;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			pointY += 61;
		}
	}

}

void HUD::release()
{

}

void HUD::render()
{
	int count, alpha;
	count = 0;
	alpha = 255;

	if (_hudMode) {
		count++;
		if (count % 10 == 0) {
			if (alpha == 100)
				alpha = 255;
			else alpha = 100;
			count = 0;
		}
	}
	else
		alpha = 255;

	if (_hud == IMAGEMANAGER->findImage("trash"))
	{
		_hud->render(getMemDC(), CAMERAMANEGER->getX() + _x, CAMERAMANEGER->getY() + _y);
		if (present&&_hudMode)
		{
			_point->alphaRender(getMemDC(), CAMERAMANEGER->getX() + _x + 5, CAMERAMANEGER->getY() + _y + 57, alpha);
		}
	}

	else if (_hud == IMAGEMANAGER->findImage("HUDone"))
	{
		_hud->render(getMemDC(), CAMERAMANEGER->getX() + _x, CAMERAMANEGER->getY() + _y);
		_playerimg->render(getMemDC(), CAMERAMANEGER->getX() + _x + 61, CAMERAMANEGER->getY() + _y + 57);

		if (present&&_hudMode) {
			_point->alphaRender(getMemDC(), CAMERAMANEGER->getX() + _x + pointX, CAMERAMANEGER->getY() + _y + pointY, alpha);
		}

		else
			_point->render(getMemDC(), CAMERAMANEGER->getX() + _x + pointX, CAMERAMANEGER->getY() + _y + pointY);

		if (_player->gethp() >= 1 )
		hp->render(getMemDC(), CAMERAMANEGER->getX() + _x + 66, CAMERAMANEGER->getY() + _y + 161);
		if (_player->gethp() >= 2)
		hp1->render(getMemDC(), CAMERAMANEGER->getX() + _x + 86, CAMERAMANEGER->getY() + _y + 161);
		if(_player->gethp() == 3)
		hp2->render(getMemDC(), CAMERAMANEGER->getX() + _x + 106, CAMERAMANEGER->getY() + _y + 161);
	}

	else
	{
		_hud->render(getMemDC(), CAMERAMANEGER->getX() + _x, CAMERAMANEGER->getY() + _y);
		_playerimg->render(getMemDC(), CAMERAMANEGER->getX() + _x + 31, CAMERAMANEGER->getY() + _y + 57);
		if (_player->key)
		{
			keyimg->render(getMemDC(), CAMERAMANEGER->getX() + _x + pointX , CAMERAMANEGER->getY() + _y + pointY);
		}
		if (_player->clear1)
		{
			clear1img->render(getMemDC(), CAMERAMANEGER->getX() + _x + pointX + 61, CAMERAMANEGER->getY() + _y + pointY);
		}
		if (_player->clear2)
		{
			clear2img->render(getMemDC(), CAMERAMANEGER->getX() + _x + pointX , CAMERAMANEGER->getY() + _y + pointY +61);
		}
		if (present&&_hudMode) {
			_point->alphaRender(getMemDC(), CAMERAMANEGER->getX() + _x + pointX, CAMERAMANEGER->getY() + _y + pointY, alpha);
		}
		else
			_point->render(getMemDC(), CAMERAMANEGER->getX() + _x + pointX, CAMERAMANEGER->getY() + _y + pointY);
		if (_player->gethp() >= 1)
		hp->render(getMemDC(), CAMERAMANEGER->getX() + _x + 36, CAMERAMANEGER->getY() + _y + 161);
		if (_player->gethp() >= 2)
		hp1->render(getMemDC(), CAMERAMANEGER->getX() + _x + 56, CAMERAMANEGER->getY() + _y + 161);
		if (_player->gethp() == 3)
		hp2->render(getMemDC(), CAMERAMANEGER->getX() + _x + 76, CAMERAMANEGER->getY() + _y + 161);
	}
}

