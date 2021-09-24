#include "stdafx.h"
#include "player.h"
#include "movestate.h"
#include "idlestate.h"
#include "jumpstate.h"
#include "fallingstate.h"
#include "pixelCollision.h"
#include "gargolee.h"
#include "damagestate.h"
statepatten* movestate::handleInput(player * _player)
{
	if (_present&& _character == 1 && (KEYMANAGER->isOnceKeyDown('A')) && ((KEYMANAGER->isStayKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_RIGHT)||(KEYMANAGER->isStayKeyDown(VK_UP)))))
	{
		return new gargolee;
	}
	if (_present&&(KEYMANAGER->isOnceKeyUp(VK_LEFT)  || KEYMANAGER->isOnceKeyUp(VK_RIGHT)))
	{
		return new idlestate;
	}										//캐릭터 에릭일때만 점프
	if (_present&& (KEYMANAGER->isOnceKeyDown(VK_SPACE) && (_character==0)))
	{
		return new jumpstate;
	}
	if (_player->_pix->groundcheck()&&!_player->wall && _player->elevator == 255)
	{
		return new fallingstate;
	}
	if (_player->damage || _player->bullet1 || _player->bullet2 || _player->fire)
	{
		return new damagestate;
	}
	return nullptr;
}

void movestate::update(player * _player)
{
	count++;
	//캐릭터가 에릭일때
	_present = _player->getpresent();
	if (_character == 0) {
		
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);

		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player->isRight = false;
			_player->setX(_player->getX() - 5);
			if (_player->door) _player->setX(_player->getX() + (_player->doorrc.right -_player->getRECT().left)+7);
			if (_player->bottenbox) _player->setX(_player->getX() + (_player->bottenboxrc.right -_player->getRECT().left) + 7);
			_player->setX(_player->_pix->leftcollision());
			_player->setY(_player->_pix->downcollision());
			if ((_player->getindex() < 0) || (_player->getindex() > 8))
				_player->setindex(7);
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player->isRight = true;
			_player->setX(_player->getX() + 5);
			if (_player->door) _player->setX(_player->getX() - (_player->getRECT().right - _player->doorrc.left) - 7);
			if (_player->bottenbox) _player->setX(_player->getX() - (_player->getRECT().right - _player->bottenboxrc.left) - 7);
			_player->setX(_player->_pix->rightcollision());
			_player->setY(_player->_pix->downcollision());
			if ((_player->getindex() < 0) || (_player->getindex() > 8))
				_player->setindex(0);

		}
		if (count % 5 == 0)
		{
			if (_player->isRight) {
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(0);
				_player->setindex(_player->getindex() + 1);
				count = 0;
			}
			else
			{
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(1);
				_player->setindex(_player->getindex() - 1);
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
			_player->setX(_player->getX() - 5);
			if (_player->door) _player->setX(_player->getX() + (_player->doorrc.right - _player->getRECT().left) + 7);
			if (_player->bottenbox) _player->setX(_player->getX() + (_player->bottenboxrc.right - _player->getRECT().left) + 7);
			_player->setX(_player->_pix->leftcollision());
			_player->setY(_player->_pix->downcollision());
			if ((_player->getindex() < 0) || (_player->getindex() > 8))
				_player->setindex(0);
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player->isRight = true;
			_player->setX(_player->getX() + 5);
			if (_player->door) _player->setX(_player->getX() - (_player->getRECT().right - _player->doorrc.left)-7);
			if (_player->bottenbox) _player->setX(_player->getX() - (_player->getRECT().right - _player->bottenboxrc.left)-7);
			_player->setX(_player->_pix->rightcollision());
			_player->setY(_player->_pix->downcollision());
			if ((_player->getindex() <0) || (_player->getindex() > 8))
				_player->setindex(0);
		}
		if (count % 5 == 0)
		{
			if (_player->isRight) {
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(0);
				_player->setindex(_player->getindex() + 1);
				count = 0;
			}
			else
			{
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(1);
				_player->setindex(_player->getindex() + 1);
				count = 0;
			}
		}
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
	}
	//캐릭터가 올라프일때
	if (_character == 2)
	{
		if (!(_player->isSmall) && !_player->isTop)
		{
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_player->isRight = false;
				_player->setX(_player->getX() - 5);
				if (_player->door) _player->setX(_player->getX() + (_player->doorrc.right - _player->getRECT().left) + 7);
				if (_player->bottenbox) _player->setX(_player->getX() + (_player->bottenboxrc.right - _player->getRECT().left) + 7);
				_player->setX(_player->_pix->leftcollision());
				_player->setY(_player->_pix->downcollision());
				if ((_player->getindex() < 0) || (_player->getindex() > 8))
					_player->setindex(0);
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_player->isRight = true;
				_player->setX(_player->getX() + 5);
				if (_player->door) _player->setX(_player->getX() - (_player->getRECT().right - _player->doorrc.left)-5);
				if (_player->bottenbox) _player->setX(_player->getX() - (_player->getRECT().right - _player->bottenboxrc.left)-5);
				_player->setX(_player->_pix->rightcollision());
				_player->setY(_player->_pix->downcollision());
				if ((_player->getindex() < 0) || (_player->getindex() > 8))
					_player->setindex(0);
			}
			if (count % 10 == 0)
			{
				if (_player->isRight) {
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(0);
					_player->setindex(_player->getindex() + 1);
					count = 0;
				}
				else
				{
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(1);
					_player->setindex(_player->getindex() + 1);
					count = 0;
				}
			}
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 89, 90);
			_player->setRECT(_rc);
		}
		else if (!(_player->isSmall) && _player->isTop)
		{
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_player->isRight = false;
				_player->setX(_player->getX() - 5);
				if (_player->door) _player->setX(_player->getX() + (_player->doorrc.right - _player->getRECT().left) + 7);
				if (_player->bottenbox) _player->setX(_player->getX() + (_player->bottenboxrc.right - _player->getRECT().left) + 7);
				_player->setX(_player->_pix->leftcollision());
				_player->setY(_player->_pix->downcollision());
				if ((_player->getindex() < 0) || (_player->getindex() > 8))
					_player->setindex(0);
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_player->isRight = true;
				_player->setX(_player->getX() + 5);
				if (_player->door) _player->setX(_player->getX() - (_player->getRECT().right - _player->doorrc.left)-7);
				if (_player->bottenbox) _player->setX(_player->getX() - (_player->getRECT().right - _player->bottenboxrc.left)-7);
				_player->setX(_player->_pix->rightcollision());
				_player->setY(_player->_pix->downcollision());
				if ((_player->getindex() < 0) || (_player->getindex() > 8))
					_player->setindex(0);
			}
			if (count % 10 == 0)
			{
				if (_player->isRight) {
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(0);
					_player->setindex(_player->getindex() + 1);
					count = 0;
				}
				else
				{
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(1);
					_player->setindex(_player->getindex() + 1);
					count = 0;
				}
			}
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 89, 90);
			_player->setRECT(_rc);
		}
		else{
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_player->isRight = false;
				_player->setX(_player->getX() - 5);
				if (_player->door) _player->setX(_player->getX() + (_player->doorrc.right - _player->getRECT().left) + 7);
				if (_player->bottenbox) _player->setX(_player->getX() + (_player->bottenboxrc.right - _player->getRECT().left) + 7);
				_player->setX(_player->_pix->leftcollision());
				_player->setY(_player->_pix->downcollision());
				if ((_player->getindex() < 0) || (_player->getindex() > 4))
					_player->setindex(0);
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_player->isRight = true;
				_player->setX(_player->getX() + 5);
				if (_player->door) _player->setX(_player->getX()- (_player->getRECT().right -_player->doorrc.left)-7);
				if (_player->bottenbox) _player->setX(_player->getX() - (_player->getRECT().right - _player->bottenboxrc.left)-7);
				_player->setX(_player->_pix->rightcollision());
				_player->setY(_player->_pix->downcollision());
				if ((_player->getindex() < 0) || (_player->getindex() > 4))
					_player->setindex(0);
			}
			if (count % 5 == 0)
			{
				if (_player->isRight) {
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(0);
					_player->setindex(_player->getindex() + 1);
					count = 0;
				}
				else
				{
					_player->getimg()->setFrameX(_player->getindex());
					_player->getimg()->setFrameY(1);
					_player->setindex(_player->getindex() + 1);
					count = 0;
				}
			}
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 67, 58);
			_player->setRECT(_rc);
		}
	}
}

