#include "stdafx.h"
#include "Swimstate.h"
#include "player.h"
#include "pixelCollision.h"
#include "jumpstate.h"
#include "idlestate.h"

statepatten * Swimstate::handleInput(player * _player)
{
	if (!_player->water)
	{
		return new jumpstate;
	}
	return nullptr;
}

void Swimstate::update(player * _player)
{
	count++;
	if (_character == 0) {

		if (_present  && KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player->setimg(IMAGEMANAGER->findImage("ErikSwimDash"));
			_player->isRight = false;
			_player->setX(_player->getX() - 3);
			_player->setX(_player->_pix->leftcollision());
			_player->setY(_player->_pix->downcollision());
		}
		if (_present  && KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player->setimg(IMAGEMANAGER->findImage("ErikSwimDash"));
			_player->isRight = true;
			_player->setX(_player->getX() + 3);
			_player->setX(_player->_pix->rightcollision());
			_player->setY(_player->_pix->downcollision());

		}

		if (_present  && KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_player->setimg(IMAGEMANAGER->findImage("ErikSwimDash"));
			_player->setY(_player->getY() - 3);
			_player->setY(_player->_pix->downcollision());
		}
		if (_present  && KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_player->setimg(IMAGEMANAGER->findImage("ErikSwimDash"));
			_player->setY(_player->getY() + 3);
			_player->setY(_player->_pix->downcollision());
		}

		if (_present && (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT) || (KEYMANAGER->isOnceKeyUp(VK_DOWN)) || _present && KEYMANAGER->isOnceKeyUp(VK_UP)))
		{
			_player->setimg(IMAGEMANAGER->findImage("ErikSwimIdle"));
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
	
		if (count % 15 == 0)
		{
			if (_player->getimg() == IMAGEMANAGER->findImage("ErikSwimDash")) {
				if (_player->isRight) {
					_player->setindex(_player->getindex() + 1);
					if ((_player->getindex() < 0) || (_player->getindex() > 9))
						_player->setindex(0);
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(0);
					count = 0;
				}
				else
				{
					_player->setindex(_player->getindex() - 1);
					if ((_player->getindex() < 0) || (_player->getindex() > 9))
						_player->setindex(9);
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(1);
					count = 0;
				}
			}
			if (_player->getimg() == IMAGEMANAGER->findImage("ErikSwimIdle"))
			{
				if (_player->isRight) {
					_player->setindex(_player->getindex() + 1);
					if ((_player->getindex() < 0) || (_player->getindex() > 3))
						_player->setindex(0);
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(0);
					count = 0;
				}
				else
				{
					_player->setindex(_player->getindex() - 1);
					if ((_player->getindex() < 0) || (_player->getindex() > 3))
						_player->setindex(3);
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(1);
					count = 0;
				}

			}

		}
		_player->setY(_player->getY() + 0.4f);
		_player->setY(_player->_pix->downcollision());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 93, 90);
		_player->setRECT(_rc);
	}
}

void Swimstate::enter(player * _player, int character)
{
	count = 0;
	_character = character;
	_present = _player->getpresent();
	if (_character == 0) {
		_player->setimg(IMAGEMANAGER->findImage("ErikSwimDash"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 93, 90);
		_player->setRECT(_rc);
		if (_player->isRight) {
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->getimg()->setFrameX(9);
			_player->getimg()->setFrameY(1);
		}
	}
}
