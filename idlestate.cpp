#include "stdafx.h"
#include "idlestate.h"
#include "player.h"
#include "pixelCollision.h"
#include "movestate.h"
#include "jumpstate.h"
#include "fallingstate.h"
#include "smallolaf.h"
#include "ropestate.h"
#include "labberstate.h"
#include "bealogatteck.h"
#include "gargolee.h"
#include "damagestate.h"
statepatten* idlestate::handleInput(player * _player)
{
	if (_present&& _character == 1 && (KEYMANAGER->isOnceKeyDown('A')) && (KEYMANAGER->isStayKeyDown(VK_UP)))
	{
		return new gargolee;
	}
	if ((_present) &&((KEYMANAGER->isStayKeyDown(VK_LEFT)||KEYMANAGER->isStayKeyDown(VK_RIGHT))))
	{
		return new movestate;
	}
	if ((_present) && (KEYMANAGER->isOnceKeyDown(VK_SPACE)&&(_character==0)))
	{
		return new jumpstate;
	}
	if ((_present) && (_character == 2) && (KEYMANAGER->isOnceKeyDown(VK_DOWN))&& _player->elevator==255)
	{
		return new smallolaf;
	}
	if (_player->_pix->groundcheck() && !_player->wall && _player->elevator==255)
	{
		return new fallingstate;
	}
	if (_present && KEYMANAGER->isOnceKeyDown(VK_UP) && _player->rope != 255 &&(_character==0 ||_character==1))
	{
		return new ropestate;
	}
	if (_present && _player->labber != 255 && (KEYMANAGER->isOnceKeyDown(VK_DOWN)||(KEYMANAGER->isOnceKeyDown('Y'))))
	{
		return new labberstate;
	}
	if (_present && _character == 1 && (KEYMANAGER->isOnceKeyDown('W')))
	{
		return new bealogatteck;
	}
	if (_player->damage || _player->bullet1 || _player->bullet2 || _player->fire)
	{
		return new damagestate;
	}
	return nullptr;
}

void idlestate::update(player* _player)
{
	count++;
	

	//캐릭터가 에릭일때
	if (_character == 0) {
		if (_player->elevator != 255)
		{
			_player->setY(_player->getY() - (_player->getRECT().bottom - _player->elevatorrc.top)+5);
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 87, 90);
			_player->setRECT(_rc);
		}
		_player->setY(_player->_pix->downcollision());
		if (count % 10 == 0)
		{
			if (_player->isRight) {
				if (_player->getindex() > 4) _player->setindex(0);
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() + 1);
				count = 0;
			}
			else
			{
				if (_player->getindex() > 4) _player->setindex(0);
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() + 1);
				count = 0;
			}
		}
	}
	//캐릭터가 벨로그일때
	if (_character == 1)
	{
		if (_player->elevator != 255)
		{
			_player->setY(_player->getY() - (_player->getRECT().bottom - _player->elevatorrc.top) + 5);
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 87, 90);
			_player->setRECT(_rc);
		}
		_player->setY(_player->_pix->downcollision());
		if (count % 10 == 0)
		{
			if (_player->isRight) {
				if (_player->getindex() > 4) _player->setindex(0);
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() + 1);
				count = 0;
			}
			else
			{
				if (_player->getindex() > 4) _player->setindex(0);
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() + 1);
				count = 0;
			}
		}
	}
	//캐릭터가 올라프일때
	if (_character == 2)
	{
		if (_player->elevator != 255)
		{
			_player->setY(_player->getY() - (_player->getRECT().bottom - _player->elevatorrc.top) + 5);
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 87, 90);
			_player->setRECT(_rc);
		}
		_player->setY(_player->_pix->downcollision());
		if (_present && KEYMANAGER->isOnceKeyDown('W'))
		{
			if (_player->isTop == true) _player->isTop = false;
			else _player->isTop = true;
		}
		//w키누르면 방패들기로 상태변환
		if (_present && _player->isTop &&!_player->isSmall)
		{
			_player->setimg(IMAGEMANAGER->findImage("OlafTopIdle"));
			_player->getimg()->setCenter(_player->getX(), _player->getY());
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 88, 90);
			_player->setRECT(_rc);
			if (_player->isRight) {
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(0);
			}
			else
			{
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(1);
			}
		}
		if (_present && !_player->isTop &&!_player->isSmall)
		{
			_player->setimg(IMAGEMANAGER->findImage("OlafIDLE"));
			_player->getimg()->setCenter(_player->getX(), _player->getY());
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 88, 90);
			_player->setRECT(_rc);
			if (_player->isRight) {
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(0);
			}
			else
			{
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(1);
			}
		}
		if(_present && _player->isSmall)
		{
			_player->setimg(IMAGEMANAGER->findImage("Olafsmall"));
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 67, 58);
			_player->setRECT(_rc);
			if (_player->isRight) {
				_player->getimg()->setFrameX(3);
				_player->getimg()->setFrameY(0);
			}
			else
			{
				_player->getimg()->setFrameX(3);
				_player->getimg()->setFrameY(1);
			}
			if (KEYMANAGER->isOnceKeyDown('T'))
			{
				_player->isSmall = false;
				_player->setimg(IMAGEMANAGER->findImage("OlafIDLE"));
				_rc = RectMakeCenter(_player->getX(), _player->getY(), 88, 90);
				_player->setRECT(_rc);
				if (_player->isRight) {
					_player->getimg()->setFrameX(0);
					_player->getimg()->setFrameY(0);
				}
				else
				{
					_player->getimg()->setFrameX(0);
					_player->getimg()->setFrameY(1);
				}
			}

		}
	}
	_present = _player->getpresent();
	
}

void idlestate::enter(player * _player,int character)
{
	count = 0;
	_character = character;
	_present = _player->getpresent();
	if (_character == 0) {
		_player->setimg(IMAGEMANAGER->findImage("ErikIdle"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 87, 90);
		_player->setRECT(_rc);
		if (_player->isRight) {
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->getimg()->setFrameX(4);
			_player->getimg()->setFrameY(1);
		}
	}
	if (_character == 1)
	{
		_player->setimg(IMAGEMANAGER->findImage("BaleogIdle"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);

		if (_player->isRight) {
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(1);
		}
	}

	if (_character == 2)
	{
		if (!(_player->isSmall)) {
			_player->setimg(IMAGEMANAGER->findImage("OlafIDLE"));
			_player->getimg()->setCenter(_player->getX(), _player->getY());
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 88, 90);
			_player->setRECT(_rc);
		}
		else {
			_player->setimg(IMAGEMANAGER->findImage("Olafsmall"));
			_rc = RectMakeCenter(_player->getX(), _player->getY() + 15, 67, 58);
			_player->setRECT(_rc);
		}
		if (_player->isRight) {
			_player->getimg()->setFrameX(3);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->getimg()->setFrameX(3);
			_player->getimg()->setFrameY(1);
		}

	
	}
}

