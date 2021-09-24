#pragma once
#include "statepatten.h"
class smallolaf :public statepatten
{
private:
	int count, seen;
	int _character, present;
	bool _present;
	RECT _rc;
public:
	statepatten* handleInput(player* _player);
	void update(player* _player);
	void enter(player* _player, int character) ;
};

