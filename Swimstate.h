#pragma once
#include "statepatten.h"

class Swimstate : public statepatten
{
private:

	int count;
	int _character, present;
	bool _present;
	RECT _rc;

public:

	virtual statepatten* handleInput(player* _player);
	virtual void update(player* _player);
	virtual void enter(player* _player, int character);
};

