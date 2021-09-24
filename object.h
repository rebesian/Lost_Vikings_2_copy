#pragma once
#include "gameNode.h"
struct object
{
	image* img;
	RECT _rc;
	float x, y;
};

//문
class door :public gameNode
{
private:
	object _door;
	image* img1;
	image* img2;
	float x, y;
	bool open;
public:
	door() {};
	~door() {};
	HRESULT init(float x, float y);
	void update();
	void release();
	void render();

	RECT getRect() { return _door._rc; }
};

//사다리
class labber : public gameNode
{
private:
	object _labber;
	int number;
public:
	labber() {};
	~labber() {};
	HRESULT init(float x, float y, int width, int height ,int number);
	void update();
	void release();
	void render(); 

	int getnumber() { return number; }
	RECT getRect() { return _labber._rc; }
};

//줄
class rope :public gameNode
{
private:
	object _rope;
	int number;
public:
	rope() {};
	~rope() {};
	HRESULT init(float x, float y, int width, int height, int number);
	void update();
	void release();
	void render();

	int getnumber() { return number; }
	RECT getRect() { return _rope._rc; }
};

//키홈
class keyhome : public gameNode
{
private:
	object _keyhome;
public:
	keyhome() {};
	~keyhome() {};
	HRESULT init(float x, float y);
	void update();
	void release();
	void render();
	RECT getRect() { return _keyhome._rc; }
};

//엘리베이터
class elevator :public gameNode
{
private:
	object _elevator;
	int number;
public:
	elevator() {};
	~elevator() {};
	HRESULT init(float x, float y ,int i);
	void update();
	void release();
	void render();
	
	float getY() { return _elevator.y; }
	int getnumber() { return number; }
	RECT getRect() { return _elevator._rc; }

	void setY(float y) { _elevator.y = y;}
};

//가시
class thorn : public gameNode
{
private:
	object _thorn;
	int number;
public:
	thorn() {};
	~thorn() {};
	HRESULT init(float x, float y, int number);
	void update();
	void release();
	void render();
	int getnumber() { return number; }
	RECT getRect() { return _thorn._rc; }
};

//푸쉬버튼
class pushbotten : public gameNode
{
private:
	object _pushbotten;
	int number;
public:
	pushbotten() {};
	~pushbotten() {};
	HRESULT init(float x, float y , int i);
	void update();
	void release();
	void render();
	int getnumber() { return number; }
	RECT getRect() { return _pushbotten._rc; }
};

//스위치누르면꺼지는바닥
class bottenground : public gameNode
{
private:
	object _bottenground;
public:
	bottenground() {};
	~bottenground() {};
	HRESULT init(float x, float y);
	void update();
	void release();
	void render();
	RECT getRect() { return _bottenground._rc; }
	
};



class ground :public gameNode
{
private:
	object _ground;

public:
	ground() {};
	~ground() {};
	HRESULT init(float x, float y);
	void update();
	void release();
	void render();
	RECT getRect() { return _ground._rc; }
};




//미는벽
class wall :public gameNode
{
private:
	object _wall;
	int number;
	float gravity;
public:
	wall() {};
	~wall() {};
	float wallleft, wallright;
	HRESULT init(float x, float y);
	void update();
	void release();
	void render();
	void wallgroudcheck(bottenground _bottenground, ground rc1 ,ground rc2);
	
	float getX() { return _wall.x; }
	float getY() { return _wall.y; }

	void setX(float x) { _wall.x = x; }
	void setY(float y) { _wall.y = y; }

	RECT getRect() { return _wall._rc; }
};

//버튼누르면 사라지는박스
class bottenbox:public gameNode
{
private:
	object _bottenbox;
public:
	bottenbox() {};
	~bottenbox() {};
	HRESULT init(float x, float y);
	void update();
	void release();
	void render();

	RECT getRect() { return _bottenbox._rc; }
};

//bealog전용 갈고리액션상자
class bealogaction : public gameNode
{
private:
	object _bealogaction;

	int number;
public:
	bealogaction() {};
	~bealogaction() {};
	HRESULT init(float x, float y , int i);
	void update();
	void release();
	void render();

	int getnumber() { return number; }
	RECT getRect() { return _bealogaction._rc; }
};

//물
class water : public gameNode
{
private:
	object _water;
public:
	water() {};
	~water() {};
	HRESULT init(float x, float y);
	void update();
	void release();
	void render();
	RECT getRect() { return _water._rc; }
};

//불
class fire : public gameNode
{
private:
	object _fire;
	float x, y;
	int index ,count;
public:
	fire() {};
	~fire() {};
	HRESULT init(float x, float y, int i);
	void update();
	void release();
	void render();
	RECT getRect() { return _fire._rc; }
};

class npc : public gameNode
{
private:
	object _npc;
	float x, y;
	int index, count;
public:
	npc() {};
	~npc() {};
	HRESULT init();
	void update();
	void release();
	void render();
	RECT getRect() { return _npc._rc; }
};