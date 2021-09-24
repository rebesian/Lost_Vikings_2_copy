#pragma once
#include "stdafx.h"

class player;


class statepatten 
{
private:
	int count;
	int _character , present;
	bool _present;
	RECT _rc;
public:

	virtual statepatten* handleInput(player* _player) { return nullptr; }
	virtual void update(player* _player) {};
	virtual void enter(player* _player, int character) {};

};

