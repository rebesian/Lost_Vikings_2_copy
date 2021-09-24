#pragma once
#include "gameNode.h"
#include "object.h"

class player;

class objectManager : public gameNode
{
private:
	
	labber _labber[8];
	rope _rope[4];
	door _door;
	thorn _thorn[12];
	keyhome _keyhome;
	elevator _elevator[5];
	pushbotten _pushbotten[2];
	wall _wall;
	bottenground _bottenground;
	bottenbox _bottenbox;
	bealogaction _bealogaction[2];
	water _water;
	ground _ground[2];
	fire _fire[3];
	npc _npc;

	RECT temp;

	int _pushbottencheck;
	int presentelevator;
	bool opendoor;

public:

	bool clear;

	objectManager() {};
	~objectManager() {};
	HRESULT init();
	void update();
	void release();
	void render();
	int  labbercheck(player* player);
	int  ropecheck(player* player);
	int thorncheck(player* player);
	int  elevatorcheck(player* player);
	int  pushbottencheck(player* player);
	int bealogactioncheck(player* player);

	bool keyhomecheck(player* player);
	bool wallcheck(player* player);
	bool bottengroundcheck(player* player);
	bool bottenboxcheck(player* player);
	bool doorcheck(player* player);
	bool watercheck(player* player);
	bool firecheck(player* player);
	bool npccheck(player* player);

	wall getWall() { return _wall; }

	void setwall(player* player);
	void setelevtor(player* player);
	void setobject();
};

