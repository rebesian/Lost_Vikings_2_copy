#include "stdafx.h"
#include "objectManager.h"
#include "player.h"

HRESULT objectManager::init()
{
	_pushbottencheck = 255;
	opendoor = clear = false;
	setobject();
	return S_OK;
}

void objectManager::update()
{

	_wall.wallgroudcheck(_bottenground ,_ground[0], _ground[1]);
	_wall.update();
	if (_pushbottencheck == 0 && KEYMANAGER->isOnceKeyDown('A'))
	{
		_bottenground.update();
		_wall.wallleft = 0;
		_wall.wallright = 0;
	}
	if (_pushbottencheck == 1 && KEYMANAGER->isOnceKeyDown('A'))
	{
		_bottenbox.update();
	}
	if (opendoor)
	{
		_door.update();
	}
	if (presentelevator != 255)
	{
		_elevator[presentelevator].update();
	}
	for (int i = 0; i < 3; i++)
	{
		_fire[i].update();
	}
	_npc.update();
}

void objectManager::release()
{

}

void objectManager::render()
{

	for (int i = 0; i < 5; i++)
	{
		_elevator[i].render();
	}

	for (int i = 0; i < 2; i++)
	{
		_pushbotten[i].render();
	}
	for (int i = 0; i < 3; i++)
	{
		_fire[i].render();
	}
	if(KEYMANAGER->isToggleKey(VK_TAB))
	for (int i = 0; i < 8; i++)
	{
		_labber[i].render();
	}
	_wall.render();
	_bottenground.render();
	_bottenbox.render();
	_door.render();
	_npc.render();
}

