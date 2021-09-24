#include "stdafx.h"
#include "fallingstate.h"
#include "idlestate.h"
#include "player.h"
#include "playGround.h"
#include "playerManager.h"
#include "Swimstate.h"
#include "deadstate.h"
#include "damagestate.h"
statepatten * fallingstate::handleInput(player* _player)
{
	if (!(_player->_pix->groundcheck()) || _player->wall || _player->elevator != 255)
	{
		return new idlestate;
	}
	if (_character == 0 && _player->water)
	{
		return new Swimstate;
	}
	if ((_character == 1 || _character == 2) && _player->water)
	{
		_player->sethp(0);
		return new deadstate;
	}
	if (_player->gethp() == 0)
	{
		return new deadstate;
	}
	if (_player->damage||_player->bullet1|| _player->bullet2 ||_player->fire)
	{
		return new damagestate;
	}
	return nullptr;
}

void fallingstate::update(player * _player)
{
	_present = _player->getpresent();
	count++;
	_player->setY(_player->getY()-jumpPower);
	jumpPower -= gravity;
	//에릭일때
	if (_character == 0) {

		if (_present && KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player->isRight = false;
			_player->setX(_player->getX() - 5);
			_player->setX(_player->_pix->leftcollision());
		}
		if (_present && KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player->isRight = true;
			_player->setX(_player->getX() + 5 );
			_player->setX(_player->_pix->rightcollision());
		}

		if (count % 5 == 0)
		{
			if (_player->isRight) {
				if (_player->getindex()> 4 && (gravity != 0))
					_player->setindex(4);

				_player->getimg()->setFrameY(0);
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() + 1);
			}
			else {
				if (_player->getindex() < 0   && (gravity != 0))
					_player->setindex(0);
				_player->getimg()->setFrameY(1);
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() - 1);

			}
			count = 0;
		}
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
	}


	//벨로그일때
	if (_character == 1)
	{
		if (_present && KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player->isRight = false;
			_player->setX(_player->getX() - 5);
			_player->setX(_player->_pix->leftcollision());
		}
		if (_present && KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player->isRight = true;
			_player->setX(_player->getX() + 5);
			_player->setX(_player->_pix->rightcollision());
		}
		if (count % 5 == 0)
		{
			if (_player->isRight) {
				if (_player->getindex() > 1 && (gravity != 0))
					_player->setindex(0);
				_player->getimg()->setFrameY(0);
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() + 1);
			}
			else {
				if (_player->getindex() >1 && (gravity != 0))
					_player->setindex(0);
				_player->getimg()->setFrameY(1);
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() + 1);

			}
			count = 0;
		}
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 82, 90);
		_player->setRECT(_rc);
	}

	//올라프일때
	if (_character == 2)
	{
		if (!_player->isTop) {
			if (_present && KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_player->isRight = false;
				_player->setX(_player->getX() - 5);
				_player->setX(_player->_pix->leftcollision());
			}
			if (_present && KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_player->isRight = true;
				_player->setX(_player->getX() + 5);
				_player->setX(_player->_pix->rightcollision());
			}

			if (count % 5 == 0)
			{
				if (_player->isRight) {
					if (_player->getindex() > 5 && (gravity != 0))
						_player->setindex(3);

					_player->getimg()->setFrameY(0);
					_player->getimg()->setFrameX(_player->getindex());
					_player->setindex(_player->getindex() + 1);
				}
				else {
					if (_player->getindex() > 5 && (gravity != 0))
						_player->setindex(3);
					_player->getimg()->setFrameY(1);
					_player->getimg()->setFrameX(_player->getindex());
					_player->setindex(_player->getindex() + 1);

				}
				count = 0;
			}
		}
		else
		{
			jumpPower = -2;
			gravity = 0;
			if (_present && KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_player->setimg(IMAGEMANAGER->findImage("OlafDown"));
				_player->isRight = false;
				_player->setX(_player->getX() - 5);
				_player->setX(_player->_pix->leftcollision());
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(1);
			}
			if (_present && KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_player->setimg(IMAGEMANAGER->findImage("OlafDown"));
				_player->isRight = true;
				_player->setX(_player->getX() + 5);
				_player->setX(_player->_pix->rightcollision());
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(0);
			}

			if (count % 5 == 0)
			{
				if (_player->isRight) {
					if (_player->getindex() > 1)
						_player->setindex(0);

					_player->getimg()->setFrameY(0);
					_player->getimg()->setFrameX(_player->getindex());
					_player->setindex(_player->getindex() + 1);
				}
				else {
					if (_player->getindex() > 1)
						_player->setindex(0);
					_player->getimg()->setFrameY(1);
					_player->getimg()->setFrameX(_player->getindex());
					_player->setindex(_player->getindex() + 1);

				}
				count = 0;
			}
		}
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 91, 90);
		_player->setRECT(_rc);
	}
	

	if (!(_player->_pix->groundcheck()))
	{
		jumpPower = 0;
		gravity = 0;
	}
	
}

void fallingstate::enter(player* _player, int character)
{
	count = jumpPower = 0;
	gravity = 0.08f;
	_character = character;
	_present = _player->getpresent();
	if (_character == 0)
	{
		_player->setimg(IMAGEMANAGER->findImage("ErikJump"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);

		if (_player->isRight)
		{
			_player->setindex(1);
			_player->getimg()->setFrameX(1);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->setindex(2);
			_player->getimg()->setFrameX(2);
			_player->getimg()->setFrameY(1);
		}
	}
	if (_character == 1)
	{
		_player->setimg(IMAGEMANAGER->findImage("BaleogfallingIdle"));
		_player->setindex(0);
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 82, 90);
		_player->setRECT(_rc);

		if (_player->isRight)
		{
			_player->getimg()->setFrameY(0);
			_player->getimg()->setFrameX(0);
	
		}
		else
		{
			_player->getimg()->setFrameY(1);
			_player->getimg()->setFrameX(0);
		}
	}
	if (_character == 2)
	{
		if (!_player->isTop) {
			_player->setimg(IMAGEMANAGER->findImage("OlafDownfast"));
			_player->setindex(0);
			_player->getimg()->setCenter(_player->getX(), _player->getY());
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 91, 90);
			_player->setRECT(_rc);

			if (_player->isRight)
			{
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(0);
			}
			else
			{
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(1);
			}
		}
		else
		{
			_player->setimg(IMAGEMANAGER->findImage("OlafDownIdle"));
			_player->setindex(0);
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 91, 90);
			_player->setRECT(_rc);
			if (_player->isRight)
			{
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

