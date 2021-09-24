#pragma once
#include "gameNode.h"
#include "statepatten.h"

class pixelCollision;
class objectManager;

class player : public gameNode
{
private:
	image *img;
	RECT rc;
	float x, y , up, down, left, right;
	int hp;
	int index , _character;
	bool present;
	statepatten* _state;

public:
	player() {};
	~player() {};
	image *gargolee, *gargoleebody1, *gargoleebody2, *gargoleebody3;
	int labber, rope, thorn, elevator, pushbotten, bealogaction;
	bool damage , bullet1, bullet2, _gargolee,wall, keyhome, door ,water ,fire , bottenbox;
	bool key , clear1, clear2 ,npc;
	float wall_x, wall_y;
	bool isRight , isTop , isSmall;
	RECT wallrc, elevatorrc, doorrc, bottenboxrc;
	RECT attack, bealogactionrc, bealogrc, gargoleebody1rc, gargoleebody2rc, gargoleebody3rc;

	pixelCollision* _pix;
	virtual HRESULT init(int character ,float x , float y);
	virtual void update();
	virtual void release();
	virtual void render(bool hudMode);
	virtual void handleInput();


	virtual int getindex() { return index; }
	virtual float getX() {return x; }
	virtual float getY() { return y; }
	virtual image* getimg() { return img; }
	virtual float gethp() { return hp; }
	virtual float getup() { return up; }
	virtual float getdown() { return down; }
	virtual float getleft() { return left; }
	virtual float getright() { return right; }
	virtual int getcharacter() { return _character; }
	virtual RECT getRECT() { return rc; }
	virtual bool getpresent() { return present; }


	
	virtual void setindex(int index) { this->index = index; }
	virtual void setimg(image* img) { this->img = img; }
	virtual void setX(float x) { this->x = x; }
	virtual void setY(float y) { this->y = y; }
	virtual void setRECT(RECT rc) {this->rc = rc; }
	virtual void sethp(int hp) { this->hp = hp; }
	virtual void setpresent(bool present) { this->present = present; }
	

	virtual void setLinkPixelcollsion(pixelCollision* pix) { _pix = pix; }
};

