#include "stdafx.h"
#include "jumpstate.h"
#include "player.h"
#include "fallingstate.h"
#include "pixelCollision.h"
#include "damagestate.h"
statepatten * jumpstate::handleInput(player * _player)
{
	if (jumpPower <= 0.0f|| _player->_pix->headcheck())
	{
		return new fallingstate;
	}
	if (_player->damage || _player->bullet1 || _player->bullet2 || _player->fire)
	{
		return new damagestate;
	}
	return nullptr;
}

void jumpstate::update(player * _player)
{
	count++;
	_player->setY(_player->getY() - jumpPower);
	jumpPower -= gravity;
	//에릭일때만 혹시몰라 예외처리
	if (_character == 0) {
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player->isRight = false;
			_player->setX(_player->_pix->leftcollision());
			_player->setX(_player->getX() - 5);
		//	_player->setX(_player->_pix->rightcollision());
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player->isRight = true;
			_player->setX(_player->_pix->rightcollision());
			_player->setX(_player->getX() + 5);
			//_player->setX(_player->_pix->rightcollision());
		}
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)&& jumpcount<1)
		{
			jumpPower = 7.0f;
			++jumpcount;
		}
		if (count % 10 == 0)
		{
			if (_player->isRight) {
				if (_player->getindex() > 0)
					_player->setindex(0);
				
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(0);
				_player->setindex(_player->getindex() + 1);
			}
			else {
				if (_player->getindex()<3)
				{
					_player->setindex(3);
				}
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(1);
				_player->setindex(_player->getindex() - 1);
			}
		}
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
	}
	
} 

void jumpstate::enter(player * _player, int character)
{
	count = 0;
	jumpcount = 0;
	jumpPower = 5.0f;
	gravity = 0.08f;
	_character = character;
	if (_character == 0) {
		_player->setimg(IMAGEMANAGER->findImage("ErikJump"));
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
		if (_player->isRight)
		{
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
			_player->setindex(0);
		}
		else
		{
			_player->getimg()->setFrameX(3);
			_player->getimg()->setFrameY(1);
			_player->setindex(3);
		}
	}
}

