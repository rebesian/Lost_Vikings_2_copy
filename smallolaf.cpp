#include "stdafx.h"
#include "smallolaf.h"
#include "player.h"
#include "movestate.h"

statepatten * smallolaf::handleInput(player * _player)
{
	if (_present &&_character == 2 && (KEYMANAGER->isStayKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_RIGHT)))
	{
		return new movestate;
	}

	return nullptr;
}

void smallolaf::update(player * _player)
{
	count++;
	if (_present &&_character == 2)
	{
		if (count % 10 == 0 && seen < 6)
		{
			_player->setindex(_player->getindex() + 1);
			if (_player->getindex() == 3 && seen < 3)  _player->setindex(2);
			_player->getimg()->setFrameX(_player->getindex());
			count = 0;
			seen++;
		}
		_rc = RectMakeCenter(_player->getX(), _player->getY()+15, 67, 58);
		_player->setRECT(_rc);
	}
}

void smallolaf::enter(player * _player, int character)
{
	count = seen =0;
	_character = character;
	_present = _player->getpresent();
	_player->isSmall = true;
	if (_character == 2)
	{
		_player->setimg(IMAGEMANAGER->findImage("Olafsmall"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 74, 90);
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
