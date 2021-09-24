#pragma once
#include "gameNode.h"
#include "player.h"
#include "imageManager.h"

class key;
class clearobject;

class HUD : public gameNode
{
private:

	image* _hud;
	image* _playerimg;
	image* _point;
	image *hp , *hp1, *hp2;

	image  *keyimg, *clear1img , *clear2img;

	player* _player;

	float _x, _y, pointX, pointY;
	bool present , isgetkey, isgetclear1 ,isgetclear2;
	bool _hudMode;

public:
	HUD() {};
	~HUD() {};

	HRESULT init(image* hud, float x, float y);
	void update(image* player);
	void release();
	void render();
	
	bool getpresent() { return present; }

	void setpresent(bool present) { this->present = present; }
	void sethudMode(bool hudMode) { _hudMode = hudMode; }
	void setLinkPlayer(player* player) { _player = player; }
};

