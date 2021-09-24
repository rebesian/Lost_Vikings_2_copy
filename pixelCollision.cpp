#include "stdafx.h"
#include "pixelCollision.h"
#include "player.h"
#include "playerManager.h"

HRESULT pixelCollision::init(int character)
{
	down = 2298;
	up = 0;
	left = 0;
	right = 3158;
	this->character = character;
	return S_OK;
}

void pixelCollision::release()
{

}

void pixelCollision::update()
{
	down = 2298;
	up = 0;
	left = 0;
	right = 3158;
	upprobe = _player->getup();
	downprobe = _player->getdown();
	leftprobe = _player->getleft();
	rightprobe = _player->getright();
	
	for (int i = downprobe - 5; i < downprobe + 5; ++i) {
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("ÇÈ¼¿¹è°æ")->getMemDC(), _player->getX() - 20, i);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		if (r == 255 && g == 254 && b == 0)
		{
			if (down > i)
				down = i;
		}
		color = GetPixel(IMAGEMANAGER->findImage("ÇÈ¼¿¹è°æ")->getMemDC(), _player->getX() + 20, i);
		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);
		if (r == 255 && g == 254 && b == 0)
		{
			if (down > i)
				down = i;
		}
	}
	//À§ÂÊ
	for (int i = upprobe - 5; i <= upprobe + 5; ++i) {
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("ÇÈ¼¿¹è°æ")->getMemDC(), _player->getX() - 20, i);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		if (r == 1 && g == 1 && b == 255)
		{
			if (up < i)
				up = i;
		}
		color = GetPixel(IMAGEMANAGER->findImage("ÇÈ¼¿¹è°æ")->getMemDC(), _player->getX() + 20, i);
		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);
		if (r == 1 && g == 1 && b == 255)
		{
			if (up < i)
				up = i;
		}
	}
	//¿ÞÂÊ
	for (int i = leftprobe + 5; i >= leftprobe - 5; --i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("ÇÈ¼¿¹è°æ")->getMemDC(), i, _player->getY() - 20);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		if (r == 255 && g == 1 && b == 1)
		{
			if (left < i)
				left = i;
		}
		color = GetPixel(IMAGEMANAGER->findImage("ÇÈ¼¿¹è°æ")->getMemDC(), i, _player->getY() + 20);
		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);
		if (r == 255 && g == 1 && b == 1)
		{
			if (left < i)
				left = i;
		}
	}
	//¿À¸¥ÂÊ
	for (int i = rightprobe - 5; i <= rightprobe + 5; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("ÇÈ¼¿¹è°æ")->getMemDC(), i, _player->getY() - 20);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		if (r == 255 && g == 1 && b == 1)
		{
			if (right > i)
				right = i;
		}
		color = GetPixel(IMAGEMANAGER->findImage("ÇÈ¼¿¹è°æ")->getMemDC(), i, _player->getY() + 20);
		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);
		if (r == 255 && g == 1 && b == 1)
		{
			if (right > i)
				right = i;
		}
	}
}

void pixelCollision::render()
{
	
	char _down[128];
	char _downcheck[128];
	char _up[128];
	char _upcheck[128];
	char _left[128];
	char _leftcheck[128];
	char _right[128];
	char _rightcheck[128];
	
	sprintf_s(_down, "¹¹°¡¸ÕÀúµÊdown?: %f", down);
	TextOut(getMemDC(), _player->getX() - 100, _player->getY() - 200, _down, strlen(_down));
	sprintf_s(_up, "¹¹°¡¸ÕÀúµÊup?: %f", up);
	TextOut(getMemDC(), _player->getX() - 100, _player->getY() - 140, _up, strlen(_up));
	sprintf_s(_left, "¹¹°¡¸ÕÀúµÊleft?: %f", left);
	TextOut(getMemDC(), _player->getX() - 100, _player->getY() - 100, _left, strlen(_left));
	sprintf_s(_right, "¹¹°¡¸ÕÀúµÊright?: %f", right);
	TextOut(getMemDC(), _player->getX() - 100, _player->getY() - 60, _right, strlen(_right));
	sprintf_s(_downcheck, "¹Ù´ÚY : %f", downprobe);
	TextOut(getMemDC(), _player->getX() - 100, _player->getY() - 160, _downcheck, strlen(_downcheck));
	sprintf_s(_upcheck, "¸Ó¸®Y : %f", upprobe);
	TextOut(getMemDC(), _player->getX() - 100, _player->getY() - 120, _upcheck, strlen(_upcheck));
	sprintf_s(_leftcheck, "¿ÞÂÊX : %f", leftprobe);
	TextOut(getMemDC(), _player->getX() - 100, _player->getY() - 80, _leftcheck, strlen(_leftcheck));
	sprintf_s(_rightcheck, "¿À¸¥ÂÊX : %f", rightprobe);
	TextOut(getMemDC(), _player->getX() - 100, _player->getY() - 40, _rightcheck, strlen(_rightcheck));
	
}

float pixelCollision::leftcollision()
{
	float x;
	if (left >= leftprobe)
	{
		x =  left + (_player->getRECT().right - _player->getRECT().left) / 2;
		return x;
	}
	return _player->getX();
}

float pixelCollision::rightcollision()
{
	float x;
	if (right <= rightprobe)
	{
		 x = right - (_player->getRECT().right - _player->getRECT().left) / 2;
		 return x;
	}
	return _player->getX();
}

float pixelCollision::downcollision()
{
	float y;
	if ( down<= downprobe ) { 
		 y = down - (_player->getRECT().bottom - _player->getRECT().top)/2;
		return y;
	}
	return _player->getY();
}

bool pixelCollision::headcheck()
{
	
	if (!(up == 0) && up >= upprobe) {
		return true;
	}
	return false;
}

bool pixelCollision::leftcheck()
{
	if (left <= leftprobe)
	{
		return true;
	}
	return false;
}

bool pixelCollision::rightcheck()
{
	if (right <= rightprobe)
	{
		return true;
	}
	return false;
}

bool pixelCollision::groundcheck()
{
	if (down > downprobe)
	{
		return true;
	}
	return false;
}
