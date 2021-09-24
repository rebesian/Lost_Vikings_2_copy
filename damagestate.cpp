#include "stdafx.h"
#include "damagestate.h"
#include "player.h"
#include "pixelCollision.h"
#include "fallingstate.h"
statepatten * damagestate::handleInput(player * _player)
{
	if (_player->_pix->headcheck() || index == 10)
	{
		return new fallingstate;
	}
	return nullptr;
}

void damagestate::update(player * _player)
{

	count++;
	if (count % 3 == 0) {
		if (_player->isRight) {
			_player->setX(_player->getX() - 3);
			_player->setY(_player->getY() - 3);
			_player->setX(_player->_pix->leftcollision());
			_player->setY(_player->_pix->downcollision());
		}
		else
		{
			_player->setX(_player->getX() + 3);
			_player->setY(_player->getY() - 3);
			_player->setX(_player->_pix->rightcollision());
			_player->setY(_player->_pix->downcollision());
		}
		index++;
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
	}
}

void damagestate::enter(player * _player, int character)
{
	count = 0;
	index = 0;
	_character = character;
	_present = _player->getpresent();
	_player->sethp(_player->gethp() - 1);
	if (_character == 0) {
		_player->setimg(IMAGEMANAGER->findImage("ErikDamageDefault"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 87, 90);
		_player->setRECT(_rc);
		if (_player->isRight) {
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->getimg()->setFrameX(1);
			_player->getimg()->setFrameY(0);
		}
	}
	if (_character == 1)
	{
		_player->setimg(IMAGEMANAGER->findImage("BaleogDamageDefault"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
		if (_player->isRight) {
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->getimg()->setFrameX(1);
			_player->getimg()->setFrameY(0);
		}
	}

	if (_character == 2)
	{
		_player->setimg(IMAGEMANAGER->findImage("OlafDamage"));
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
}
