#pragma once
#include "gameNode.h"
#include <vector>
class player;
class playerManager;

class pixelCollision : public gameNode
{

private:
	player* _player;
	float down ,up, left ,right; //¿ªÄ¡
	float downprobe , upprobe , rightprobe, leftprobe; //probe == Å½»ç

	int present;
	int character;
public:
	pixelCollision() {};
	~pixelCollision() {};
	virtual HRESULT init(int character);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void setLinkPlayer(player* player) { _player = player; }

	float leftcollision();
	float rightcollision();
	float downcollision();
	bool headcheck();
	bool leftcheck();
	bool rightcheck();
	bool groundcheck();
};

