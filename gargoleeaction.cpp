#include "stdafx.h"
#include "gargoleeaction.h"
#include "player.h"
#include "fallingstate.h"
statepatten * gargoleeaction::handleInput(player * _player)
{
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_player->_gargolee = false;
		_player->bealogrc = RectMakeCenter(0, 0, 0, 0);
		_player->gargoleebody1rc = RectMakeCenter(0, 0, 0, 0);
		_player->gargoleebody2rc = RectMakeCenter(0, 0, 0, 0);
		_player->gargoleebody3rc = RectMakeCenter(0, 0, 0, 0);
		return new fallingstate;
	}
	return nullptr;
}

void gargoleeaction::update(player * _player)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (angle > 1.57 && 3.07 >angle)
			angle += 0.01f;
		
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if(angle <1.57 && 0.2<angle)
		angle -= 0.01f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		distance -= 1;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		distance += 1;
	}

	_player->bealogrc = RectMakeCenter(((_player->bealogactionrc.right + _player->bealogactionrc.left) / 2),
									((_player->bealogactionrc.bottom + _player->bealogactionrc.top) / 2), 38, 38);
	_player->gargoleebody1rc = RectMakeCenter(((_player->bealogrc.right + _player->bealogrc.left) / 2) + cosf(angle)*distance, 
											((_player->bealogrc.bottom + _player->bealogrc.top) / 2) + sinf(angle)*distance, 32, 32);
	_player->gargoleebody2rc = RectMakeCenter(((_player->gargoleebody1rc.right + _player->gargoleebody1rc.left) / 2) + cosf(angle)*distance, ((_player->gargoleebody1rc.bottom + _player->gargoleebody1rc.top) / 2) + sinf(angle)*distance, 32, 32);
	_player->gargoleebody3rc = RectMakeCenter(((_player->gargoleebody2rc.right + _player->gargoleebody2rc.left) / 2) + cosf(angle)*distance, ((_player->gargoleebody2rc.bottom + _player->gargoleebody2rc.top) / 2) + sinf(angle)*distance, 32, 32);
	_player->setX(((_player->gargoleebody3rc.right + _player->gargoleebody3rc.left) / 2) + cosf(angle)*distance);
	_player->setY(((_player->gargoleebody3rc.bottom + _player->gargoleebody3rc.top) / 2) + sinf(angle)*distance);
	_rc = RectMakeCenter(_player->getX(), _player->getY(), 90, 90);
	_player->setRECT(_rc);
	Accelearation = (gravity / distance)*cosf(angle);
	speed += Accelearation;
	speed *= 0.995f;
	angle += speed;	
	if (_player->isRight) {
		if (2.8 < angle)
			_player->getimg()->setFrameX(0);
		if (2.00 < angle && angle < 2.4)
			_player->getimg()->setFrameX(1);
		if (1.57 < angle && angle < 2.00)
			_player->getimg()->setFrameX(2);
		if (1.00 < angle && angle < 1.57)
			_player->getimg()->setFrameX(3);
		if ( 0.4 < angle && angle < 1.00)
			_player->getimg()->setFrameX(4);
		if (0.2 < angle && angle < 0.4)
			_player->getimg()->setFrameX(5);
	}
	else
	{
		if (2.8 < angle)
			_player->getimg()->setFrameX(5);
		if (2.00 < angle && angle < 2.4)
			_player->getimg()->setFrameX(4);
		if (1.57 < angle && angle < 2.00)
			_player->getimg()->setFrameX(3);
		if (1.00 < angle && angle < 1.57)
			_player->getimg()->setFrameX(2);
		if (0.4 < angle && angle < 1.00)
			_player->getimg()->setFrameX(1);
		if (0.2 < angle && angle < 0.4)
			_player->getimg()->setFrameX(0);
	}

}

void gargoleeaction::enter(player * _player, int character)
{

	count =0;
	_character = character;
	gravity = 0.08f;
	_present = _player->getpresent();

	angle =(_player->getX()-((_player->bealogactionrc.right+_player->bealogactionrc.left)/2)) / 
			(_player->getY() -((_player->bealogactionrc.right + _player->bealogactionrc.left) / 2));

	distance = getDistance(((_player->bealogrc.right + _player->bealogrc.left) / 2), 
			((_player->bealogrc.bottom + _player->bealogrc.top) / 2), 
			((_player->bealogactionrc.right + _player->bealogactionrc.left) / 2), 
			((_player->bealogactionrc.bottom + _player->bealogactionrc.top) / 2));

	Accelearation = 0 ;
	speed = 0;
	_player->_gargolee = true;
	if (_character == 1) {
	
		_player->setimg(IMAGEMANAGER->findImage("BaleogSwing"));
		if (_player->isRight) {
			angle += 1.57;
			_player->setindex(1);
			_player->getimg()->setFrameX(1);
			_player->getimg()->setFrameY(0);
		}
		else{
			angle += 0.75;
			_player->setindex(3);
			_player->getimg()->setFrameX(3);
			_player->getimg()->setFrameY(1);
		}
	}
}
