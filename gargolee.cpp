#include "stdafx.h"
#include "gargolee.h"
#include "player.h"
#include "idlestate.h"
#include "gargoleeaction.h"

statepatten * gargolee::handleInput(player * _player)
{
	if (end)
	{
		_player->_gargolee = false;
		_player->bealogrc = RectMakeCenter(0, 0, 0, 0);
		_player->gargoleebody1rc = RectMakeCenter(0, 0, 0, 0);
		_player->gargoleebody2rc = RectMakeCenter(0, 0, 0, 0);
		_player->gargoleebody3rc = RectMakeCenter(0, 0, 0, 0);
		return new idlestate;
	}
	if (_player->bealogaction !=255)
	{
		return new gargoleeaction;
	}
	return nullptr;
}

void gargolee::update(player * _player)
{
	count++;
	//앞으로 갈고리
	if (_player->getimg() == IMAGEMANAGER->findImage("BaleogPunch")) {
		if (count % 10 == 0) {
			if (_player->isRight) {
				_player->setindex(_player->getindex() + 1);
				if (_player->getindex() > 3) _player->setindex(3);
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(0);
				count = 0;
			}
			else
			{
				_player->setindex(_player->getindex() + 1);
				if (_player->getindex() > 3) _player->setindex(3);
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(1);
				count = 0;
			}
		}
		if (_player->isRight) {
			if (_player->getindex() > 2) x -= 2;
			else x += 2;
			_player->gargoleebody3rc = RectMakeCenter(_player->getX() + x, _player->getY(), 32, 32);
			_player->gargoleebody2rc = RectMakeCenter(((_player->gargoleebody3rc.right + _player->gargoleebody3rc.left) / 2) + x, _player->getY(), 32, 32);
			_player->gargoleebody1rc = RectMakeCenter(((_player->gargoleebody2rc.right + _player->gargoleebody2rc.left) / 2) + x, _player->getY(), 32, 32);
			_player->bealogrc = RectMakeCenter(((_player->gargoleebody1rc.right + _player->gargoleebody1rc.left) / 2) + x, _player->getY(), 38, 38);
			if (x < 0) end=true;
		}
		else {
			if (_player->getindex() > 2) x += 2;
			else x -= 2;
			_player->gargoleebody3rc = RectMakeCenter(_player->getX() + x, _player->getY(), 32, 32);
			_player->gargoleebody2rc = RectMakeCenter(((_player->gargoleebody3rc.right + _player->gargoleebody3rc.left) / 2) + x, _player->getY(), 32, 32);
			_player->gargoleebody1rc = RectMakeCenter(((_player->gargoleebody2rc.right + _player->gargoleebody2rc.left) / 2) + x, _player->getY(), 32, 32);
			_player->bealogrc = RectMakeCenter(((_player->gargoleebody1rc.right + _player->gargoleebody1rc.left) / 2) + x, _player->getY(), 38, 38);
			if (x > 0) end = true;
		}
	}

	//위로갈고리
	if (_player->getimg() == IMAGEMANAGER->findImage("BaleogPunchTop")) {
		if (count % 10 == 0) {
			if (_player->isRight) {
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(0);
				_player->setindex(_player->getindex() + 1);
				if (_player->getindex() > 2) _player->setindex(1);
			}
			else
			{
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(1);
				_player->setindex(_player->getindex() + 1);
				if (_player->getindex() > 2) _player->setindex(1);
			}
		}

		if (count < 30) y -= 2;
		else y += 2;
		_player->gargoleebody3rc = RectMakeCenter(_player->getX(), _player->getY() + y, 32, 32);
		_player->gargoleebody2rc = RectMakeCenter(_player->getX(), ((_player->gargoleebody3rc.bottom + _player->gargoleebody3rc.top) / 2) + y, 32, 32);
		_player->gargoleebody1rc = RectMakeCenter(_player->getX(), ((_player->gargoleebody2rc.bottom + _player->gargoleebody2rc.top) / 2) + y, 32, 32);
		_player->bealogrc = RectMakeCenter(_player->getX(), ((_player->gargoleebody1rc.bottom + _player->gargoleebody1rc.top) / 2)+y, 38, 38);

		if (y > 0) end = true;
	}


	//대각선갈고리
	if (_player->getimg() == IMAGEMANAGER->findImage("BaleogPunchDiagonal")) {
		if (count % 10 == 0) {
			if (_player->isRight) {
				_player->setindex(_player->getindex() + 1);
				if (_player->getindex() > 3) _player->setindex(3);
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(0);
				count = 0;
			}
			else
			{
				_player->setindex(_player->getindex() + 1);
				if (_player->getindex() > 3) _player->setindex(3);
				_player->getimg()->setFrameX(_player->getindex());
				_player->getimg()->setFrameY(1);
				count = 0;
			}
		}
		if (_player->isRight) {
			if (_player->getindex() > 2) { x -= 1.5f; y += 1.5f; }
			else { x += 1.5f; y -= 1.5f; }
			_player->gargoleebody3rc = RectMakeCenter(_player->getX() + x, _player->getY() + y, 32, 32);
			_player->gargoleebody2rc = RectMakeCenter(((_player->gargoleebody3rc.right + _player->gargoleebody3rc.left) / 2) + x, ((_player->gargoleebody3rc.bottom + _player->gargoleebody3rc.top) / 2) + y, 32, 32);
			_player->gargoleebody1rc = RectMakeCenter(((_player->gargoleebody2rc.right + _player->gargoleebody2rc.left) / 2) + x, ((_player->gargoleebody2rc.bottom + _player->gargoleebody2rc.top) / 2) + y, 32, 32);
			_player->bealogrc = RectMakeCenter(((_player->gargoleebody1rc.right + _player->gargoleebody1rc.left) / 2) + x, ((_player->gargoleebody1rc.bottom + _player->gargoleebody1rc.top) / 2) +y, 38, 38);

			if (x < 0) end = true;
		}
		else {
			if (_player->getindex() > 2) { x += 1.5f; y += 1.5f; }
			else { x -= 1.5f; y -= 1.5f; }
			_player->gargoleebody3rc = RectMakeCenter(_player->getX() + x, _player->getY() + y, 32, 32);
			_player->gargoleebody2rc = RectMakeCenter(((_player->gargoleebody3rc.right + _player->gargoleebody3rc.left) / 2) + x, ((_player->gargoleebody3rc.bottom + _player->gargoleebody3rc.top) / 2) + y, 32, 32);
			_player->gargoleebody1rc = RectMakeCenter(((_player->gargoleebody2rc.right + _player->gargoleebody2rc.left) / 2) + x, ((_player->gargoleebody2rc.bottom + _player->gargoleebody2rc.top) / 2) + y, 32, 32);
			_player->bealogrc = RectMakeCenter(((_player->gargoleebody1rc.right + _player->gargoleebody1rc.left) / 2) + x, ((_player->gargoleebody1rc.bottom + _player->gargoleebody1rc.top) / 2) + y, 38, 38);
			if (x > 0) end = true;
		}
	}
}

