#include "stdafx.h"
#include "object.h"
//문
HRESULT door::init(float x, float y)
{
	img1=IMAGEMANAGER->addImage("objectDoorRtoL", "LostVikingsimage/Object/objectDoorRtoL.bmp", 48, 144, true, RGB(255, 0, 255));
	img2=IMAGEMANAGER->addImage("objectDoorOpen", "LostVikingsimage/Object/objectDoorOpen.bmp", 89, 144, true, RGB(255, 0, 255));
	_door.img = IMAGEMANAGER->findImage("objectDoorRtoL");
	_door.img->setCenter(x,y);
	this->x = x;
	this->y = y;
	_door._rc = RectMakeCenter(x, y, 48, 144);
	return S_OK;
}

void door::update()
{
	_door._rc = RectMakeCenter(0, 0, 0, 0);
	_door.img = img2;
	_door.img->setCenter(x, y);
}

void door::release()
{

}

void door::render()
{
	_door.img->render(getMemDC());
}

//사다리
HRESULT labber::init(float x, float y , int width, int height, int number)
{

	_labber._rc = RectMakeCenter(x, y, width, height);
	return S_OK;
}

void labber::update()
{

}

void labber::release()
{

}

void labber::render()
{
	Rectangle(getMemDC(), _labber._rc);
}


//로프
HRESULT rope::init(float x, float y ,int width, int height, int number)
{
	
	_rope._rc = RectMakeCenter(x, y, width, height);
	return S_OK;
}

void rope::update()
{
}

void rope::release()
{
}

void rope::render()
{
	Rectangle(getMemDC(), _rope._rc);
}

//키꽂는데
HRESULT keyhome::init(float x, float y)
{

	_keyhome._rc = RectMakeCenter(x, y, 45,48);
	return S_OK;
}

void keyhome::update()
{

}

void keyhome::release()
{

}

void keyhome::render()
{
	Rectangle(getMemDC(), _keyhome._rc);
}


//엘리베이터
HRESULT elevator::init(float x, float y,int i)
{
	char name[12];
	sprintf_s(name, "엘리베이터%d", i);
	IMAGEMANAGER->addImage(name, "LostVikingsimage/Object/objectPulley.bmp", 96, 48, true, RGB(255, 0, 255));
	_elevator.img = IMAGEMANAGER->findImage(name);
	_elevator.img->setCenter(x, y);
	_elevator._rc = RectMakeCenter(x, y, 96, 48);
	_elevator.x = x;
	_elevator.y = y;

	number = i;
	return S_OK;
}

void elevator::update()
{
	_elevator._rc = RectMakeCenter(_elevator.x , _elevator.y , 96, 48);
	_elevator.img->setCenter(_elevator.x, _elevator.y);
}

void elevator::release()
{

}

void elevator::render()
{
	//Rectangle(getMemDC(), _elevator._rc);
	_elevator.img->render(getMemDC());
}

//가시
HRESULT thorn::init(float x, float y, int number)
{
	_thorn._rc = RectMakeCenter(x, y, 44, 90);
	this->number = number;
	return S_OK;
}

void thorn::update()
{

}

void thorn::release()
{
}

void thorn::render()
{
	Rectangle(getMemDC(), _thorn._rc);
}

HRESULT pushbotten::init(float x, float y , int i)
{
	char name[12];
	sprintf_s(name, "버튼%d", i);
	IMAGEMANAGER->addImage(name, "LostVikingsimage/Object/pushbotten.bmp", 42, 42, true, RGB(255, 0, 255));
	_pushbotten.img = IMAGEMANAGER->findImage(name);
	_pushbotten.img->setCenter(x, y);
	_pushbotten._rc = RectMakeCenter(x, y, 42, 42);
	number = i;
	return S_OK;
}

void pushbotten::update()
{
}

void pushbotten::release()
{
}

void pushbotten::render()
{
	Rectangle(getMemDC(), _pushbotten._rc);
	_pushbotten.img->render(getMemDC());
}

HRESULT bottenground::init(float x, float y)
{
	IMAGEMANAGER->addImage("꺼진바닥", "LostVikingsimage/Object/swtichground.bmp", 96, 45, true, RGB(255, 0, 255));
	_bottenground.img = IMAGEMANAGER->findImage("꺼진바닥");
	_bottenground.img->setCenter(x, y);
	_bottenground._rc = RectMakeCenter(x, y, 96, 45);
	return S_OK;
}

void bottenground::update()
{
	_bottenground._rc = RectMakeCenter(0, 0, 0, 0);
	_bottenground.img->setCenter(0, 0);
}

void bottenground::release()
{
	
}

void bottenground::render()
{
	
	_bottenground.img->render(getMemDC());
}

HRESULT wall::init(float x, float y)
{
	IMAGEMANAGER->addImage("미는벽", "LostVikingsimage/Object/objectMovingStone.bmp", 96, 96, true, RGB(255, 0, 255));
	_wall.img = IMAGEMANAGER->findImage("미는벽");
	_wall.img->setCenter(x, y);
	_wall._rc = RectMakeCenter(x, y, 96, 96);
	_wall.x = x;
	_wall.y = y;
	gravity = 5;
	return S_OK;
}

