#pragma once
#include "gameNode.h"
#include "pixelCollision.h"
#include "objectManager.h"
#include "object.h"
#include "HUD.h";
#include "Erik.h"
#include "Bealog.h"
#include "Olaf.h"
#include "pirate.h"
#include "cannonbullet.h"
#include "item.h"

class playGround : public gameNode
{
private:

	image* background;
	image* pixel;

	pixelCollision* _pix;
	pixelCollision* _pix1;
	pixelCollision* _pix2;

	objectManager* _object;

	door* door;

	player* _erik;
	player* _bealog;
	player* _olaf;

	pirate* _pirate;
	cannonbullet *_cannonbullet1, *_cannonbullet2;
	key* _key;
	clearobject1 *_clear1;
	clearobject2 *_clear2;
	HUD* _erikhud;
	HUD* _bealoghud;
	HUD* _olafhud;
	HUD* _trashhud;

	bool hudMode;

public:
	playGround();
	~playGround();

	int present;

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void imageset();
	void ErikCollision();
	void BealogCollision();
	void OlafCollision();

	void ErikPlay();
	void BealogPlay();
	void OlafPlay();
};

