#pragma once
#include "statepatten.h"

class idlestate :public statepatten
{
private:
	int count;
	int _character;
	bool _present;
	RECT _rc;
public:

	statepatten* handleInput(player* _player) ;
	void update(player* _player) ;
	void enter(player* _player, int character);
};

