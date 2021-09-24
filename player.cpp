#include "stdafx.h"
#include "player.h"
#include "idlestate.h"
#include "pixelCollision.h"
#include "objectManager.h"

HRESULT player::init(int character ,float x, float y)
{

	index = 0;

	gargoleebody1 = IMAGEMANAGER->findImage("gargoleebody");
	gargoleebody2 = IMAGEMANAGER->findImage("gargoleebody1");
	gargoleebody3 = IMAGEMANAGER->findImage("gargoleebody2");
	present = isTop= key = clear1= clear2=false;

	_character = character;
	_state = new idlestate;
	_state->enter(this , _character);
	isRight = true;
	hp = 3;

	up = y - (rc.bottom - rc.top) / 2;
	down = y + (rc.bottom - rc.top) / 2;
	left = x - (rc.right - rc.left) / 2;
	right = x + (rc.right - rc.left) / 2;

	this->x = x;
	this->y = y;

	return S_OK;
}

void player::update()
{
	handleInput();
	_state->update(this);
	up = y - (rc.bottom - rc.top) / 2;
	down = y + (rc.bottom - rc.top) / 2;
	left = x - (rc.right - rc.left) / 2;
	right = x + (rc.right - rc.left) / 2;

}

void player::release()
{
}

void player::render(bool hudMode)
{
	if (!hudMode) {
		//Rectangle(getMemDC(), rc);
		if(!isSmall || (present&&(KEYMANAGER->isStayKeyDown(VK_LEFT))|| (present && KEYMANAGER->isStayKeyDown(VK_RIGHT)))) img->frameRender(getMemDC(), rc.left, rc.top);
		else img->frameRender(getMemDC(), rc.left - 6, rc.top - 32);
		if (_gargolee)
		{
			//Rectangle(getMemDC(), bealogrc);
			gargolee->render(getMemDC(), bealogrc.left, bealogrc.top);
			gargoleebody1->render(getMemDC(),  gargoleebody1rc.left, gargoleebody1rc.top);
			gargoleebody2->render(getMemDC(), gargoleebody2rc.left, gargoleebody2rc.top);
			gargoleebody3->render(getMemDC(), gargoleebody3rc.left, gargoleebody3rc.top);;
		}

	}
	else
	{
		Rectangle(getMemDC(), rc);
		img->frameAlphaRender(getMemDC(), x-(rc.right-rc.left)/2, y-(rc.bottom-rc.top)/2, 200);
	}
}

void player::handleInput()
{
	statepatten* state = _state->handleInput(this);
	if (state != nullptr)
	{
		SAFE_DELETE(_state);
		_state = state;
		_state->enter(this , _character);
	}
}




