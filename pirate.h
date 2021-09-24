#pragma once
#include "gameNode.h"
class player;
enum STATE
{
	MOVE,
	ATTACK,
	DAMAGE
};
class pirate : public gameNode
{
private:
	image* img;
	RECT _rc , attack_rc;
	STATE state;
	float x, y;
	int move;
	bool isdamage, isattack, isright , isdead;
	int index, count;

public:
	pirate() {};
	~pirate() {};
	RECT rangerc;
	HRESULT init();
	void update();
	void release();
	void render();
	bool playerdamage(player* player);
	void attackdamage(player* player);
	void rangeplayer(player* player);
};

