#include "stdafx.h"
#include "ropestate.h"
#include "player.h"
#include "fallingstate.h"

statepatten * ropestate::handleInput(player * _player)
{
	if (_present && KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		return new fallingstate;
	}
	return nullptr;
}

void ropestate::update(player * _player)
{
	
	count++;
	if (_character == 0) {

		if (_present && KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player->isRight = false;
			_player->setX(_player->getX() - 3);
	
			_player->setindex(_player->getindex() - 1);
			if ((_player->getindex() < 0) || (_player->getindex() > 8))
				_player->setindex(8);
		}
		if (_present && KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player->isRight = true;
			_player->setX(_player->getX() + 3);
	
			_player->setindex(_player->getindex() + 1);
			if ((_player->getindex() < 0) || (_player->getindex() > 8))
				_player->setindex(0);
		}
		if (count % 10 == 0)
		{
			if (_player->isRight) {
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(0);
				count = 0;
			}
			else
			{
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(1);
				count = 0;
			}
		}
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
	}
	//캐릭터가 벨로그일때
	if (_character == 1)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player->isRight = false;
			_player->setX(_player->getX() - 3);
			_player->setindex(_player->getindex() + 1);
			if ((_player->getindex() < 0) || (_player->getindex() > 6))
				_player->setindex(0);
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player->isRight = true;
			_player->setX(_player->getX() + 3);
			_player->setindex(_player->getindex() + 1);
			if ((_player->getindex() < 0) || (_player->getindex() > 6))
				_player->setindex(0);
		}
		if (count % 15 == 0)
		{
			if (_player->isRight) {
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(0);
				count = 0;
			}
			else
			{
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(1);
				count = 0;
			}
		}
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
	}
}

void ropestate::enter(player * _player, int character)
{
	count = 0;
	_character = character;
	_present = _player->getpresent();
	if (_character == 0) {
		_player->setimg(IMAGEMANAGER->findImage("ErikRope"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
		if (_player->isRight) {
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->getimg()->setFrameX(8);
			_player->getimg()->setFrameY(1);
		}
	}
	if (_character == 1)
	{
		_player->setimg(IMAGEMANAGER->findImage("BaleogRopeMove"));
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
}