void gargolee::enter(player * _player, int character)
{
	count = 0;
	x = y = 1;
	_character = character;
	_present = _player->getpresent();
	_player->_gargolee = true;
	end = false;
	if (_character == 1) {
		if (KEYMANAGER->isStayKeyDown(VK_LEFT) || (KEYMANAGER->isStayKeyDown(VK_RIGHT)))
		{
			_player->setimg(IMAGEMANAGER->findImage("BaleogPunch"));
			_player->setindex(0);
			if (_player->isRight) {
				_player->gargolee = IMAGEMANAGER->findImage("gargolee2");
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(0);
			}
			else
			{
				_player->gargolee = IMAGEMANAGER->findImage("gargolee3");
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(1);
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_player->setimg(IMAGEMANAGER->findImage("BaleogPunchTop"));
			_player->gargolee = IMAGEMANAGER->findImage("gargolee1");
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
		if (KEYMANAGER->isStayKeyDown(VK_UP)&& (KEYMANAGER->isStayKeyDown(VK_LEFT) || (KEYMANAGER->isStayKeyDown(VK_RIGHT))))
		{
			_player->setimg(IMAGEMANAGER->findImage("BaleogPunchDiagonal"));
			_player->getimg()->setCenter(_player->getX(), _player->getY());
			_player->setindex(0);
			if (_player->isRight) {
				_player->gargolee = IMAGEMANAGER->findImage("gargolee4");
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(0);
			}
			else
			{
				_player->gargolee = IMAGEMANAGER->findImage("gargolee5");
				_player->getimg()->setFrameX(0);
				_player->getimg()->setFrameY(1);
			}
		}
	}
}
