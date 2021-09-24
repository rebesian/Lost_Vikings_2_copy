#include "stdafx.h"
#include "labberstate.h"
#include "player.h"
#include "idlestate.h"
#include "movestate.h"
statepatten * labberstate::handleInput(player * _player)
{
	if (_present && _player->labber == 255)
	{
		return new idlestate;
	}
	if (_present && (KEYMANAGER->isStayKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_RIGHT)))
	{
		return new movestate;
	}
	return nullptr;
}

void labberstate::update(player * _player)
{
	count++;
	if (_present && KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_player->setY(_player->getY() - 3);
		_player->setindex(_player->getindex() + 1);
		if ((_player->getindex() < 0) || (_player->getindex() > 3))
			_player->setindex(0);

	}
	if (_present&& KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player->setY(_player->getY() + 3);
		_player->setindex(_player->getindex() - 1);
		if ((_player->getindex() < 0) || (_player->getindex() > 3))
			_player->setindex(3);
	}

	if (_character == 0)
	{
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 77, 90);
		_player->setRECT(_rc);
	}
	if (_character == 1) {
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
	}
	if (_character == 2) {
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 80, 90);
		_player->setRECT(_rc);
	}

	if (count % 15 == 0)
	{
		_player->getimg()->setFrameX(_player->getindex());
		_player->getimg()->setFrameY(0);
		count = 0;
	}
}

void labberstate::enter(player * _player, int character)
{
	count = 0;
	_character = character;
	_present = _player->getpresent();
	if (_character == 0) {
		_player->setimg(IMAGEMANAGER->findImage("ErikLadder"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 77, 90);
		_player->setRECT(_rc);
		_player->getimg()->setFrameX(0);
		_player->getimg()->setFrameY(0);
	
	}
	if (_character == 1)
	{
		_player->setimg(IMAGEMANAGER->findImage("BaleogLadder"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
		_player->setRECT(_rc);
		_player->getimg()->setFrameX(0);
		_player->getimg()->setFrameY(0);

	}
	if (_character == 2)
	{
		_player->setimg(IMAGEMANAGER->findImage("Olafladder"));
		_player->getimg()->setCenter(_player->getX(), _player->getY());
		_rc = RectMakeCenter(_player->getX(), _player->getY(), 80, 90);
		_player->setRECT(_rc);
		_player->getimg()->setFrameX(0);
		_player->getimg()->setFrameY(0);
	}
}
