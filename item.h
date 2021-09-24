#pragma once
#include "gameNode.h"
class player;

struct item
{
	image* _img;
	RECT _rc;
};
class key : public gameNode
{
private:
	item _key;
public:
	HRESULT init();
	void update();
	void release();
	void render();
	bool keycheck(player* player);
};

class heal :public gameNode
{
public:
	HRESULT init(float x, float y);
	void update();
	void release();
	void render();
};

class bomb : public gameNode
{
public:
	HRESULT init(float x, float y);
	void update();
	void release();
	void render();
};

class clearobject1 :public gameNode
{
private:
	item _clear;
	float x, y;
public:
	HRESULT init(float x, float y ,int i);
	void update();
	void release();
	void render();
	bool clearcheck1(player* player);
};
class clearobject2 :public gameNode
{
private:
	item _clear;
	float x, y;
public:
	HRESULT init(float x, float y, int i);
	void update();
	void release();
	void render();
	bool clearcheck2(player* player);
};