void wall::update()
{
	_wall._rc = RectMakeCenter(_wall.x , _wall.y , 96, 96);
	_wall.img->setCenter(_wall.x, _wall.y);
}

void wall::release()
{

}

void wall::render()
{
	// 1291,1151
	Rectangle(getMemDC(), _wall._rc);
	_wall.img->render(getMemDC());
}

void wall::wallgroudcheck(bottenground bottenground , ground ground1 , ground ground2)
{
	RECT temp;

	if (IntersectRect(&temp, &_wall._rc, &bottenground.getRect()))
	{
		_wall.y = bottenground.getRect().top - (_wall._rc.bottom - _wall._rc.top) / 2;
		wallleft = bottenground.getRect().left;
		wallright = bottenground.getRect().right;
	}
	else if (IntersectRect(&temp, &_wall._rc, &ground1.getRect()))
	{
		_wall.y = ground1.getRect().top - (_wall._rc.bottom - _wall._rc.top) / 2;
		wallleft = ground1.getRect().left;
		wallright = ground1.getRect().right;
	}
	else if (IntersectRect(&temp, &_wall._rc, &ground2.getRect()))
	{
		_wall.y = ground2.getRect().top - (_wall._rc.bottom - _wall._rc.top) / 2;
		wallleft = ground2.getRect().left;
		wallright = ground2.getRect().right;
	}

	if(_wall._rc.left>=wallright || _wall._rc.right<=wallleft)
	{
		_wall.y += gravity;
	}
}


HRESULT bottenbox::init(float x, float y)
{
	IMAGEMANAGER->addImage("버튼벽", "LostVikingsimage/Object/objectBOX2x3.bmp", 96, 144, true, RGB(255, 0, 255));
	_bottenbox.img = IMAGEMANAGER->findImage("버튼벽");
	_bottenbox.img->setCenter(x, y);
	_bottenbox._rc = RectMakeCenter(x, y, 96, 144);
	return S_OK;
}

void bottenbox::update()
{
	_bottenbox._rc = RectMakeCenter(0, 0, 0, 0);
	_bottenbox.img->setCenter(0, 0);
}

void bottenbox::release()
{

}

void bottenbox::render()
{
	// 2591 ,1987 
	Rectangle(getMemDC(), _bottenbox._rc);
	_bottenbox.img->render(getMemDC());
}

HRESULT bealogaction::init(float x, float y, int number)
{
	//1751, 1361.5f
	_bealogaction._rc = RectMakeCenter(x, y, 48, 48);
	this->number = number;
	return S_OK;
}

void bealogaction::update()
{
}

void bealogaction::release()
{
}

void bealogaction::render()
{
	Rectangle(getMemDC(), _bealogaction._rc);
}

HRESULT water::init(float x, float y)
{
	_water._rc = RectMakeCenter(x, y , 585, 326);
	return S_OK;
}

void water::update()
{
}

void water::release()
{
}

void water::render()
{
	Rectangle(getMemDC(), _water._rc);
}

HRESULT ground::init(float x, float y)
{
	_ground._rc = RectMakeCenter(x, y, 122, 18);
	return S_OK;
}

void ground::update()
{

}

void ground::release()
{

}

void ground::render()
{
	Rectangle(getMemDC(), _ground._rc);

}

HRESULT fire::init(float x, float y ,int i)
{

	char name[12];
	sprintf_s(name, "불%d", i);
	IMAGEMANAGER->addFrameImage(name, "LostVikingsimage/Object/objectFire3Frame.bmp", 870, 69, 6,1, true, RGB(255, 0, 255));
	_fire.img = IMAGEMANAGER->findImage(name);
	_fire.img->setCenter(x, y);
	this->x = x;
	this->y = y;
	_fire._rc = RectMakeCenter(x, y, 145, 68);
	index = 0;
	_fire.img->setFrameY(0);
	_fire.img->setFrameX(0);
	count = 0;
	return S_OK;
}

void fire::update()
{
	count++;
	if (count % 10 == 0)
	{
		_fire.img->setFrameX(index);
		index++;
		if (index > 5) index = 0;
	}
}

void fire::release()
{

}

void fire::render()
{
	_fire.img->frameRender(getMemDC(), _fire._rc.left, _fire._rc.top);

}

HRESULT npc::init()
{
	_npc._rc = RectMakeCenter(2232, 1536 ,90, 90);
	_npc.img = IMAGEMANAGER->addFrameImage("npc", "LostVikingsimage/NPC_item/witchDefault.bmp", 270, 90, 3, 1, true, RGB(255, 0, 255));
	_npc.img->setCenter(2232, 1536);
	index = 0;
	_npc.img->setFrameY(0);
	_npc.img->setFrameX(0);
	count = 0;
	return S_OK;
}

void npc::update()
{
	count++;
	if (count % 10 == 0)
	{
		_npc.img->setFrameX(index);
		index++;
		if (index > 3) index = 0;
	}
}

void npc::release()
{

}

void npc::render()
{
	_npc.img->frameRender(getMemDC(), 2232-45, 1536-45);
}
