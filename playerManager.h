#pragma once
#include "gameNode.h"
#include "Bealog.h"
#include "Olaf.h"
#include "Erik.h"
#include <vector>

class pixelCollision;

class playerManager : public gameNode
{
private:
	typedef vector<player*>			  vPlayer;
	typedef vector<player*>::iterator viPlayer;
private:
	player* _erik;
	player* _bealog;
	player* _olaf;
	vPlayer _vPlayer;
	viPlayer _viPlayer;
	int present;
	int character;
public:
	playerManager() {};
	~playerManager() {};

	pixelCollision* _pix;
	pixelCollision* _pix1;
	pixelCollision* _pix2;
	HRESULT init();
	void release();
	void update();
	void render();


	void setErik();
	void setBealog();
	void setOlaf();
	virtual void setLinkPixelcollsion(pixelCollision* pix) { _pix = pix; }
	virtual void setLinkPixelcollsion1(pixelCollision* pix) { _pix1 = pix; }
	virtual void setLinkPixelcollsion2(pixelCollision* pix) { _pix2 = pix; }

	player* getErik() { return _erik; }
	player* getBealog() { return _bealog; }
	player* getOlaf() { return _olaf; }

	vPlayer getVPlayer() { return _vPlayer; }
	viPlayer getVIPlayer() { return _viPlayer;  }
	int getpresent() { return present; }
	int getcharacter() { return character; }
};