//모든 오브젝트 충돌체크하는곳
int objectManager::labbercheck(player * player)
{
	for (int i = 0; i < 8; i++) {
		if (IntersectRect(&temp, &(player->getRECT()), &(_labber[i].getRect())))
		{
			return _labber[i].getnumber();
		}
	}
	return 255;
}
int objectManager::ropecheck(player * player)
{
	for (int i = 0; i < 4; i++) {
		if (IntersectRect(&temp, &(player->getRECT()), &(_rope[i].getRect())))
		{
			
			return _rope[i].getnumber();
		}
	}
	return 255;
}
bool objectManager::doorcheck(player * player)
{
	if (IntersectRect(&temp, &(player->getRECT()), &(_door.getRect())))
	{
		player->doorrc = _door.getRect();
		return true;
	}
	return false;
}
bool objectManager::watercheck(player * player)
{
	if (IntersectRect(&temp, &(player->getRECT()), &(_water.getRect())))
	{
		return true;
	}
	return false;
}
bool objectManager::firecheck(player * player)
{
	for (int i = 0; i < 3; i++)
	{
		if (IntersectRect(&temp, &(player->getRECT()), &(_fire[i].getRect())))
		{
			return true;
		}
	}
	return false;
}
bool objectManager::npccheck(player * player)
{
	if (IntersectRect(&temp, &(player->getRECT()), &(_npc.getRect())))
	{
		if (player->clear1 && player->clear2 && KEYMANAGER->isOnceKeyDown('A'))
		{
			clear = true;
		}
		return true;
	}
	return false;
}
int objectManager::thorncheck(player * player)
{
	for (int i = 0; i < 12; i++) {
		if (IntersectRect(&temp, &(player->getRECT()), &(_thorn[i].getRect())))
		{
			player->sethp(0);
			return _thorn[i].getnumber();
		}
	}
	return 255;
}
bool objectManager::keyhomecheck(player * player)
{
	if (IntersectRect(&temp, &(player->getRECT()), &(_keyhome.getRect())))
	{
		if  (player->key && KEYMANAGER->isOnceKeyDown('A'))
		{
			opendoor = true;
		}
		return true;
	}
	return false;
}
int objectManager::elevatorcheck(player * player)
{
	for (int i = 0; i < 5; i++) {
		if (IntersectRect(&temp, &(player->getRECT()), &(_elevator[i].getRect())))
		{
			player->elevatorrc = _elevator[i].getRect();
			return _elevator[i].getnumber();
		}
	}
	return 255;
}
int objectManager::pushbottencheck(player * player)
{
	for (int i = 0; i < 2; i++) {
		if (IntersectRect(&temp, &(player->getRECT()), &(_pushbotten[i].getRect())))
		{
			_pushbottencheck = _pushbotten[i].getnumber();
			return _pushbotten[i].getnumber();
		}
	}
	return 255;
}
bool objectManager::wallcheck(player * player)
{
	if (IntersectRect(&temp, &(player->getRECT()), &(_wall.getRect())))
	{
		player->wallrc = _wall.getRect();
		player->wall_x = _wall.getX();
		player->wall_y = _wall.getY();
		return true;
	}

	return false;
}
bool objectManager::bottengroundcheck(player * player)
{
	if (IntersectRect(&temp, &(player->getRECT()), &(_bottenground.getRect())))
	{
		return true;
	}
	return false;
}
bool objectManager::bottenboxcheck(player * player)
{
	if (IntersectRect(&temp, &(player->getRECT()), &(_bottenbox.getRect())))
	{
		player->bottenboxrc = _bottenbox.getRect();
		return true;
	}
	return false;
}
int objectManager::bealogactioncheck(player * player)
{
	for (int i = 0; i < 2; i++) {
		if (IntersectRect(&temp, &(player->bealogrc), &(_bealogaction[i].getRect())))
		{
			player->bealogactionrc = _bealogaction[i].getRect();
			return _bealogaction[i].getnumber();
		}
	}

	return 255;
}
//오브젝트 세팅
void objectManager::setobject()
{
	_thorn[0].init(1221.5f, 1678 , 0);
	_thorn[1].init(1270.5f, 1678, 1);
	_thorn[2].init(1654.5f, 1678 , 2);
	_thorn[3].init(1702.6f ,1725.6f , 3);
	_thorn[4].init(1750.6f ,1774,4);
	_thorn[5].init(1798.5f ,1820.7f,5);
	_thorn[6].init(1846.6f ,1869.2f,6);
	_thorn[7].init(1894.5f , 1964.7f,7);
	_thorn[8].init(1942.4f, 1964.7f,8);
	_thorn[9].init(1990.6f, 1964.7f,9);
	_thorn[10].init(2038.5f, 1964.7f,10);
	_thorn[11].init(2086.6f, 1964.7f ,11);

	_rope[0].init(670  ,1491, 576, 12 , 0);
	_rope[1].init(1959, 387, 1074, 12 , 1);
	_rope[2].init(1682, 147, 946, 12 , 2);
	_rope[3].init(2544, 99, 480, 12, 3);

	_labber[0].init(1584, 998, 96, 220 , 0);
	_labber[1].init(1344,  517 , 96, 310 , 1);
	_labber[2].init (1248, 301.5f, 96, 165 , 2);
	_labber[3].init (1728, 301.5f, 96, 165,3);
	_labber[4].init (3072, 349.5f, 96, 262 ,4);
	_labber[5].init(2784,  633 ,96, 358, 5);
	_labber[6].init(2688 , 1165.5f ,96, 165,6);
	_labber[7].init(861, 742.5f, 96, 193, 7);


	_keyhome.init(2089.5f, 1461);

	_door.init(1992, 1461);

	_elevator[0].init(2496, 2133 ,0);
	_elevator[1].init(3072, 837 ,1);
	_elevator[2].init(2352, 981,2);
	_elevator[3].init(2064.5f, 981,3);
	_elevator[4].init(1004, 685, 4);

	_pushbotten[0].init(1364, 1168 , 0);
	_pushbotten[1].init(2852, 1984, 1);

	_wall.init(1151 , 1265.5f);
		
	_bottenground.init(1151, 1361.5f);
	_bottenbox.init(2591, 1987);
	_bealogaction[0].init(1751, 1361.5f ,0);
	_bealogaction[1].init(2135 ,739 ,1);

	_water.init(623, 1895);

	_ground[0].init(1138, 1638);
	_ground[1].init(1251, 1735);

	_fire[0].init(2711, 1396, 0);
	_fire[1].init(2854.5f, 1645.5f, 1);
	_fire[2].init(2711, 1873.5f, 2);

	_npc.init();

}
//벽밀기
void objectManager::setwall(player* player)
{
	float wall_x, wall_y;
	if (player->getRECT().bottom - 20 >= _wall.getRect().top)
	{
		if (player->getRECT().right < _wall.getRect().right)
		{
			wall_x = player->getRECT().right - _wall.getRect().left;
		}
		if (player->getRECT().left > _wall.getRect().left)
		{
			wall_x = player->getRECT().left - _wall.getRect().right;
		}
		_wall.setX(wall_x + _wall.getX());
	}
}
//엘레베이터 움직이기
void objectManager::setelevtor(player * player)
{
	presentelevator = player->elevator;
	if (player->getpresent()&& !player->_gargolee&&KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_elevator[presentelevator].setY(_elevator[presentelevator].getY() - 3);
	}
	if (player->getpresent() && !player->_gargolee &&KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_elevator[presentelevator].setY(_elevator[presentelevator].getY() + 3);
	}
}

