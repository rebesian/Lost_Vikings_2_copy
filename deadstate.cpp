#include "stdafx.h"
#include "deadstate.h"
#include "player.h"

statepatten * deadstate::handleInput(player * _player)
{
	return nullptr;
}

void deadstate::update(player * _player)
{
	count++;
	if (_character == 0) {
		if (count % 10 == 0)
		{
			if (_player->isRight) {
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() + 1);
				if (_player->getindex() > 3) _player->setindex(3);
				count = 0;
			}
			else
			{
				_player->getimg()->setFrameX(_player->getindex());
				_player->setindex(_player->getindex() - 1);
				if (_player->getindex() < 0) _player->setindex(0);
				count = 0;
			}
		}
	}
	if (_character == 1 || _character==2) {
		if (count % 10 == 0)
		{
			_player->getimg()->setFrameX(_player->getindex());
			_player->setindex(_player->getindex() + 1);
			if (_player->getindex() > 3) _player->setindex(3);
			count = 0;
		}
	}
	if (_player->getindex() == 3)
	{
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 0,0);
		_player->setRECT(_rc);
	}
}

void deadstate::enter(player * _player, int character)
{
	count = 0;
	_character = character;
	_present = _player->getpresent();
	if (_character == 0) {
		_player->setimg(IMAGEMANAGER->findImage("ErikDeath"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 87, 90);
		_player->setRECT(_rc);
		if (_player->isRight) {
			_player->getimg()->setFrameX(0);
			_player->getimg()->setFrameY(0);
		}
		else
		{
			_player->getimg()->setFrameX(3);
			_player->getimg()->setFrameY(1);
		}
	}
	if (_character == 1)
	{
		_player->setimg(IMAGEMANAGER->findImage("BaleogDeath"));
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
		_player->setimg(IMAGEMANAGER->findImage("OlafDEAD"));
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