void movestate::enter(player* _player, int character)
{
	count = 0;
	_character = character;
	if (_character == 0) {
		_player->setimg(IMAGEMANAGER->findImage("ErikRun"));
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
		if (_player->isRight) {
			_player->setindex(0);
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->setindex(7);
			_player->getimg()->setFrameX(7);
			_player->getimg()->setFrameY(1);
		}
	}
	if (_character == 1)
	{
		_player->setimg(IMAGEMANAGER->findImage("BaleogRun"));
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
		if (_player->isRight) {
			_player->setindex(0);
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->setindex(0);
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(1);
		}
	}
	if(_character == 2)
	{
		if (!(_player->isSmall) && !_player->isTop)
		{
			_player->setimg(IMAGEMANAGER->findImage("Olafmove"));
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 89, 90);
			_player->setRECT(_rc);
		}
		else if(!_player->isSmall && _player->isTop)
		{
			_player->setimg(IMAGEMANAGER->findImage("Olafmove2"));
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 89, 90);
			_player->setRECT(_rc);
		}
		else
		{
			_player->setimg(IMAGEMANAGER->findImage("SmallOlafmove"));
			_rc = RectMakeCenter(_player->getX(), _player->getY(), 67, 58);
			_player->setRECT(_rc);
		}

		if (_player->isRight) {
			_player->setindex(0);
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->setindex(0);
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(1);
		}
	}
}
