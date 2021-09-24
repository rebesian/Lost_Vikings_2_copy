#include "stdafx.h"
#include "bealogatteck.h"
#include "player.h"
#include "idlestate.h"
#include "damagestate.h"
statepatten * bealogatteck::handleInput(player * _player)
{
	if (_player->getindex() == 6)
	{
		_player->attack = RectMakeCenter(0, 0, 0, 0);
		return new idlestate;
	}
	if (_player->damage)
	{
		return new damagestate;
	}
	return nullptr;
}

void bealogatteck::update(player * _player)
{
	count++;
	if (count % 5 == 0)
	{
		if (_player->isRight) {
			_player->getimg()->setFrameX(_player->getindex());
			_player->getimg()->setFrameY(0);
			if (_player->getindex() == 2 || _player->getindex() == 3)
			{
				_player->attack = RectMakeCenter(_player->getX() + 40, _player->getY(), 40, 30);
			}
		}
		else
		{
			_player->getimg()->setFrameX(_player->getindex());
			_player->getimg()->setFrameY(1);
			if (_player->getindex() == 2 || _player->getindex() == 3)
			{
				_player->attack = RectMakeCenter(_player->getX() - 40, _player->getY(), 40, 30);
			}
		}
		_player->setindex(_player->getindex() + 1);
		count = 0;
	}
}

void bealogatteck::enter(player * _player, int character)
{
	count = 0;
	_character = character;
	_present = _player->getpresent();
	if (_character == 1)
	{
		_player->setimg(IMAGEMANAGER->findImage("BaleogAttackSword"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_player->setindex(0);
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
