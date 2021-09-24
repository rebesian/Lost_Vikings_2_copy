#pragma once
#include "statepatten.h"
class gargolee :public statepatten
{
private:
	int count;
	float x, y;
	int _character, present;
	bool _present ,end;
	RECT _rc;

public:
	statepatten* handleInput(player* _player);
	void update(player* _player);
	void enter(player* _player, int character);
};

