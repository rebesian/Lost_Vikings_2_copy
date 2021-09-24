#pragma once
#include "singletonBase.h"
#include "image.h"

class cameraManager : public singletonBase<cameraManager>
{
private:
	//ī�޶� ���ߴ� ȭ�� ũ��(WINSIZEX, WINSIZEY)�� ��ǥ(left, right, top, bottom)
	RECT _screen, _zoom;
	int _backWidth, _backHeight;	//backDC ũ��
	int _frontWidth, _frontHeight;	//frontDC ũ��
	float _count ,_x, _y;

public:
	cameraManager();
	~cameraManager();

	HRESULT init(int width, int height);
	void release();

	//ī�޶� ��ġ ����
	void updateScreen(float standardX, float standardY,
		float ratioX = 0.5f, float ratioY = 0.5f, float zoom = 1.0f);
	//ī�޶� ����
	void vibrateScreen(float standardX, float standardY,
		float magnitude = 5.0f, float interval = 0);
	//ī�޶� ���
	void render(HDC frontDC, int destX, int destY, HDC backDC,
		float zoom = 1.0f);

	void setBackScreenSize(float width, float height) { _backWidth = width, _backHeight = height; }
	//void setFrontScreenSize(float width, float height) { _frontWidth = width, _frontHeight = height; }
	float getBackScreenWidth() { return _backWidth; }
	float getBackScreenHeight() { return _backHeight; }
	RECT getScreen() { return _screen; }
	
	float getX() { return _x; }
	float getY() { return _y; }
};

