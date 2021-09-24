#pragma once
#include "gameNode.h"
class player;

class cannonbullet :public gameNode
{
private:
	image* img;
	RECT bullet;
	float cannon_x, cannon_y , bullet_x;
	int count;
public:
	RECT range_rc;
	bool isfire ,isdamage;

	HRESULT init(float x, float y, float width, float height ,float bulletx, float bullety, int i);
	void update();
	void release();
	void render();
	void rangeplayer(player* player);
	bool bulletdamage(player* player);
};

